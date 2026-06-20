import AVFoundation
import sdk_core

/// Installs AVPlayer / AVPlayerItem health monitoring and (optionally) recovery.
///
/// Two concerns, independently switchable:
///
/// 1. **Fatal-failure detection + auto-recovery** (always on, cheap).
///    A live HLS stall surfaces as `AVPlayerItemFailedToPlayToEndTime`
///    (typically CoreMediaErrorDomain -12888 "Playlist File unchanged for longer
///    than 1.5 * target duration"). AVPlayer abandons the item permanently in this
///    state, so the only way to resume a live stream is to rebuild the item from the
///    same (proxy) URL and seek to the live edge. This costs one notification
///    observer per item, so it stays enabled even in production.
///
/// 2. **Verbose health logging** (off by default, opt-in for QA/debug).
///    Player `timeControlStatus`/`rate` transitions, buffer state, access/error log
///    dumps, and a periodic heartbeat. Useful to analyze a freeze purely from logs,
///    but it adds steady-state KVO + a 2s timer + high log volume, so it is gated
///    behind ``verboseLoggingEnabled`` to impose no cost in production.
///
/// The SDK attaches this automatically to the player it receives via the media
/// player hook, so integrators do not wire it up themselves.
public final class PlayerDiagnostics {
    /// Global opt-in for verbose health logging. Leave `false` in production; a QA
    /// build can flip it at launch to get the full diagnostic stream. Instances
    /// created without an explicit `verboseLogging` argument inherit this value.
    public static var verboseLoggingEnabled = false

    private let logger = FLogging(tag: "PlayerDiagnostics").logger

    private weak var player: AVPlayer?

    private var playerObservations: [NSKeyValueObservation] = []
    private var itemObservations: [NSKeyValueObservation] = []
    private var notificationTokens: [NSObjectProtocol] = []
    private var periodicObserver: Any?
    private weak var observedItem: AVPlayerItem?

    /// Heartbeat interval. 2s is frequent enough to catch the buffer draining
    /// to zero without flooding the log.
    private let heartbeatIntervalSec: Double = 2.0

    /// When `false` (production default) only fatal-failure detection + recovery run;
    /// the verbose health logging is skipped entirely.
    private let verboseLogging: Bool

    /// When `true`, rebuild the item and resume at the live edge on a fatal stall.
    private let autoRecover: Bool

    // MARK: Recovery state

    private var isRecovering = false
    private var recoveryAttempts = 0
    private var lastRecoveryTime: Date?
    /// Max consecutive recovery attempts before giving up (avoids a tight retry loop
    /// against a permanently-dead stream).
    private let maxRecoveryAttempts = 3
    /// If playback stayed healthy this long since the last recovery, the next failure
    /// is treated as a fresh incident and the attempt counter resets.
    private let recoveryAttemptResetInterval: TimeInterval = 60

    public init(
        player: AVPlayer,
        verboseLogging: Bool = PlayerDiagnostics.verboseLoggingEnabled,
        autoRecover: Bool = true
    ) {
        self.player = player
        self.verboseLogging = verboseLogging
        self.autoRecover = autoRecover
        observePlayer(player)
        attachItem(player.currentItem)
        if verboseLogging {
            startHeartbeat(player)
            logger.info { "PlayerDiagnostics started (verbose, autoRecover: \(autoRecover))" }
        }
    }

    deinit {
        stop()
    }

    public func stop() {
        detachItem()
        playerObservations.forEach { $0.invalidate() }
        playerObservations.removeAll()
        if let periodicObserver = periodicObserver {
            player?.removeTimeObserver(periodicObserver)
            self.periodicObserver = nil
        }
    }

    // MARK: - Player-level observation

