import Foundation
import sdk_core

final class MessageCommunicatorImpl: NSObject, MessageCommunicator, URLSessionWebSocketDelegate {
    private let logger = FLogging(tag: "MessageCommunicatorImpl").logger

    private let queue = DispatchQueue(label: "tv.anypoint.flower.MessageCommunicator")
    private lazy var session: URLSession = {
        URLSession(configuration: .default, delegate: self, delegateQueue: nil)
    }()

    private var task: URLSessionWebSocketTask?
    private var listeners: [MessageListener] = []
    private var intentionallyClosed: Bool = false
    private var reconnectAttempts: Int = 0
    private var isReconnecting: Bool = false
    private var currentAccessKey: String?
    private var shortenedUrlValue: String?

    var shortenedUrl: String? {
        queue.sync { shortenedUrlValue }
    }

    private var flowerConfigService: FlowerConfigService {
        SdkContainer.companion.getInstance().flowerConfigService
    }

    func connect() {
        queue.async { [weak self] in
            guard let self = self else { return }
            self.intentionallyClosed = false
            if self.task != nil {
                self.logger.info { "Already connected or connecting, skip connect()" }
                return
            }
            self.doConnect()
        }
    }

    private func doConnect() {
        let token = flowerConfigService.flowerConfig.wsAccessToken
        var urlString = "\(MessageCommunicatorCompanion().resolveWsUrl())?token=\(token)"
        if let accessKey = currentAccessKey {
            urlString += "&accessKey=\(accessKey)"
        }

        guard let url = URL(string: urlString) else {
            logger.warn { "Invalid WebSocket URL: \(urlString)" }
            return
        }

        logger.info { "Connecting WebSocket: \(urlString)" }
        let newTask = session.webSocketTask(with: url)
        task = newTask
        newTask.resume()
        receiveLoop(on: newTask)
    }

    private func receiveLoop(on current: URLSessionWebSocketTask) {
        current.receive { [weak self] result in
            guard let self = self else { return }
            switch result {
            case .success(let message):
                switch message {
                case .string(let text):
                    self.handleIncoming(text)
                case .data(let data):
                    if let text = String(data: data, encoding: .utf8) {
                        self.handleIncoming(text)
                    }
                @unknown default:
                    break
                }
                self.queue.async {
                    if self.task === current {
                        self.receiveLoop(on: current)
                    }
                }
            case .failure(let error):
                self.logger.warn { "WebSocket receive failed: \(error.localizedDescription)" }
                self.queue.async {
                    if self.task === current {
                        self.task = nil
                        self.scheduleReconnect()
                    }
                }
            }
        }
    }

    func sendClickUrl(adId: String, url: String) -> Bool {
        return queue.sync { () -> Bool in
            guard let task = self.task else {
                self.logger.warn { "sendClickUrl() called but not connected. Dropping message." }
                return false
            }

            let payload: [String: Any] = [
                "type": MessageCommunicatorImpl.typeClickUrl,
                "adId": adId,
                "url": url,
            ]
            guard let data = try? JSONSerialization.data(withJSONObject: payload, options: []),
                  let text = String(data: data, encoding: .utf8) else {
                self.logger.warn { "Failed to serialize click.url payload" }
                return false
            }

            task.send(.string(text)) { [weak self] error in
                if let error = error {
                    self?.logger.warn { "sendClickUrl() failed: \(error.localizedDescription)" }
                }
            }
            return true
        }
    }

    func close() {
        queue.async { [weak self] in
            guard let self = self else { return }
            self.intentionallyClosed = true
            let current = self.task
            self.task = nil
            current?.cancel(with: .normalClosure, reason: "client closed".data(using: .utf8))
            self.currentAccessKey = nil
            self.shortenedUrlValue = nil
            self.clearMessageListeners()
        }
    }

    func addMessageListener(listener: MessageListener) {
        queue.async { [weak self] in
            self?.listeners.append(listener)
        }
    }

    func removeMessageListener(listener: MessageListener) {
        queue.async { [weak self] in
            guard let self = self else { return }
            self.listeners.removeAll { existing in
                (existing as AnyObject) === (listener as AnyObject)
            }
        }
    }

    func clearMessageListeners() {
        queue.async { [weak self] in
            self?.listeners.removeAll()
        }
    }

    private func handleIncoming(_ text: String) {
        guard let data = text.data(using: .utf8),
              let parsed = try? JSONSerialization.jsonObject(with: data, options: []),
              let obj = parsed as? [String: Any] else {
            logger.warn { "Failed to parse incoming message: \(text)" }
            return
        }

        let type = obj["type"] as? String ?? ""
        switch type {
        case MessageCommunicatorImpl.typeWelcome:
            guard let accessKey = (obj["accessKey"] as? String), !accessKey.isEmpty else {
                logger.warn { "welcome missing accessKey: \(text)" }
                return
            }
            let url = (obj["url"] as? String).flatMap { $0.isEmpty ? nil : $0 }
            queue.async { [weak self] in
                guard let self = self else { return }
                self.currentAccessKey = accessKey
                self.shortenedUrlValue = url
                self.logger.info { "Received welcome: accessKey captured for reconnect" }
            }
        case MessageCommunicatorImpl.typeClickEvent:
            guard let adId = (obj["adId"] as? String), !adId.isEmpty else {
                logger.warn { "click.event missing adId: \(text)" }
                return
            }
            queue.async { [weak self] in
                guard let self = self else { return }
                let snapshot = self.listeners
                for listener in snapshot {
                    listener.onClickEvent(adKey: adId)
                }
            }
        default:
            logger.warn { "Unknown server message type: \(text)" }
        }
    }

    private func scheduleReconnect() {
        if intentionallyClosed || isReconnecting { return }
        isReconnecting = true

        reconnectAttempts = min(reconnectAttempts + 1, MessageCommunicatorImpl.maxAttemptForBackoff)
        let delaySec = backoffDelaySec(attempt: reconnectAttempts)

        logger.info { "Scheduling reconnect in \(delaySec)s (attempt=\(self.reconnectAttempts))" }
        queue.asyncAfter(deadline: .now() + delaySec) { [weak self] in
            guard let self = self else { return }
            self.isReconnecting = false
            if self.intentionallyClosed { return }
            if self.task != nil { return }
            self.doConnect()
        }
    }

    private func backoffDelaySec(attempt: Int) -> TimeInterval {
        let base = MessageCommunicatorImpl.initialBackoffSec * pow(2.0, Double(max(attempt - 1, 0)))
        return min(base, MessageCommunicatorImpl.maxBackoffSec)
    }

    // MARK: - URLSessionWebSocketDelegate

    func urlSession(_ session: URLSession, webSocketTask: URLSessionWebSocketTask, didOpenWithProtocol protocolName: String?) {
        queue.async { [weak self] in
            self?.logger.info { "WebSocket opened" }
            self?.reconnectAttempts = 0
        }
    }

    func urlSession(_ session: URLSession, webSocketTask: URLSessionWebSocketTask, didCloseWith closeCode: URLSessionWebSocketTask.CloseCode, reason: Data?) {
        queue.async { [weak self] in
            guard let self = self else { return }
            self.logger.info { "WebSocket closed: code=\(closeCode.rawValue)" }
            if self.task === webSocketTask {
                self.task = nil
            }
            self.scheduleReconnect()
        }
    }

    private static let initialBackoffSec: TimeInterval = 1.0
    private static let maxBackoffSec: TimeInterval = 16.0
    private static let maxAttemptForBackoff: Int = 5

    private static let typeWelcome = "welcome"
    private static let typeClickEvent = "click.event"
    private static let typeClickUrl = "click.url"
}
