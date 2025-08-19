import sdk_core
import AVFoundation

class MediaPlayerAdapterWrapperFactory: sdk_core.SdkContainerBeanFactory {
    func create(args: KotlinArray<AnyObject>) throws -> KotlinWrapped<AnyObject> {
        let mediaPlayerAdapter = args.get(index: 0) as! MediaPlayerAdapter

        return KotlinWrapped(value: MediaPlayerAdapterWrapper(platformMediaPlayerAdapter: mediaPlayerAdapter))
    }
}