    private func observePlayer(_ player: AVPlayer) {
        // Always observed: re-attach item-level observers when the current item changes,
        // so failure detection / recovery keeps following the live item.
        playerObservations.append(
            player.observe(\.currentItem, options: [.new]) { [weak self] player, _ in
                guard let self = self else { return }
                if self.verboseLogging {
                    self.logger.info { "player.currentItem changed -> \(self.describe(player.currentItem))" }
                }
                self.detachItem()
                self.attachItem(player.currentItem)
            }
        )

        guard verboseLogging else { return }

        playerObservations.append(
            player.observe(\.timeControlStatus, options: [.new, .old]) { [weak self] player, _ in
                guard let self = self else { return }
                self.logger.info {
                    "player.timeControlStatus -> \(self.timeControlStatusText(player.timeControlStatus))"
                    + ", reasonForWaiting: \(self.waitingReasonText(player.reasonForWaitingToPlay))"
                    + ", rate: \(player.rate)"
                    + self.itemStateSuffix(player.currentItem)
                }
            }
        )

        playerObservations.append(
            player.observe(\.rate, options: [.new, .old]) { [weak self] player, change in
                guard let self = self else { return }
                self.logger.info {
                    "player.rate \(change.oldValue ?? -1) -> \(change.newValue ?? -1)"
                    + ", timeControlStatus: \(self.timeControlStatusText(player.timeControlStatus))"
                }
            }
        )
    }

    // MARK: - Item-level observation

    private func attachItem(_ item: AVPlayerItem?) {
        guard let item = item else { return }
        observedItem = item

        // Always observed (cheap, rare): fatal failure that requires recovery.
        itemObservations.append(
            item.observe(\.status, options: [.new]) { [weak self] item, _ in
                guard let self = self else { return }
                switch item.status {
                case .failed:
                    self.logger.warn { "item.status -> failed, error: \(self.describe(item.error))" }
                    self.dumpErrorLog(item)
                    self.recoverFromPlaybackFailure(item.error)
                case .readyToPlay:
                    if self.verboseLogging { self.logger.info { "item.status -> readyToPlay" } }
                case .unknown:
                    if self.verboseLogging { self.logger.info { "item.status -> unknown" } }
                @unknown default:
                    if self.verboseLogging { self.logger.info { "item.status -> unknown(default)" } }
                }
            }
        )

        observeNotification(.AVPlayerItemFailedToPlayToEndTime, item) { [weak self] note in
            guard let self = self else { return }
            let error = note.userInfo?[AVPlayerItemFailedToPlayToEndTimeErrorKey] as? Error
            self.logger.warn { "AVPlayerItemFailedToPlayToEndTime, error: \(self.describe(error))" }
            self.dumpErrorLog(item)
            self.recoverFromPlaybackFailure(error)
        }

        guard verboseLogging else { return }

        itemObservations.append(
            item.observe(\.isPlaybackBufferEmpty, options: [.new]) { [weak self] item, _ in
                guard let self = self else { return }
                if item.isPlaybackBufferEmpty {
                    self.logger.warn { "item.isPlaybackBufferEmpty -> true (buffer drained)" + self.bufferSuffix(item) }
                } else {
                    self.logger.info { "item.isPlaybackBufferEmpty -> false" + self.bufferSuffix(item) }
                }
            }
        )

        itemObservations.append(
            item.observe(\.isPlaybackLikelyToKeepUp, options: [.new]) { [weak self] item, _ in
                guard let self = self else { return }
                self.logger.info {
                    "item.isPlaybackLikelyToKeepUp -> \(item.isPlaybackLikelyToKeepUp)" + self.bufferSuffix(item)
                }
            }
        )

        itemObservations.append(
            item.observe(\.isPlaybackBufferFull, options: [.new]) { [weak self] item, _ in
                guard let self = self else { return }
                self.logger.info { "item.isPlaybackBufferFull -> \(item.isPlaybackBufferFull)" }
            }
        )

        observeNotification(.AVPlayerItemPlaybackStalled, item) { [weak self] _ in
            guard let self = self else { return }
            self.logger.warn { "AVPlayerItemPlaybackStalled" + self.bufferSuffix(item) }
            self.dumpAccessLog(item)
        }

        observeNotification(.AVPlayerItemNewErrorLogEntry, item) { [weak self] _ in
            self?.dumpErrorLog(item)
        }

        observeNotification(.AVPlayerItemNewAccessLogEntry, item) { [weak self] _ in
            self?.dumpAccessLog(item)
        }

        observeNotification(.AVPlayerItemDidPlayToEndTime, item) { [weak self] _ in
            self?.logger.info { "AVPlayerItemDidPlayToEndTime" }
        }
    }

