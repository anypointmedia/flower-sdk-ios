import AVFoundation
import sdk_core

struct HLSManifestForParsing {
    struct HLSSegment {
        let duration: Double
        let url: String
    }

    let segments: [HLSSegment]
}

struct DASHManifestForParsing {
    let periodID: String
}

class AVQueuePlayerAdapter: NSObject, MediaPlayerAdapter {
    private var mediaPlayerHook: MediaPlayerHook
    private var flowerAdsManager: FlowerAdsManagerImpl

    private var player: AVQueuePlayer {
        get throws {
            let player = mediaPlayerHook.getPlayer()

            guard let player = player as? AVQueuePlayer else {
                throw MediaPlayerHookException(expected: "AVPlayer", actual: player == nil ? "nil" : String(describing: type(of: player!)))
            }

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

    func getCurrentMediaChunk() throws -> MediaChunkStub {
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

        throw KotlinException(message: "No media available")
}

    func isPlaying() throws -> KotlinWrapped<KotlinBoolean> {
        KotlinWrapped(value: KotlinBoolean(value: try player.rate != 0.0))
    }

    func getHeight_() throws -> KotlinWrapped<KotlinInt> {
        KotlinWrapped(value: KotlinInt(value: Int32(try player.currentItem?.presentationSize.height ?? 0)))
    }

    func getVolume() throws -> KotlinWrapped<KotlinFloat> {
        KotlinWrapped(value: KotlinFloat(value: try player.volume))
    }

    func pause_() throws {
        try player.pause()
    }

    func resume_() throws {
        try player.play()
    }

    func enqueue(mediaPlayerItem: MediaPlayerItem) throws {
        let playerItem = AVPlayerItem(url: URL(string: mediaPlayerItem.url)!)
        Task {
            try await playerItem.asset.load(.duration)
        }

        playerItem.addObserver(self, forKeyPath: #keyPath(AVPlayerItem.status), options: [.new], context: nil)
        try player.insert(playerItem, after: nil)
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
}
