import sdk_core
import AVFoundation
#if canImport(MobileVLCKit)
import MobileVLCKit
#endif

class MediaPlayerAdapterFactory: sdk_core.SdkContainerBeanFactory {
    func create(args: KotlinArray<AnyObject>) throws -> KotlinWrapped<AnyObject> {
        let mediaPlayerHook = args.get(index: 0) as! MediaPlayerHook
        let flowerAdsManager = args.get(index: 1) as! FlowerAdsManagerImpl

        if let avplayer = mediaPlayerHook.getPlayer() as? AVQueuePlayer {
            return KotlinWrapped(value: AVQueuePlayerAdapter(mediaPlayerHook: mediaPlayerHook, flowerAdsManager: flowerAdsManager))
        }

        #if canImport(MobileVLCKit)
        if let vlcMediaPlayer = mediaPlayerHook.getPlayer() as? VLCMediaPlayer {
            return KotlinWrapped(value: VLCPlayerAdapter(mediaPlayerHook: mediaPlayerHook, flowerAdsManager: flowerAdsManager))
        }

        if let vlcMediaListPlayer = mediaPlayerHook.getPlayer() as? VLCMediaListPlayer {
            return KotlinWrapped(value: VLCPlayerAdapter(mediaPlayerHook: mediaPlayerHook, flowerAdsManager: flowerAdsManager))
        }
        #endif

        throw UnsupportedPlayerException()
    }
}

class UnsupportedPlayerException : KotlinException {
    init() {
        super.init(
            message: """
                Not Supported Player.
                Supported Players are:
                - AVPlayer
                - VLCMediaPlayer
                - VLCMediaListPlayer
                """
        )
    }

    required init(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
}
