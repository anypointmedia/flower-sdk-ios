import AVFoundation
import sdk_core

class AVQueuePlayerAdapter: NSObject, MediaPlayerAdapter {
    private var mediaPlayerHook: MediaPlayerHook
    private var flowerAdsManager: FlowerAdsManagerImpl

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

    init(mediaPlayerHook: MediaPlayerHook, flowerAdsManager: FlowerAdsManagerImpl) {
        self.mediaPlayerHook = mediaPlayerHook
        self.flowerAdsManager = flowerAdsManager
    }


    func getCurrentPosition() throws -> KotlinWrapped<KotlinInt> {
        KotlinWrapped(value: KotlinInt(value: Int32(CMTimeGetSeconds(try player.currentTime()) * 1000)))
    }

    func getCurrentMediaChunk() throws -> MediaChunk {
        MediaChunk(
            currentPosition: Int32(CMTimeGetSeconds(try player.currentTime()) * 1000),
            url: nil,
            periodId: nil
        )
    }

    func getCurrentMedia() throws -> Media {
        if let asset = try player.currentItem?.asset as? AVURLAsset {
            if case .loaded(let _duration) = asset.status(of: .duration) {
                let duration = CMTimeGetSeconds(_duration) * 1000
                let position = CMTimeGetSeconds(try player.currentTime()) * 1000

                return Media(
                    url:  asset.url.absoluteString,
                    duration: (duration.isInfinite || duration.isNaN) ? -1 : Int32(duration),
                    position: (position.isInfinite || position.isNaN) ? -1 : Int32(position)
                )
            }

            Task {
                try await asset.load(.duration)
            }
        }

        throw Throwable(message: "No media available")
}

    func isPlaying() throws -> KotlinWrapped<KotlinBoolean> {
        KotlinWrapped(value: KotlinBoolean(value: try player.rate != 0.0))
    }

    func getVolume() throws -> KotlinWrapped<KotlinFloat> {
        KotlinWrapped(value: KotlinFloat(value: try player.volume))
    }

    func getHeight_() throws -> KotlinWrapped<KotlinInt> {
        KotlinWrapped(value: KotlinInt(value: Int32(try player.currentItem?.presentationSize.height ?? 0)))
    }

    func pause_() throws {
        try player.pause()
    }

    func resume_() throws {
        try player.play()
    }

    func enqueuePlayItem(playItem: PlayItem) throws {
        let playerItem = AVPlayerItem(url: URL(string: playItem.url)!)
        Task {
            try await playerItem.asset.load(.duration)
        }

        playerItem.addObserver(self, forKeyPath: #keyPath(AVPlayerItem.status), options: [.new], context: nil)
        try player.insert(playerItem, after: nil)
    }

    func removePlayItem(playItem: PlayItem) throws {
        guard let playerItem = try player.items().first(where: { item in
            if let urlAsset = item.asset as? AVURLAsset {
                return urlAsset.url.absoluteString == playItem.url
            }
            return false
        }) else {
            throw Throwable(message: "No media available")
        }

        try player.remove(playerItem)
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
            case .readyToPlay: break
            @unknown default:
                if let playerItem = object as? AVPlayerItem {
                    player.remove(playerItem)
                }
            }
        }
    }

    func playNextItem() throws {
        try player.advanceToNextItem()
    }
}
