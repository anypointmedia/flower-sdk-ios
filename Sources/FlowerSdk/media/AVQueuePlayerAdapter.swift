import AVFoundation
import sdk_core

class AVQueuePlayerAdapter: NSObject, MediaPlayerAdapter {
    private let logger = FLogging(tag: "AVQueuePlayerAdapter").logger

    private var mediaPlayerHook: MediaPlayerHook
    private var adsManagerListener: FlowerAdsManagerListener

    /// Health monitoring + auto-recovery for the player received via the media player hook.
    /// Verbose logging is off by default (production-safe); fatal-stall recovery is always on.
    private var diagnostics: PlayerDiagnostics?

    private var player: AVQueuePlayer {
        get throws {
            let player = mediaPlayerHook.getPlayer()

            guard let player = player as? AVQueuePlayer else {
                throw Throwable(
                    message: MediaPlayerHookExceptionKt.formatMediaPlayerHookExceptionString(
                        expected: "AVQueuePlayer",
                        received: player == nil ? "nil" : String(describing: type(of: player!))
                    )
                )            }

            return player
        }
    }

    init(mediaPlayerHook: MediaPlayerHook, adsManagerListener: FlowerAdsManagerListener) {
        self.mediaPlayerHook = mediaPlayerHook
        self.adsManagerListener = adsManagerListener
        super.init()
        setupRateObserver()
        setupDiagnostics()
    }

