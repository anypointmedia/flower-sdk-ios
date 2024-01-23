import Foundation
import core
import AVKit

class PlayerObserver: NSObject {
    var player: AVPlayer
    var callback: (_ player: AVPlayer, _ keyPath: String) -> Void

    init(player: AVPlayer, callback: @escaping (_ player: AVPlayer, _ keyPath: String) -> Void) {
        self.player = player
        self.callback = callback
        super.init()
        player.addObserver(self, forKeyPath: "rate", options: NSKeyValueObservingOptions.new, context: nil)
    }

    deinit {
        destroy()
    }

    override func observeValue(forKeyPath keyPath: String?, of object: Any?, change: [NSKeyValueChangeKey: Any]?, context: UnsafeMutableRawPointer?) {
        callback(player, keyPath!)
    }

    public func destroy() {
        player.removeObserver(self, forKeyPath: "rate")
    }
}

class ManipulationServerImplFactory: core.SdkContainerBeanFactory {
    func create(args: KotlinArray<AnyObject>) -> Any {
        return ManipulationServerImpl()
    }
}

class ManipulationServerImpl: ManipulationServer {
    private let sdkContainer = SdkContainer.Companion().getInstance()
    public let manipulationServerHandler = ManipulationServerHandler()
    private let server = HttpServer()
    private lazy var httpClient = sdkContainer.httpClient
    private var observer: PlayerObserver?
    var logger = core.LoggingKmLog()

    private var lastServerPort: in_port_t = 0

    func doInit(flowerAdsManager: FlowerAdsManagerImpl) {
        manipulationServerHandler.doInit(flowerAdsManager: flowerAdsManager)

        let freePort = findFreePort()
        startServer(address: "127.0.0.1", port: freePort)
        manipulationServerHandler.localEndpoint = "http://\(server.listenAddressIPv4!)\(freePort != nil ? ":\(freePort)" : "")"

        observer = PlayerObserver(player: flowerAdsManager.mediaPlayerHook.getPlayer() as! AVPlayer) { player, keyPath in
            if keyPath == "rate" {
                if player.status == .readyToPlay && player.rate > 0.0 {
                    self.checkServerAliveAndRestart()
                }
            }
        }
    }

    private func findFreePort() -> in_port_t {
        var port: in_port_t = 8080

        let socketFD = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)
        if socketFD == -1 {
            //print("Error creating socket: \(errno)")
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
            //print("Error getting address info: \(errno)")
            close(socketFD)

            return 0
        }

        result = Darwin.bind(socketFD, addressInfo!.pointee.ai_addr, socklen_t(addressInfo!.pointee.ai_addrlen))
        if result == -1 {
            //print("Error binding socket to an address: \(errno)")
            close(socketFD)

            return 0;
        }

        result = Darwin.listen(socketFD, 1)
        if result == -1 {
            //print("Error setting socket to listen: \(errno)")
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
        requestBuilder.ios_url(urlString: manipulationServerHandler.localEndpoint + "/ping")

        logger.verbose { "ping to server: \(self.manipulationServerHandler.localEndpoint)"}

        var response = try? httpClient.ios_requestSync(builder: requestBuilder)

        if (response == nil) {
            startServer(address: "127.0.0.1", port: lastServerPort)
        }
    }

    private func startServer(address: String, port: in_port_t) {
        server.listenAddressIPv4 = address

        do {
            try server.start(port, forceIPv4: true)
            lastServerPort = port
        } catch {
            print("Failed to run server.")
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

            var cachedResponse: CacheResponse!

            do {
                cachedResponse = try? manipulationServerHandler.ios_handleRequestSync(requestUri: requestUri, headers: request.headers)
            } catch {
                logger.warn { "failed to get cached response" }
                print(error)
                return HttpResponse.notFound
            }

            switch cachedResponse.statusCode {
            case Ktor_httpHttpStatusCode.Companion().OK:
                return HttpResponse.ok(.data((cachedResponse.data as! String).data(using: .utf8)!))
            default:
                if (cachedResponse.statusCode != Ktor_httpHttpStatusCode.Companion().ServiceUnavailable) {
//                    logger.warn("original response status code: \(cachedResponse.statusCode). Fallback to InternalServerError")
                }

                return HttpResponse.internalServerError
            }
        }
    }

    func stop() {
        observer?.destroy()
        server.stop()
    }
}

enum ManipulationType {
    case mpd
    case m3u8
    case other
}

class ResponsePlaylistCache {
    var playlistText: String
//    var headers: Ktor_httpHeaders
//    var contentType: String

    init(manipulatedPlayList: String/*, headers: Ktor_httpHeaders, contentType: String */) {
        self.playlistText = manipulatedPlayList
//        self.headers = headers
//        self.contentType = contentType
    }
}
