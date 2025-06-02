import sdk_core
import AVFoundation
#if canImport(MobileVLCKit)
import MobileVLCKit
#endif

class MediaPlayerAdapterFactory: sdk_core.SdkContainerBeanFactory {
    func create(args: KotlinArray<AnyObject>) throws -> KotlinWrapped<AnyObject> {
        let mediaPlayerHook = args.get(index: 0) as! MediaPlayerHook
        let flowerAdsManager = args.get(index: 1) as! FlowerAdsManagerImpl
        let player = mediaPlayerHook.getPlayer()

        if let avplayer = player as? AVQueuePlayer {
            return KotlinWrapped(value: AVQueuePlayerAdapter(mediaPlayerHook: mediaPlayerHook, flowerAdsManager: flowerAdsManager))
        }

        #if canImport(MobileVLCKit)
        if let vlcMediaListPlayer = player as? VLCMediaListPlayer {
            return KotlinWrapped(value: VLCMediaListPlayerAdapter(mediaPlayerHook: mediaPlayerHook, flowerAdsManager: flowerAdsManager))
        }
        #endif

        throw Throwable(
            message: UnsupportedMediaPlayerExceptionKt.formatUnsupportedMediaPlayerExceptionString(
                players: PlatformList(array: [
                    "AVPlayer",
                    "VLCMediaListPlayer",
                ]),
                received: player == nil ? "nil" : String(describing: type(of: player!))
            )
        )
    }
}
