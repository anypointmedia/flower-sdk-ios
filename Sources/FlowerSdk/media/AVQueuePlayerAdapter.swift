import AVFoundation
import sdk_core

class AVQueuePlayerAdapter: NSObject, MediaPlayerAdapter {
    private let logger = FLogging(tag: "AVQueuePlayerAdapter").logger

    private var mediaPlayerHook: MediaPlayerHook
    private var adsManagerListener: FlowerAdsManagerListener

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

    func getCurrentMedia() throws -> Media {
        let currentPlayer = try self.player

        if let asset = currentPlayer.currentItem?.asset as? AVURLAsset {
            if case .loaded(let _duration) = asset.status(of: .duration) {
                let duration = CMTimeGetSeconds(_duration) * 1000
                let position = CMTimeGetSeconds(currentPlayer.currentTime()) * 1000

                let finalPosition: Int64 = (position.isInfinite || position.isNaN) ? Int64(-1) : Int64(position)
                let finalDuration: Int64 = (duration.isInfinite || duration.isNaN) ? Int64(-1) : Int64(duration)

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
            duration: Int64(-1),
            position: Int64(-1),
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
        try self.player.pause()
        try self.player.removeAllItems()
    }

    func resume() throws {
        try self.player.play()
    }

    func enqueuePlayItem(playItem: PlayItem) throws {
        let playerItem = AVPlayerItem(url: URL(string: playItem.url)!)
        Task {
            try await playerItem.asset.load(.duration)
        }

        playerItem.addObserver(self, forKeyPath: #keyPath(AVPlayerItem.status), options: [.new], context: nil)

        let player = try self.player
        if let flowerPlayer = player as? FlowerAVPlayer {
            flowerPlayer.insertInternal(playerItem, after: nil)
        } else {
            player.insert(playerItem, after: nil)
        }
    }

    func removePlayItem(playItem: PlayItem) throws {
        let player = try self.player

        let items: [AVPlayerItem]
        if let flowerPlayer = player as? FlowerAVPlayer {
            items = flowerPlayer.itemsInternal()
        } else {
            items = player.items()
        }

        guard let playerItem = items.first(where: { item in
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
        player.remove(playerItem)
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
                    player.remove(playerItem)
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
        try self.player.advanceToNextItem()
    }

    func seekToPosition(absoluteStartTimeMs: Double?, relativeStartTimeMs: Double?, offsetMs: Double?, windowDurationMs: Double?, periodIndex: Int32?) throws {
        guard let targetMs = relativeStartTimeMs ?? offsetMs ?? absoluteStartTimeMs else {
            return
        }
        let time = CMTime(seconds: targetMs / 1000, preferredTimescale: 600)
        try self.player.seek(to: time)
    }

    func getCurrentAbsoluteTime(isPrintDetails: Bool) throws -> Double {
        // currentDate() returns the date of the current playback position from EXT-X-PROGRAM-DATE-TIME
        guard let currentPlayer = try? self.player,
              let date = currentPlayer.currentItem?.currentDate()
        else {
            return -1
        }
        return date.timeIntervalSince1970 * 1000
    }

    func getPlayerType() -> String? {
        "AVQueuePlayer"
    }

    func getPlayerVersion() -> String? {
        nil
    }
}