    private func detachItem() {
        itemObservations.forEach { $0.invalidate() }
        itemObservations.removeAll()
        notificationTokens.forEach { NotificationCenter.default.removeObserver($0) }
        notificationTokens.removeAll()
        observedItem = nil
    }

    private func observeNotification(
        _ name: Notification.Name,
        _ item: AVPlayerItem,
        handler: @escaping (Notification) -> Void
    ) {
        let token = NotificationCenter.default.addObserver(
            forName: name,
            object: item,
            queue: .main,
            using: handler
        )
        notificationTokens.append(token)
    }

    // MARK: - Recovery

    /// Recovers from a fatal live-playback stall by rebuilding the current item from the
    /// same (proxy) URL and seeking to the live edge. The proxy keeps serving a last-good
    /// playlist meanwhile, so the rebuilt item can resume once the origin edge advances.
    private func recoverFromPlaybackFailure(_ error: Error?) {
        guard autoRecover else { return }
        guard !isRecovering else {
            logger.debug { "PlayerDiagnostics: already recovering, ignoring" }
            return
        }
        guard let player = player,
              let url = (player.currentItem?.asset as? AVURLAsset)?.url else {
            logger.warn { "PlayerDiagnostics: no current item URL, cannot recover" }
            return
        }

        let now = Date()
        if let last = lastRecoveryTime, now.timeIntervalSince(last) > recoveryAttemptResetInterval {
            recoveryAttempts = 0
        }
        guard recoveryAttempts < maxRecoveryAttempts else {
            logger.warn { "PlayerDiagnostics: giving up recovery after \(self.recoveryAttempts) attempts - \(url.absoluteString)" }
            return
        }

        isRecovering = true
        recoveryAttempts += 1
        lastRecoveryTime = now
        logger.warn {
            "PlayerDiagnostics: recovering from fatal stall (attempt \(self.recoveryAttempts)/\(self.maxRecoveryAttempts)) "
            + "for \(url.absoluteString), error: \(error.map { String(describing: $0) } ?? "nil")"
        }

        // Rebuild from the same URL. Use the player-type-appropriate item swap; for
        // FlowerAVPlayer go through its recovery hook so the ad pipeline is not re-initialized.
        let newItem = AVPlayerItem(url: url)
        switch player {
        case let flowerPlayer as FlowerAVPlayer:
            flowerPlayer.replaceCurrentItemForRecovery(newItem)
        case let queuePlayer as AVQueuePlayer:
            queuePlayer.removeAllItems()
            queuePlayer.insert(newItem, after: nil)
        default:
            player.replaceCurrentItem(with: newItem)
        }
        player.seek(to: CMTime.positiveInfinity) { [weak self] _ in
            guard let self = self else { return }
            self.player?.play()
            self.isRecovering = false
            self.logger.info { "PlayerDiagnostics: recovery resumed at live edge" }
        }
    }

    // MARK: - Heartbeat

    private func startHeartbeat(_ player: AVPlayer) {
        let interval = CMTime(seconds: heartbeatIntervalSec, preferredTimescale: 600)
        periodicObserver = player.addPeriodicTimeObserver(forInterval: interval, queue: .main) { [weak self, weak player] time in
            guard let self = self, let player = player, let item = player.currentItem else { return }
            // Only emit when not steadily playing, to keep noise down while healthy.
            let healthy = player.timeControlStatus == .playing && item.isPlaybackLikelyToKeepUp
            let level = healthy ? "ok" : "WATCH"
            self.logger.verbose {
                "heartbeat[\(level)] t=\(self.seconds(time))"
                + ", timeControlStatus: \(self.timeControlStatusText(player.timeControlStatus))"
                + ", reasonForWaiting: \(self.waitingReasonText(player.reasonForWaitingToPlay))"
                + self.bufferSuffix(item)
            }
        }
    }

    // MARK: - Log dumps

