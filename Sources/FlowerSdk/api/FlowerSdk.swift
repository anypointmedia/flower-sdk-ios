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
public typealias FlowerAd = sdk_core.FlowerAd
public typealias FlowerCreative = sdk_core.FlowerCreative
public typealias ChannelAdRequest = sdk_core.ChannelAdRequest

class DefaultSdkLifecycleListener: SdkLifecycleListener {
    func onDestroyed() {
        // TODO("Not yet implemented")
    }

    func onInitialized() {
        // TODO("Not yet implemented")
    }
}

public class FlowerSdk {
    private nonisolated(unsafe) static let logger = FLogging(tag: "FlowerSdk").logger

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
            sdk_core.SdkContainer.ClassName.messageCommunicator: MessageCommunicatorImpl(),
        ]

        #if canImport(ProgrammaticAccessLibrary)
        instances[sdk_core.SdkContainer.ClassName.googlePalManager] = GooglePalManagerImpl()
        logger.info {
            "Google PAL SDK initialized"
        }
        #else
        instances[sdk_core.SdkContainer.ClassName.googlePalManager] = GooglePalManagerDummyImpl()
        logger.info {
            "Google PAL SDK not available - using dummy implementation"
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

        applyClientOverride()
    }

    /// Reads the tester's override from the app's Documents directory (`Documents/flower-override.json`),
    /// placed there through the simulator container, `xcrun devicectl`, or Finder file sharing.
    /// See e2e/docs/CLIENT_APP.md.
    ///
    /// Applied on every init, file or not, so an override from an earlier init in this process does
    /// not outlive its file.
    private static func applyClientOverride() {
        let fileName = sdk_core.ClientOverride.shared.FILE_NAME
        let file = FileManager.default.urls(for: .documentDirectory, in: .userDomainMask).first?
            .appendingPathComponent(fileName)

        var raw: String? = nil
        if let file = file, FileManager.default.fileExists(atPath: file.path) {
            raw = try? String(contentsOf: file, encoding: .utf8)
            if raw == nil {
                logger.warn { "failed to read client override: \(file.path)" }
            }
        }
        sdk_core.LifecycleManager().applyClientOverride(raw: raw, source: file?.path ?? fileName)
    }

    public static func getVersion() -> String {
        return FlowerSdkVersion().version
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

        switch env {
        case "local",
             "dev",
             "prod":
            // Through setEnvironment, as on Android/HTML5, so the env's log level applies here too.
            sdk_core.SdkContainer.companion.getInstance().setEnvironment(env: env)
            break;
        default:
            // Throw an error if env is not one of "local", "dev", or "prod"
            fatalError("env must be one of local, dev, prod")
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

    @available(*, deprecated, renamed: "notifyUserLeftApp(_:)", message: "Report the user leaving the app instead, whether or not the app enters PIP.")
    public static func notifyPictureInPictureModeChanged(_ isInPictureInPictureMode: Bool) {
        notifyUserLeftApp(isInPictureInPictureMode)
    }

    /// Tells the SDK the user left the app (`true`) - to the home screen, another app, or a PIP
    /// window - or came back to it (`false`). With `setIgnoreAdBreakInPIPMode(true)`, the default,
    /// an ad playing when the user leaves pauses until the user comes back, and VOD mid/post-rolls
    /// are not requested meanwhile. Report it whether or not the app enters PIP: while an ad plays,
    /// the app should not put the content player into PIP at all.
    public static func notifyUserLeftApp(_ hasLeftApp: Bool) {
        SdkContainer.companion.getInstance().isInPictureInPictureMode = hasLeftApp
    }

    public static func setIgnoreAdBreakInPIPMode(_ ignore: Bool) {
        SdkContainer.companion.getInstance().ignoreAdBreakInPIPMode = ignore
    }
}

