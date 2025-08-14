import sdk_core

class ManipulationProxyFactory: sdk_core.SdkContainerBeanFactory {
    func create(args: KotlinArray<AnyObject>) throws -> KotlinWrapped<AnyObject> {
        let adsManager = args.get(index: 0) as! FlowerAdsManagerImpl
        let mediaPlayerHook = args.get(index: 1) as! MediaPlayerHook?

        let manipulationProxy = ManipulationServerImpl()
        try manipulationProxy.doInit(flowerAdsManager: adsManager, mediaPlayerHook: mediaPlayerHook)

        return KotlinWrapped(value: manipulationProxy)
    }
}