    private func dumpAccessLog(_ item: AVPlayerItem) {
        guard let event = item.accessLog()?.events.last else {
            logger.info { "accessLog: <empty>" }
            return
        }
        logger.info {
            "accessLog.last -> observedBitrate: \(Int(event.observedBitrate))"
            + ", indicatedBitrate: \(Int(event.indicatedBitrate))"
            + ", switchBitrate: \(Int(event.switchBitrate))"
            + ", numberOfStalls: \(event.numberOfStalls)"
            + ", numberOfDroppedVideoFrames: \(event.numberOfDroppedVideoFrames)"
            + ", numberOfBytesTransferred: \(event.numberOfBytesTransferred)"
            + ", durationWatched: \(String(format: "%.2f", event.durationWatched))"
            + ", numberOfServerAddressChanges: \(event.numberOfServerAddressChanges)"
            + ", numberOfMediaRequests: \(event.numberOfMediaRequests)"
            + ", startupTime: \(String(format: "%.3f", event.startupTime))"
            + ", uri: \(event.uri ?? "nil")"
        }
    }

    private func dumpErrorLog(_ item: AVPlayerItem) {
        guard let event = item.errorLog()?.events.last else {
            logger.info { "errorLog: <empty>" }
            return
        }
        logger.warn {
            "errorLog.last -> errorStatusCode: \(event.errorStatusCode)"
            + ", errorDomain: \(event.errorDomain)"
            + ", errorComment: \(event.errorComment ?? "nil")"
            + ", uri: \(event.uri ?? "nil")"
            + ", serverAddress: \(event.serverAddress ?? "nil")"
        }
    }

    // MARK: - Formatting helpers

    private func itemStateSuffix(_ item: AVPlayerItem?) -> String {
        guard let item = item else { return ", item: nil" }
        return ", itemStatus: \(statusText(item.status))" + bufferSuffix(item)
    }

    private func bufferSuffix(_ item: AVPlayerItem) -> String {
        ", bufferedAhead: \(String(format: "%.2f", bufferedAhead(item)))s"
        + ", likelyToKeepUp: \(item.isPlaybackLikelyToKeepUp)"
        + ", bufferEmpty: \(item.isPlaybackBufferEmpty)"
    }

    private func bufferedAhead(_ item: AVPlayerItem) -> Double {
        let current = item.currentTime()
        for value in item.loadedTimeRanges {
            let range = value.timeRangeValue
            if range.containsTime(current) {
                let end = CMTimeAdd(range.start, range.duration)
                return CMTimeGetSeconds(end) - CMTimeGetSeconds(current)
            }
        }
        return 0
    }

    private func seconds(_ time: CMTime) -> String {
        let value = CMTimeGetSeconds(time)
        return (value.isNaN || value.isInfinite) ? "nan" : String(format: "%.2f", value)
    }

    private func describe(_ item: AVPlayerItem?) -> String {
        guard let item = item else { return "nil" }
        let uri = (item.asset as? AVURLAsset)?.url.absoluteString ?? "non-url-asset"
        return "status: \(statusText(item.status)), uri: \(uri)"
    }

    private func describe(_ error: Error?) -> String {
        guard let error = error else { return "nil" }
        let nsError = error as NSError
        let underlying = nsError.userInfo[NSUnderlyingErrorKey] as? NSError
        return "\(nsError.domain)(\(nsError.code)): \(nsError.localizedDescription)"
            + (underlying.map { " | underlying: \($0.domain)(\($0.code))" } ?? "")
    }

    private func statusText(_ status: AVPlayerItem.Status) -> String {
        switch status {
        case .unknown: return "unknown"
        case .readyToPlay: return "readyToPlay"
        case .failed: return "failed"
        @unknown default: return "unknown(default)"
        }
    }

    private func timeControlStatusText(_ status: AVPlayer.TimeControlStatus) -> String {
        switch status {
        case .paused: return "paused"
        case .waitingToPlayAtSpecifiedRate: return "waitingToPlayAtSpecifiedRate"
        case .playing: return "playing"
        @unknown default: return "unknown(default)"
        }
    }

    private func waitingReasonText(_ reason: AVPlayer.WaitingReason?) -> String {
        guard let reason = reason else { return "none" }
        switch reason {
        case .evaluatingBufferingRate: return "evaluatingBufferingRate"
        case .toMinimizeStalls: return "toMinimizeStalls"
        case .noItemToPlay: return "noItemToPlay"
        default: return reason.rawValue
        }
    }
}
