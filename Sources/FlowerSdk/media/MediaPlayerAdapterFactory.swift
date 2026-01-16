import sdk_core
import AVFoundation
#if canImport(MobileVLCKit)
import MobileVLCKit
#endif

class MediaPlayerAdapterFactory: sdk_core.SdkContainerBeanFactory {
    private let logger = FLogging(tag: nil).logger

    func create(args: KotlinArray<AnyObject>) throws -> KotlinWrapped<AnyObject> {
        let mediaPlayerHook = args.get(index: 1) as! MediaPlayerHook
        let adsManagerListener = args.get(index: 2) as! FlowerAdsManagerListener
        let player = mediaPlayerHook.getPlayer()

        if let avplayer = player as? AVQueuePlayer {
            logger.info { "Using AVQueuePlayerAdapter" }
            return KotlinWrapped(value: AVQueuePlayerAdapter(mediaPlayerHook: mediaPlayerHook, adsManagerListener: adsManagerListener))
        }

        #if canImport(MobileVLCKit)
        if let vlcMediaListPlayer = player as? VLCMediaListPlayer {
            logger.info { "Using VLCMediaListPlayerAdapter" }
            return KotlinWrapped(value: VLCMediaListPlayerAdapter(mediaPlayerHook: mediaPlayerHook, adsManagerListener: adsManagerListener))
        }
        #endif

        throw Throwable(
            message: UnsupportedMediaPlayerExceptionKt.formatUnsupportedMediaPlayerExceptionString(
                players: [
                    "AVPlayer",
                    "VLCMediaListPlayer",
                ],
                received: player == nil ? "nil" : String(describing: type(of: player!))
            )
        )
    }
}
