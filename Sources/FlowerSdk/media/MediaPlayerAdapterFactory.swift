import sdk_core
import AVFoundation

/// Builds an adapter for the players the SDK ships support for.
///
/// Any other player is the host app's responsibility: implement `MediaPlayerAdapter` there and pass
/// the instance to `FlowerAdsManager.changeChannelUrl(..., mediaPlayerAdapter:, ...)` instead of a
/// `MediaPlayerHook`. The MobileVLCKitLinearTv example does exactly that for MobileVLCKit.
class MediaPlayerAdapterFactory: sdk_core.SdkContainerBeanFactory {
    private let logger = FLogging(tag: "MediaPlayerAdapterFactory").logger

    func create(args: KotlinArray<AnyObject>) throws -> KotlinWrapped<AnyObject> {
        let mediaPlayerHook = args.get(index: 1) as! MediaPlayerHook
        let adsManagerListener = args.get(index: 2) as! FlowerAdsManagerListener
        let player = mediaPlayerHook.getPlayer()

        if let avQueuePlayer = player as? AVQueuePlayer {
            logger.info { "Using AVQueuePlayerAdapter" }
            return KotlinWrapped(value: AVQueuePlayerAdapter(mediaPlayerHook: mediaPlayerHook, adsManagerListener: adsManagerListener))
        }

        if player is AVPlayer {
            logger.info {
                "Using AVPlayerAdapter"
            }
            return KotlinWrapped(value: AVPlayerAdapter(mediaPlayerHook: mediaPlayerHook, adsManagerListener: adsManagerListener))
        }

        throw Throwable(
            message: UnsupportedMediaPlayerExceptionKt.formatUnsupportedMediaPlayerExceptionString(
                players: [
                    "AVQueuePlayer",
                    "AVPlayer",
                ],
                received: player == nil ? "nil" : String(describing: type(of: player!))
            )
        )
    }
}