    private func setupRateObserver() {
        do {
            let player = try self.player
            player.addObserver(self, forKeyPath: #keyPath(AVPlayer.rate), options: [.new, .old], context: nil)
        } catch {
            logger.error {
                "Failed to setup rate observer: \(error.localizedDescription)"
            }
        }
    }

    private func setupDiagnostics() {
        guard let player = try? self.player else { return }
        diagnostics = PlayerDiagnostics(player: player)
    }

    func getCurrentMedia() throws -> Media {
        let currentPlayer = try self.player

        if let asset = currentPlayer.currentItem?.asset as? AVURLAsset {
            if case .loaded(let _duration) = asset.status(of: .duration) {
                let duration = CMTimeGetSeconds(_duration) * 1000
                let position = CMTimeGetSeconds(currentPlayer.currentTime()) * 1000

                let finalPosition: Double = (position.isInfinite || position.isNaN) ? -1.0 : position
                let finalDuration: Double = (duration.isInfinite || duration.isNaN) ? -1.0 : duration

                return Media(
                    urlOrId: asset.url.absoluteString,
                    duration: finalDuration,
                    position: finalPosition
                )
            }

            Task {
                try await asset.load(.duration)
            }
        }

        return Media(
            urlOrId: "",
            duration: -1.0,
            position: -1.0,
            )
    }

    func isPlaying() throws -> Bool {
        try self.player.rate != 0.0
    }

    func getVolume() throws -> Float {
        try self.player.volume
    }

    func getHeight() throws -> Int32 {
        Int32(try self.player.currentItem?.presentationSize.height ?? 0)
    }

    func pause() throws {
        try self.player.pause()
    }

    func stop() throws {
        let player = try self.player
        player.pause()
        logQueueOperation("stop.removeAllItems", on: player) {
            player.flowerRemoveAllItems()
        }
    }

    func resume() throws {
        try self.player.play()
    }

    func enqueuePlayItem(playItem: PlayItem) throws {
        let playerItem = AVPlayerItem(url: URL(string: playItem.url)!)
        Task { @MainActor in
            try await playerItem.asset.load(.duration)
        }

        playerItem.addObserver(self, forKeyPath: #keyPath(AVPlayerItem.status), options: [.new], context: nil)

        let player = try self.player
        player.flowerInsert(playerItem, after: nil)
        logger.info { "enqueuePlayItem: queue=\(player.flowerItems().count), url=\(playItem.url)" }
    }

    func removePlayItem(playItem: PlayItem) throws {
        let player = try self.player

        guard let playerItem = player.flowerItems().last(where: { item in
            if let urlAsset = item.asset as? AVURLAsset {
                return urlAsset.url.absoluteString == playItem.url
            }
            return false
        }) else {
            logger.warn {
                "not matched playitem"
            }
            return
        }

        playerItem.removeObserver(self, forKeyPath: #keyPath(AVPlayerItem.status))
        logQueueOperation("removePlayItem url=\(playItem.url)", on: player) {
            player.flowerRemove(playerItem)
        }
    }

    override func observeValue(forKeyPath keyPath: String?, of object: Any?, change: [NSKeyValueChangeKey : Any]?, context: UnsafeMutableRawPointer?) {
        guard let player = try? self.player else {
            return
        }

        if keyPath == #keyPath(AVPlayerItem.status) {
            let status: AVPlayerItem.Status
            if let statusNumber = change?[.newKey] as? NSNumber {
                status = AVPlayerItem.Status(rawValue: statusNumber.intValue)!
            } else {
                status = .unknown
            }

            switch status {
            case .readyToPlay:
                break
            default:
                if let playerItem = object as? AVPlayerItem {
                    playerItem.removeObserver(self, forKeyPath: #keyPath(AVPlayerItem.status))
                    logQueueOperation("dropFailedItem", on: player) {
                        player.flowerRemove(playerItem)
                    }
                }
            }
        } else if keyPath == #keyPath(AVPlayer.rate) {
            // rate 변화 감지: 0 -> non-zero (재생 시작)
            if let newRate = change?[.newKey] as? NSNumber,
               let oldRate = change?[.oldKey] as? NSNumber {
                let newRateValue = newRate.doubleValue
                let oldRateValue = oldRate.doubleValue

                // 재생 시작 시 또는 재개 시 새 item의 status observer 추가
                if oldRateValue == 0 && newRateValue > 0 {
                    if let player = try? self.player {
                        player.currentItem?.addObserver(self, forKeyPath: #keyPath(AVPlayerItem.status), options: [.new], context: nil)
                    }
                } else if newRateValue > 0 {
                    if let player = try? self.player {
                        player.currentItem?.addObserver(self, forKeyPath: #keyPath(AVPlayerItem.status), options: [.new], context: nil)
                    }
                }
            }
        }
    }

    func playNextItem() throws {
        let player = try self.player

        // `flowerAdvanceToNextItem()`, never the public `advanceToNextItem()`: `FlowerAVPlayer`
        // marks the AVQueuePlayer queue API unavailable and overrides it with empty bodies, those
        // overrides are dispatched dynamically, and this adapter holds the player as an
        // `AVQueuePlayer` - so the public call reached the empty body and the skip did nothing.
        // Nothing else showed it: the beacon went out, the button was hidden, and the ad played
        // its full 30s. `effect=` on the line below is what says which of the two happened.
        logQueueOperation("playNextItem", on: player) {
            player.flowerAdvanceToNextItem()
        }
    }

    /// Runs one queue operation and records whether it actually changed the queue.
    ///
    /// Every queue call in this adapter goes through the host app's player, and the SDK ships two
    /// ways of supplying one: the app's own `AVQueuePlayer` (`adsManager` integration), or
    /// `FlowerAVPlayer`, which subclasses `AVQueuePlayer` and overrides the queue API with empty
    /// bodies so integrators cannot reorder a queue the SDK owns. Both arrive here as an
    /// `AVQueuePlayer`, so one line of code is two implementations at runtime and nothing at the
    /// call site says which one ran.
    ///
    /// `effect=none` on an operation that should have moved something is the whole defect,
    /// visible nowhere else: the beacons still go out, the skip button is still hidden, and the ad
    /// simply keeps playing. `flowerItems()` is used for the counts deliberately - it reads the
    /// real queue even on a `FlowerAVPlayer`, so it can observe an operation that did nothing.
    private func logQueueOperation(_ what: String, on player: AVQueuePlayer, _ body: () -> Void) {
        let beforeCount = player.flowerItems().count
        let beforeCurrent = Self.itemUrl(player.currentItem)
        body()
        let afterCount = player.flowerItems().count
        let afterCurrent = Self.itemUrl(player.currentItem)
        let changed = beforeCount != afterCount || beforeCurrent != afterCurrent
        logger.info {
            "\(what): player=\(type(of: player)) flowerPlayer=\(player is FlowerAVPlayer) "
            + "queue=\(beforeCount)→\(afterCount) effect=\(changed ? "applied" : "none") "
            + "current=\(beforeCurrent)→\(afterCurrent)"
        }
    }

    private static func itemUrl(_ item: AVPlayerItem?) -> String {
        guard let urlAsset = item?.asset as? AVURLAsset else {
            return "nil"
        }
        return urlAsset.url.absoluteString
    }

    func seekToPosition(absoluteStartTimeMs: Double?, relativeStartTimeMs: Double?, offsetMs: Double?, windowDurationMs: Double?, periodIndex: Int32?) throws {
        guard let targetMs = relativeStartTimeMs ?? offsetMs ?? absoluteStartTimeMs else {
            return
        }
        let time = CMTime(seconds: targetMs / 1000, preferredTimescale: 600)
        try self.player.seek(to: time)
    }

    // Caches the last valid PROGRAM-DATE-TIME (ms). currentDate() can momentarily return nil
    // while the player seeks/reloads right after an ad skip; returning -1 in that window makes
    // the SDK fall back to wall-clock time and flip its absolute-time clock space, tearing down
    // ad tracking for the next ad. Serving the last valid PDT keeps the value in PDT space.
    // Stays -1 only until the first valid reading (bootstrap).
    private var lastValidAbsoluteTimeMs: Double = -1

    func getCurrentAbsoluteTime(isPrintDetails: Bool) throws -> Double {
        // currentDate() returns the date of the current playback position from EXT-X-PROGRAM-DATE-TIME
        guard let currentPlayer = try? self.player,
              let date = currentPlayer.currentItem?.currentDate()
        else {
            return lastValidAbsoluteTimeMs
        }
        let absoluteTimeMs = date.timeIntervalSince1970 * 1000
        lastValidAbsoluteTimeMs = absoluteTimeMs
        return absoluteTimeMs
    }

    func getPlayerType() -> String? {
        "AVQueuePlayer"
    }

    func getPlayerVersion() -> String? {
        nil
    }
}

