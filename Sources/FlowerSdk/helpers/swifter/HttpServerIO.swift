//
//  HttpServer.swift
//  Swifter
//
//  Copyright (c) 2014-2016 Damian Kołakowski. All rights reserved.
//

import Foundation
import Dispatch
import OSLog

public protocol HttpServerIODelegate: AnyObject {
    func socketConnectionReceived(_ socket: Socket)
}

open class HttpServerIO {

    public weak var delegate: HttpServerIODelegate?

    private var socket = Socket(socketFileDescriptor: -1)
    private var sockets = Set<Socket>()

    public enum HttpServerIOState: Int32 {
        case starting
        case running
        case stopping
        case stopped
    }

    private var stateValue: Int32 = HttpServerIOState.stopped.rawValue

    public private(set) var state: HttpServerIOState {
        get {
            return HttpServerIOState(rawValue: stateValue)!
        }
        set(state) {
            #if !os(Linux)
            OSAtomicCompareAndSwapInt(self.state.rawValue, state.rawValue, &stateValue)
            #else
            self.stateValue = state.rawValue
            #endif
        }
    }

    public var operating: Bool { return self.state == .running }

    /// String representation of the IPv4 address to receive requests from.
    /// It's only used when the server is started with `forceIPv4` option set to true.
    /// Otherwise, `listenAddressIPv6` will be used.
    public var listenAddressIPv4: String?

    /// String representation of the IPv6 address to receive requests from.
    /// It's only used when the server is started with `forceIPv4` option set to false.
    /// Otherwise, `listenAddressIPv4` will be used.
    public var listenAddressIPv6: String?

    private let queue = DispatchQueue(label: "swifter.httpserverio.clientsockets")

    public func port() throws -> Int {
        return Int(try socket.port())
    }

    public func isIPv4() throws -> Bool {
        return try socket.isIPv4()
    }

    deinit {
        stop()
    }

    @available(macOS 10.10, *)
    public func start(_ port: in_port_t = 8080, forceIPv4: Bool = false, priority: DispatchQoS.QoSClass = DispatchQoS.QoSClass.background) throws {
        guard !self.operating else { return }
        stop()
        self.state = .starting
        let address = forceIPv4 ? listenAddressIPv4 : listenAddressIPv6
        self.socket = try Socket.tcpSocketForListen(port, forceIPv4, SOMAXCONN, address)
        self.state = .running
        DispatchQueue.global(qos: priority).async { [weak self] in
            guard let strongSelf = self else { return }
            guard strongSelf.operating else { return }
            while let socket = try? strongSelf.socket.acceptClientSocket() {
                DispatchQueue.global(qos: priority).async { [weak self] in
                    guard let strongSelf = self else { return }
                    guard strongSelf.operating else { return }
                    strongSelf.queue.async {
                        strongSelf.sockets.insert(socket)
                    }

                    strongSelf.handleConnection(socket)

                    strongSelf.queue.async {
                        strongSelf.sockets.remove(socket)
                    }
                }
            }
            strongSelf.stop()
        }
    }

    public func stop() {
        guard self.operating else { return }
        self.state = .stopping
        // Shutdown connected peers because they can live in 'keep-alive' or 'websocket' loops.
        for socket in self.sockets {
            socket.close()
        }
        self.queue.sync {
            self.sockets.removeAll(keepingCapacity: true)
        }
        socket.close()
        self.state = .stopped
    }

    open func dispatch(_ request: HttpRequest) -> ([String: String], (HttpRequest) -> HttpResponse) {
        return ([:], { _ in HttpResponse.notFound })
    }

    private static func elapsedMs(since start: DispatchTime) -> Double {
        Double(DispatchTime.now().uptimeNanoseconds - start.uptimeNanoseconds) / 1_000_000
    }

