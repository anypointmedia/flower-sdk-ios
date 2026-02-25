import Foundation

class RemoteLogger {
    static let shared = RemoteLogger()

    private var logServerURL: String?
    private var logQueue: [String] = []
    private let queue = DispatchQueue(label: "com.flowersdk.remotelogger", qos: .utility)
    private var timer: Timer?
    private let maxBatchSize = 5000
    private let flushInterval: TimeInterval = 1.0 // 1 second

    private init() {
    }

    func configure(serverURL: String) {
        self.logServerURL = "http://\(serverURL)/logs"
        startTimer()
    }

    func log(_ message: String) {
        queue.async { [weak self] in
            self?.logQueue.append(message)
        }
    }

    private func startTimer() {
        DispatchQueue.main.async { [weak self] in
            guard let self = self else {
                return
            }
            self.timer = Timer.scheduledTimer(withTimeInterval: self.flushInterval, repeats: true) { [weak self] _ in
                self?.flushLogs()
            }
        }
    }

    private func flushLogs() {
        queue.async { [weak self] in
            guard let self = self else {
                return
            }
            guard let urlString = self.logServerURL, !self.logQueue.isEmpty else {
                return
            }

            var logsToSend: [String] = []

            // Take up to 5000 logs at a time
            if self.logQueue.count > self.maxBatchSize {
                logsToSend = Array(self.logQueue.prefix(self.maxBatchSize))
                self.logQueue.removeFirst(self.maxBatchSize)
            } else {
                logsToSend = self.logQueue
                self.logQueue.removeAll()
            }

            guard !logsToSend.isEmpty else {
                return
            }

            // Join logs with newline
            let logContent = logsToSend.joined(separator: "\n")

            self.sendLogs(content: logContent, to: urlString)
        }
    }

    private func sendLogs(content: String, to urlString: String) {
        guard let url = URL(string: urlString) else {
            return
        }

        var request = URLRequest(url: url)
        request.httpMethod = "POST"
        request.setValue("text/plain", forHTTPHeaderField: "Content-Type")
        request.httpBody = content.data(using: .utf8)
        request.timeoutInterval = 30

        let task = URLSession.shared.dataTask(with: request) { _, _, _ in
            // Logging removed
        }
        task.resume()
    }

    func stop() {
        timer?.invalidate()
        timer = nil
        // Flush remaining logs
        queue.sync {
            if !logQueue.isEmpty {
                let logContent = logQueue.joined(separator: "\n")
                if let urlString = logServerURL {
                    sendLogs(content: logContent, to: urlString)
                }
                logQueue.removeAll()
            }
        }
    }
}
