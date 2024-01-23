import Foundation
import SwiftUI
import core

public typealias FlowerAdsManagerListener = core.FlowerAdsManagerListener
public typealias MediaPlayerHook = core.MediaPlayerHook
public typealias FlowerError = core.FlowerError

class DefaultSdkLifecycleListener: SdkLifecycleListener {
    func onDestroyed() {
        // TODO("Not yet implemented")
    }

    func onInitialized() {
        // TODO("Not yet implemented")
    }
}

public class FlowerSdk {
    // TODO: Implement
//    private const val DEFAULT_TIMEOUT = 3_000

    public static func doInit(appContext: Any) {
        let lm: Void = core.LifecycleManager().doInit(
                listener: DefaultSdkLifecycleListener(),
                instances: PlatformMap(storage: [
                    // TODO Implement
//                    core.SdkContainer.ClassName.httpClient: "TODO",
                    core.SdkContainer.ClassName.cacheManager: CacheManagerImpl(appContext: appContext),
                    core.SdkContainer.ClassName.deviceService: DeviceServiceImpl(appContext: appContext),
                    core.SdkContainer.ClassName.mediaPlayerAdapter: AvPlayerAdapter(),
                    core.SdkContainer.ClassName.xmlUtil: XmlUtilImpl(),
                ]),
                factories: PlatformMap(storage: [
                    core.SdkContainer.ClassName.manipulationServer: ManipulationServerImplFactory(),
                ])
        )

    }

    // TODO: Implement
    static func getEnv() -> String {
        return "" // FlowerSdk.getEnv()
    }


    public static func setEnv(env: String) {
        switch env {
        case "local",
             "dev",
             "prod":
            break;
                // TODO: Implement
                // SdkContainer.getInstance().setEnvironment(env)
        default:
            // Throw an error if env is not one of "local", "dev", or "prod"
            fatalError("env must be one of local, dev, prod")
        }
    }

    public static func setLogLevel(level: String) {
        let logLevels = SdkContainer.LogLevel.entries

        guard let logLevel = logLevels.first(where: { $0.name == level }) else {
            fatalError("log level must be one of \(logLevels.map { $0.name }.joined(separator: ", "))")
        }

        SdkContainer.companion.getInstance().setLogLevel(level: logLevel)
    }
}
