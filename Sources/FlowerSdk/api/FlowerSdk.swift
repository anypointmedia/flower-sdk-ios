import Foundation
import SwiftUI
import core

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
                    core.SdkContainer.ClassName.mediaPlayerAdapter: NoopMediaPlayerAdapter(),
                ]),
                factories: PlatformMap(storage: [
                    core.SdkContainer.ClassName.manipulationServer: ManipulationServerImplFactory(),
                    core.SdkContainer.ClassName.vastParser: VastParserImplFactory(),
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

    static func setLogLevel(level: String) {
        // TODO: Implement
        /*
         SdkContainer.getInstance().setLogLevel(
             when (level) {
                 "Verbose" -> org.lighthousegames.logging.LogLevel.Verbose
                 "Debug" -> org.lighthousegames.logging.LogLevel.Debug
                 "Info" -> org.lighthousegames.logging.LogLevel.Info
                 "Warn" -> org.lighthousegames.logging.LogLevel.Warn
                 "Error" -> org.lighthousegames.logging.LogLevel.Error
                 "Off" -> org.lighthousegames.logging.LogLevel.Off
                 else -> throw IllegalArgumentException("unknown log level")
             }
         )
         */
    }
}
