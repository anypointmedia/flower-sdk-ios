import Foundation
import sdk_core

/**
 * Swift implementation of Kotlin LogListener interface.
 * Forwards logs from Kotlin FLogging to RemoteLogger.
 */
class LogListenerImpl: LogListener {
    // DateFormatter creation is expensive (it parses locale data on every init),
    // so a single instance is reused. DateFormatter is thread-safe for formatting.
    private static let dateFormatter: DateFormatter = {
        let formatter = DateFormatter()
        formatter.dateFormat = "MM-dd HH:mm:ss.SSS"
        formatter.locale = Locale(identifier: "en_US_POSIX")
        return formatter
    }()

    // The process identifier never changes for the lifetime of the app.
    private static let pid = ProcessInfo.processInfo.processIdentifier

    func onLog(tag: String, level: String, message: String) {
        let timestamp = LogListenerImpl.dateFormatter.string(from: Date())
        let tid = pthread_mach_thread_np(pthread_self())
        let levelChar = mapLevel(level)
        let formattedLog = "\(timestamp) \(LogListenerImpl.pid) \(tid) \(levelChar) \(tag): \(message)"
        RemoteLogger.shared.log(formattedLog)
    }

    private func mapLevel(_ level: String) -> String {
        switch level.uppercased() {
        case "VERBOSE": return "V"
        case "DEBUG": return "D"
        case "INFO": return "I"
        case "WARN", "WARNING": return "W"
        case "ERROR": return "E"
        case "ASSERT": return "A"
        default: return "I"
        }
    }
}
