import sdk_core
import AVFoundation

class AdPlayerImplFactory: sdk_core.SdkContainerBeanFactory {
    private let logger = FLogging(tag: "AdPlayerImplFactory").logger

    func create(args: KotlinArray<AnyObject>) throws -> KotlinWrapped<AnyObject> {
        guard args.size >= 2 else {
            logger.info {
                "Using default AdPlayerImpl"
            }
            return KotlinWrapped(value: AdPlayerImpl())
        }

        let mediaPlayerHook = args.get(index: 1) as? MediaPlayerHook
        let player = mediaPlayerHook?.getPlayer()

        if let queuePlayer = player as? AVQueuePlayer {
            logger.info { "Using AdPlayerImpl (AVQueuePlayer)" }
            return KotlinWrapped(value: AdPlayerImpl(player: queuePlayer))
        }

        if let avPlayer = player as? AVPlayer {
            logger.info { "Using AdAvPlayerImpl (AVPlayer)" }
            return KotlinWrapped(value: AdAvPlayerImpl(player: avPlayer))
        }

        // Default: create internal AVQueuePlayer
        logger.info { "Using default AdPlayerImpl" }
        return KotlinWrapped(value: AdPlayerImpl())
    }
}
