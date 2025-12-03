import Foundation
import sdk_core
import AVKit
import OSLog

class MSPlayerObserver: NSObject {
    var player: AVPlayer
    var callback: (_ player: AVPlayer, _ keyPath: String) -> Void

    init(player: AVPlayer, callback: @escaping (_ player: AVPlayer, _ keyPath: String) -> Void) {
        self.player = player
        self.callback = callback
        super.init()
        player.addObserver(self, forKeyPath: "rate", options: NSKeyValueObservingOptions.new, context: nil)
    }

    override func observeValue(forKeyPath keyPath: String?, of object: Any?, change: [NSKeyValueChangeKey: Any]?, context: UnsafeMutableRawPointer?) {
        callback(player, keyPath!)
    }

    public func destroy() {
        player.removeObserver(self, forKeyPath: "rate")
    }
}

class ManipulationServerImpl: ManipulationServer {
    private let server = HttpServer()
    private var observer: MSPlayerObserver?
    var logger = FLogging(tag: nil).logger

    private var lastServerPort: in_port_t = 0

    override func serve() throws -> String {
        let freePort = findFreePort()
        startServer(address: "127.0.0.1", port: freePort)

        if freePort == 0 {
            throw Throwable(message: "No free port available.")
        } else {
            if let player = mediaPlayerHook?.getPlayer() as? AVPlayer {
                observer = MSPlayerObserver(player: player) { player, keyPath in
                    if keyPath == "rate" {
                        if player.status == .readyToPlay && player.rate > 0.0 {
                            self.checkServerAliveAndRestart()
                        }
                    }
                }
            }

            return "http://\(server.listenAddressIPv4!):\(freePort)"
        }
    }

    private func findFreePort() -> in_port_t {
        var port: in_port_t = 8080

        let socketFD = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)
        if socketFD == -1 {
            logger.error{"Error creating socket"}
            return 0
        }

        var hints = addrinfo(
                ai_flags: AI_PASSIVE,
                ai_family: AF_INET,
                ai_socktype: SOCK_STREAM,
                ai_protocol: 0,
                ai_addrlen: 0,
                ai_canonname: nil,
                ai_addr: nil,
                ai_next: nil
        );

        var addressInfo: UnsafeMutablePointer<addrinfo>? = nil
        var result = getaddrinfo(nil, "0", &hints, &addressInfo)
        if result != 0 {
            logger.error{"Error getting address info \(addressInfo)"}
            close(socketFD)

            return 0
        }

        result = Darwin.bind(socketFD, addressInfo!.pointee.ai_addr, socklen_t(addressInfo!.pointee.ai_addrlen))
        if result == -1 {
            logger.error{"Error binding socket to an address"}
            close(socketFD)

            return 0;
        }

        result = Darwin.listen(socketFD, 1)
        if result == -1 {
            logger.error{"Error setting socket to listen"}
            close(socketFD)

            return 0;
        }

        var addr_in = sockaddr_in()
        addr_in.sin_len = UInt8(MemoryLayout.size(ofValue: addr_in))
        addr_in.sin_family = sa_family_t(AF_INET)

        var len = socklen_t(addr_in.sin_len)
        result = withUnsafeMutablePointer(to: &addr_in, {
            $0.withMemoryRebound(to: sockaddr.self, capacity: 1) {
                return Darwin.getsockname(socketFD, $0, &len)
            }
        });

        if result == 0 {
            port = addr_in.sin_port
        }

        Darwin.shutdown(socketFD, SHUT_RDWR)
        close(socketFD)

        return port
    }

    private func checkServerAliveAndRestart() {
        let requestBuilder = Ktor_client_coreHttpRequestBuilder()
        requestBuilder.ios_url(urlString: localEndpoint + "/ping")

        logger.verbose { "ping to server: \(self.localEndpoint)"}

        var response = try? httpClient.ios_requestSync(builder: requestBuilder)

        if (response == nil) {
            logger.info { "Proxy server healthcheck failed. Restarting server." }
            startServer(address: "127.0.0.1", port: lastServerPort)
        }
    }

    private func startServer(address: String, port: in_port_t) {
        server.listenAddressIPv4 = address

        do {
            try server.start(port, forceIPv4: true)
            lastServerPort = port
        } catch {
            logger.error {"Failed to run server \(error)"}
            print(error)
            return
        }

        server["/"] = { [self] request in
            if request.path == "/ping" {
                logger.verbose { "pong from server" }
                return HttpResponse.ok(.data("pong".data(using: .utf8)!))
            }

            let requestUri = request.path + (request.queryParams.count == 0 ? "" : "?" + request.queryParams.reduce("") { (result, param) in
                result + (result.isEmpty ? "" : "&") + param.0 + "=" + param.1
            })

            logger.verbose { "requestUri: \(server.listenAddressIPv4!):\(lastServerPort)\(requestUri)" }

            var response: ManipulationServerResponse

            do {
                response = try ios_handleRequestSync(requestUri: requestUri, requestHeaders: request.headers)
            } catch {
                logger.warn { "failed to get cached response \(error)" }
                print(error)
                return HttpResponse.notFound
            }

            return HttpResponse.raw(
                Int(response.statusCode.value),
                response.statusCode.description(),
                KtorExt_iosKt.HeadersToStringMap(headers: response.headers),
                { writer in
                    try writer.write(KtorExt_iosKt.ByteReadChannelToNSData(channel: response.data))
                }
            )
        }
    }

    override func stop_() throws {
        try super.stop_()
        observer?.destroy()
        observer = nil
        server.stop()
    }
}
