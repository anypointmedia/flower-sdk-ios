import sdk_core

class ManipulationProxyFactory: sdk_core.SdkContainerBeanFactory {
    func create(args: KotlinArray<AnyObject>) throws -> KotlinWrapped<AnyObject> {
        let adsManager = args.get(index: 0) as! FlowerAdsManagerImpl

        let manipulationProxy = ManipulationServerImpl()
        try manipulationProxy.doInit(flowerAdsManager: adsManager)

        return KotlinWrapped(value: manipulationProxy)
    }
}