    private func handleConnection(_ socket: Socket) {
        let parser = HttpParser()
        let connectionStart = DispatchTime.now()
        let peer = (try? socket.peername()) ?? "unknown"
        var requestsServed = 0
        while self.operating, let request = try? parser.readHttpRequest(socket) {
            let request = request
            request.address = try? socket.peername()
            let (params, handler) = self.dispatch(request)
            request.params = params

            var components = URLComponents()
            components.queryItems = request.queryParams.map { key, value in
                URLQueryItem(name: key, value: value)
            }
            let pathAndQuery = "\(request.path)\(components.percentEncodedQuery != nil ? "?\(components.percentEncodedQuery!)" : "")"

            let handlerStart = DispatchTime.now()
            let response = handler(request)
            let handlerMs = HttpServerIO.elapsedMs(since: handlerStart)

            var keepConnection = parser.supportsKeepAlive(request.headers)
            do {
                if self.operating {
                    keepConnection = try self.respond(socket, response: response, keepAlive: keepConnection, pathAndQuery: pathAndQuery, handlerMs: handlerMs)
                }
            } catch {
                // EPIPE/"Broken pipe" here means the client (AVPlayer) closed the
                // socket before we finished writing. During HLS playback this is
                // usually benign: variant/ABR switch, seek, or player teardown
                // causes AVPlayer to cancel an in-flight request it no longer needs.
                os_log(.info, log: .default, "Proxy client closed connection while sending: %{public}@ handlerMs=%.1f peer=%{public}@ error: %{public}@ (usually benign: variant-switch/seek/stop)", pathAndQuery, handlerMs, peer, String(describing: error))
            }
            requestsServed += 1
            if let session = response.socketSession() {
                delegate?.socketConnectionReceived(socket)
                session(socket)
                break
            }
            if !keepConnection { break }
        }
        let connMs = HttpServerIO.elapsedMs(since: connectionStart)
        let openSockets = self.queue.sync { self.sockets.count }
        os_log(.debug, log: .default, "Proxy connection ended: peer=%{public}@ requestsServed=%d durationMs=%.1f openSockets=%d", peer, requestsServed, connMs, openSockets)
        socket.close()
    }

    private final class InnerWriteContext: HttpResponseBodyWriter {

        let socket: Socket
        private(set) var bytesWritten = 0

        init(socket: Socket) {
            self.socket = socket
        }

        func write(_ file: String.File) throws {
            try socket.writeFile(file)
        }

        func write(_ data: [UInt8]) throws {
            try write(ArraySlice(data))
        }

        func write(_ data: ArraySlice<UInt8>) throws {
            try socket.writeUInt8(data)
            bytesWritten += data.count
        }

        func write(_ data: NSData) throws {
            try socket.writeData(data)
            bytesWritten += data.length
        }

        func write(_ data: Data) throws {
            try socket.writeData(data)
            bytesWritten += data.count
        }
    }

    private func respond(_ socket: Socket, response: HttpResponse, keepAlive: Bool, pathAndQuery: String, handlerMs: Double) throws -> Bool {
        guard self.operating else { return false }

        // Some web-socket clients (like Jetfire) expects to have header section in a single packet.
        // We can't promise that but make sure we invoke "write" only once for response header section.

        var responseHeader = String()

        responseHeader.append("HTTP/1.1 \(response.statusCode) \(response.reasonPhrase)\r\n")

        let content = response.content()

        if content.length >= 0 {
            responseHeader.append("Content-Length: \(content.length)\r\n")
        }

        if keepAlive && content.length != -1 {
            responseHeader.append("Connection: keep-alive\r\n")
        }

        for (name, value) in response.headers() {
            responseHeader.append("\(name): \(value)\r\n")
        }

        responseHeader.append("\r\n")

        let writeStart = DispatchTime.now()
        try socket.writeUTF8(responseHeader)

        var bodyBytes = 0
        if let writeClosure = content.write {
            let context = InnerWriteContext(socket: socket)
            try writeClosure(context)
            bodyBytes = context.bytesWritten
        }
        let writeMs = HttpServerIO.elapsedMs(since: writeStart)
        let willKeepAlive = keepAlive && content.length != -1

        // handlerMs: time spent producing the response (manipulation + origin fetch).
        // writeMs:   time spent writing the response to the AVPlayer socket.
        // Comparing the two pinpoints whether latency comes from manipulation or transport.
        os_log(.info, log: .default, "Proxy response sent: %{public}@ status=%d bodyBytes=%d handlerMs=%.1f writeMs=%.1f keepAlive=%d", pathAndQuery, response.statusCode, bodyBytes, handlerMs, writeMs, willKeepAlive ? 1 : 0)

        return willKeepAlive
    }
}
