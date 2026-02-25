import Foundation
import sdk_core

/**
 * Swift implementation of Kotlin LogListener interface.
 * Forwards logs from Kotlin FLogging to RemoteLogger.
 */
class LogListenerImpl: LogListener {
    func onLog(tag: String, level: String, message: String) {
        let timestamp = formatDate(Date())
        let pid = ProcessInfo.processInfo.processIdentifier
        let tid = pthread_mach_thread_np(pthread_self())
        let levelChar = mapLevel(level)
        let formattedLog = "\(timestamp) \(pid) \(tid) \(levelChar) \(tag): \(message)"
        RemoteLogger.shared.log(formattedLog)
    }

    private func formatDate(_ date: Date) -> String {
        let formatter = DateFormatter()
        formatter.dateFormat = "MM-dd HH:mm:ss.SSS"
        formatter.locale = Locale(identifier: "en_US_POSIX")
        return formatter.string(from: date)
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
