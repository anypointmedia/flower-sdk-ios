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

class AvPlayerAdapterFactory: sdk_core.SdkContainerBeanFactory {
    func create(args: KotlinArray<AnyObject>) -> Any? {
        return AvPlayerAdapter(
            mediaPlayerHook: args.get(index: 0) as! MediaPlayerHook,
            flowerAdsManager: args.get(index: 1) as! FlowerAdsManagerImpl
        )
    }
}

class AvPlayerAdapter: MediaPlayerAdapter {

    private var mediaPlayerHook: MediaPlayerHook!
    private var flowerAdsManager: FlowerAdsManagerImpl!

    init(mediaPlayerHook: MediaPlayerHook, flowerAdsManager: FlowerAdsManagerImpl) {
        self.mediaPlayerHook = mediaPlayerHook
        self.flowerAdsManager = flowerAdsManager
    }


    func getCurrentPosition() -> Int32 {
        if mediaPlayerHook.getPlayer() is AVPlayer {
            return Int32(CMTimeGetSeconds((mediaPlayerHook.getPlayer() as! AVPlayer).currentTime()) * 1000)
        }
        return 0
    }

    func getCurrentMediaChunk() -> MediaChunkStub {
        return MediaChunk(currentPosition: getCurrentPosition(), url: nil, periodId: nil)
    }

    func isPlaying() -> Bool {
        var player: AVPlayer {
            mediaPlayerHook.getPlayer() as! AVPlayer
        }
        return player.rate != 0.0
    }

    func getVolume() -> Float {
        var player: AVPlayer {
            mediaPlayerHook.getPlayer() as! AVPlayer
        }
        return player.volume
    }

    func getHeight() -> Int32 {
        var player: AVPlayer {
            mediaPlayerHook.getPlayer() as! AVPlayer
        }
        return Int32(player.currentItem?.presentationSize.height ?? 0)
    }

    func pause() {
        var player: AVPlayer {
            mediaPlayerHook.getPlayer() as! AVPlayer
        }
        player.pause()
    }

    func resume() {
        var player: AVPlayer {
            mediaPlayerHook.getPlayer() as! AVPlayer
        }
        player.play()
    }
}
