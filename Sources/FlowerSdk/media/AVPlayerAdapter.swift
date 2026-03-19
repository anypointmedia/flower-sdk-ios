import AVFoundation
import sdk_core

class AVPlayerAdapter: NSObject, MediaPlayerAdapter {
    private let logger = FLogging(tag: "AVPlayerAdapter").logger

    private var mediaPlayerHook: MediaPlayerHook
    private var adsManagerListener: FlowerAdsManagerListener

    /// AVPlayer에는 플레이리스트가 없으므로 큐를 어댑터에서 관리한다.
    private var queue: [PlayItem] = []
    private let queueLock = NSLock()

    private var currentPlayerItem: AVPlayerItem?

    private var player: AVPlayer {
        get throws {
            let player = mediaPlayerHook.getPlayer()

            guard let player = player as? AVPlayer else {
                throw Throwable(
                    message: MediaPlayerHookExceptionKt.formatMediaPlayerHookExceptionString(
                        expected: "AVPlayer",
                        received: player == nil ? "nil" : String(describing: type(of: player!))
                    )
                )
            }

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
        let player = try self.player
        if let asset = player.currentItem?.asset as? AVURLAsset {
            if case .loaded(let _duration) = asset.status(of: .duration) {
                let duration = CMTimeGetSeconds(_duration) * 1000
                let position = CMTimeGetSeconds(player.currentTime()) * 1000

                let finalPosition: Int64 = (position.isInfinite || position.isNaN) ? Int64(-1) : Int64(position)
                let finalDuration: Int64 = (duration.isInfinite || duration.isNaN) ? Int64(-1) : Int64(duration)

                return Media(
                    urlOrId: asset.url.absoluteString,
                    duration: finalDuration,
                    position: finalPosition,
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
        try player.rate != 0.0
    }

    func getVolume() throws -> Float {
        try player.volume
    }

    func getHeight() throws -> Int32 {
        Int32(try player.currentItem?.presentationSize.height ?? 0)
    }

    func pause() throws {
        try player.pause()
    }

    func stop() throws {
        let player = try self.player
        player.pause()
        player.replaceCurrentItem(with: nil)
        queueLock.lock()
        queue.removeAll()
        queueLock.unlock()
    }

    func resume() throws {
        try player.play()
    }

    func enqueuePlayItem(playItem: PlayItem) throws {
        queueLock.lock()
        defer {
            queueLock.unlock()
        }
        queue.append(playItem)
    }

    func removePlayItem(playItem: PlayItem) throws {
        queueLock.lock()
        defer {
            queueLock.unlock()
        }
        queue.removeAll {
            $0.url == playItem.url
        }
    }

    override func observeValue(forKeyPath keyPath: String?, of object: Any?, change: [NSKeyValueChangeKey: Any]?, context: UnsafeMutableRawPointer?) {
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
            @unknown default:
                if let playerItem = object as? AVPlayerItem, playerItem === currentPlayerItem {
                    playerItem.removeObserver(self, forKeyPath: #keyPath(AVPlayerItem.status))
//                    removeObservers(from: playerItem)
                    currentPlayerItem = nil
                    try? playNextItem()
                }
            }
        } else if keyPath == #keyPath(AVPlayer.rate) {
            // rate 변화 감지: 0 -> non-zero (재생 시작)
            if let newRate = change?[.newKey] as? NSNumber,
               let oldRate = change?[.oldKey] as? NSNumber {
                let newRateValue = newRate.doubleValue
                let oldRateValue = oldRate.doubleValue

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
        let next: PlayItem?
        queueLock.lock()
        next = queue.isEmpty ? nil : queue.removeFirst()
        queueLock.unlock()

        guard let playItem = next else {
            return
        }

        let player = try self.player
        let playerItem = AVPlayerItem(url: URL(string: playItem.url)!)

        Task {
            try? await playerItem.asset.load(.duration)
        }

        if let previous = currentPlayerItem {
            previous.removeObserver(self, forKeyPath: #keyPath(AVPlayerItem.status))
//            removeObservers(from: previous)
        }
        currentPlayerItem = playerItem
//        addObservers(to: playerItem)

        player.replaceCurrentItem(with: playerItem)

        player.play()
    }

//    private func addObservers(to item: AVPlayerItem) {
//        NotificationCenter.default.addObserver(self,
//                                               selector: #selector(playerItemPlaybackStalled(_:)),
//                                               name: .AVPlayerItemPlaybackStalled,
//                                               object: item)
//        NotificationCenter.default.addObserver(self,
//                                               selector: #selector(playerItemFailedToPlayToEndTime(_:)),
//                                               name: .AVPlayerItemFailedToPlayToEndTime,
//                                               object: item)
//    }
//
//    private func removeObservers(from item: AVPlayerItem) {
//        NotificationCenter.default.removeObserver(self, name: .AVPlayerItemPlaybackStalled, object: item)
//        NotificationCenter.default.removeObserver(self, name: .AVPlayerItemFailedToPlayToEndTime, object: item)
//    }
//
//    @objc func playerItemPlaybackStalled(_ notification: Notification) {
//        logger.warn {
//            "Playback Stalled: Restarting playback..."
//        }
//        try? resume()
//    }
//
//    @objc func playerItemFailedToPlayToEndTime(_ notification: Notification) {
//        if let error = notification.userInfo?[AVPlayerItemFailedToPlayToEndTimeErrorKey] as? Error {
//            logger.error {
//                "Failed to play to end time: \(error.localizedDescription). Attempting to restart..."
//            }
//        } else {
//            logger.error {
//                "Failed to play to end time. Attempting to restart..."
//            }
//        }
//
//        // 에러 발생 시 재시작 시도 (처음부터 다시 재생하거나, play() 호출)
//        // 여기서는 단순 play() 시도. 필요 시 seek(to: .zero) 등 추가 가능
//        try? resume()
//    }

    func seekToPosition(absoluteStartTimeMs: Double?, relativeStartTimeMs: Double?, offsetMs: Double?, windowDurationMs: Double?, periodIndex: Int32?) throws {
        guard let targetMs = relativeStartTimeMs ?? offsetMs ?? absoluteStartTimeMs else {
            return
        }
        let time = CMTime(seconds: targetMs / 1000, preferredTimescale: 600)
        try player.seek(to: time)
    }

    func getCurrentAbsoluteTime(isPrintDetails: Bool) -> Double {
        // currentDate() returns the date of the current playback position from EXT-X-PROGRAM-DATE-TIME
        guard let currentPlayer = try? self.player,
              let date = currentPlayer.currentItem?.currentDate()
        else {
            return -1
        }
        return date.timeIntervalSince1970 * 1000
    }

    func getPlayerType() -> String? {
        "AVPlayer"
    }

    func getPlayerVersion() -> String? {
        nil
    }
}

