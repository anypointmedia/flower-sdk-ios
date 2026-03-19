import Foundation
import SwiftUI
import sdk_core

// Import from util group/folder
// Note: In Swift, files in the same target are visible to each other without import,
// but we moved them physically. Just ensure the project structure reflects this.
// No explicit import needed if they are in the same module.

public typealias FlowerAdsManagerListener = sdk_core.FlowerAdsManagerListener
public typealias MediaPlayerHook = sdk_core.MediaPlayerHook
public typealias FlowerError = sdk_core.FlowerError
public typealias AdInfo = sdk_core.AdInfo

class DefaultSdkLifecycleListener: SdkLifecycleListener {
    func onDestroyed() {
        // TODO("Not yet implemented")
    }

    func onInitialized() {
        // TODO("Not yet implemented")
    }
}

public class FlowerSdk {
    private static var logger = FLogging(tag: "FlowerSdk").logger

    public static var root: some View {
        VStack {}
    }

    public static func doInit() {
        let versionObj = FlowerSdkVersion()
        logger.info {
            "FlowerSdk.doInit()\n" +
            "version: \(versionObj.version)\n" +
            "head: \(versionObj.head)\n" +
            "dirty: \(versionObj.dirty)"
        }

        var DEFAULT_TIMEOUT: TimeInterval = 3_000

        var instances: [SdkContainer.ClassName: Any] = [
            sdk_core.SdkContainer.ClassName.deviceService: DeviceServiceImpl(),
            sdk_core.SdkContainer.ClassName.cacheService: CacheServiceImpl(),
        ]

        #if canImport(ProgrammaticAccessLibrary)
        instances[sdk_core.SdkContainer.ClassName.googlePalManager] = GooglePalManagerImpl()
        logger.info {
            "Google PAL SDK initialized"
        }
        #endif

        let lm: Void = sdk_core.LifecycleManager().doInit(
            listener: DefaultSdkLifecycleListener(),
            instances: PlatformMap(storage: instances),
                factories: PlatformMap(storage: [
                    sdk_core.SdkContainer.ClassName.mediaPlayerAdapterWrapper: MediaPlayerAdapterWrapperFactory(),
                    sdk_core.SdkContainer.ClassName.platformMediaPlayerAdapter: MediaPlayerAdapterFactory(),
                    sdk_core.SdkContainer.ClassName.platformFile: PlatformFileImplFactory(),
                    sdk_core.SdkContainer.ClassName.manipulationProxy: ManipulationProxyFactory(),
                    sdk_core.SdkContainer.ClassName.adPlayer: AdPlayerImplFactory(),
                ])
        )

    }

    static func getEnv() -> String {
        return sdk_core.SdkContainer.companion.getInstance().env
    }


    public static func setEnv(env: String) {
        logger.info {
            "FlowerSdk.setEnv(\n" +
            "- env: \(env)\n" +
            ")"
        }

        // Parse env string for remote logging support
        // Format: "local-log-192.168.0.1:9898" -> env: "local", logServer: "192.168.0.1:9898"
        var actualEnv = env
        var logServerURL: String? = nil

        if env.contains("-log-") {
            let components = env.components(separatedBy: "-log-")
            if components.count == 2 {
                actualEnv = components[0]
                logServerURL = components[1]
            }
        }

        switch actualEnv {
        case "local",
             "dev",
             "prod":
            sdk_core.SdkContainer.companion.getInstance().env = actualEnv
            break;
        default:
            // Throw an error if env is not one of "local", "dev", or "prod"
            fatalError("env must be one of local, dev, prod")
        }

        // Configure remote logger if log server URL is provided
        if let logServer = logServerURL {
            // Configure RemoteLogger
            RemoteLogger.shared.configure(serverURL: logServer)

            // Bridge Kotlin logs to RemoteLogger via the SDK's global listener API
            GlobalLogListener.shared.setListener(listener: LogListenerImpl())

            logger.info {
                "Remote logging enabled - sending logs to: http://\(logServer)"
            }
        } else {
            // Disable remote logging by clearing the listener
            GlobalLogListener.shared.setListener(listener: nil)
        }
    }

    public static func setLogLevel(level: String) {
        logger.info {
            "FlowerSdk.setLogLevel(\n" +
            "- level: \(level)\n" +
            ")"
        }

        let logLevels = SdkContainer.LogLevel.entries

        guard let logLevel = logLevels.first(where: { $0.name == level }) else {
            fatalError("log level must be one of \(logLevels.map { $0.name }.joined(separator: ", "))")
        }

        SdkContainer.companion.getInstance().setLogLevel(level: logLevel)
    }
    
    public static func getDeviceId() -> String {
        return SdkContainer.companion.getInstance().deviceService.getDeviceId() ?? ""
    }

    public static func setDeviceId(deviceId: String) {
        SdkContainer.companion.getInstance().deviceService.setDeviceId(deviceId: deviceId)
    }

    public static func ignoreSkip() {
        SdkContainer.companion.getInstance().ignoreSkip = true
    }

    public static func notifyPictureInPictureModeChanged(_ isInPictureInPictureMode: Bool) {
        SdkContainer.companion.getInstance().isInPictureInPictureMode = isInPictureInPictureMode
    }
}

