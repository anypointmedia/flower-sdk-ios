import sdk_core

class AdPlayerImplFactory: sdk_core.SdkContainerBeanFactory {
    func create(args: KotlinArray<AnyObject>) throws -> KotlinWrapped<AnyObject> {
        return KotlinWrapped(value: AdPlayerImpl())
    }
}
