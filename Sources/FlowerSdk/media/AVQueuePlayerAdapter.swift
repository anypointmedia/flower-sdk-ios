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

class AVQueuePlayerAdapter: MediaPlayerAdapter {
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
        let duration = CMTimeGetSeconds(try player.currentItem?.asset.duration ?? CMTime.zero) * 1000

        return Media(
            url: try player.currentItem?.asset as? AVURLAsset == nil ? "" : (player.currentItem?.asset as! AVURLAsset).url.absoluteString,
            duration: (duration.isInfinite || duration.isNaN) ? 0 : Int32(duration),
            position: Int32(CMTimeGetSeconds(try player.currentTime()) * 1000)
        )
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
        try player.insert(AVPlayerItem(url: URL(string: mediaPlayerItem.url)!), after: nil)
    }
}
