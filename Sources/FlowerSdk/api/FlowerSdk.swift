import Foundation
import SwiftUI
import sdk_core

public typealias FlowerAdsManagerListener = sdk_core.FlowerAdsManagerListener
public typealias MediaPlayerHook = sdk_core.MediaPlayerHook
public typealias MediaPlayerAdapter = sdk_core.MediaPlayerAdapter
public typealias MediaChunkStub = sdk_core.MediaChunkStub
public typealias FlowerError = sdk_core.FlowerError
public typealias Media = sdk_core.Media
public typealias MediaPlayerItem = sdk_core.MediaPlayerItem

public class MediaChunk: MediaChunkStub {
    public var currentPosition: Int32

    public var url: String?

    public var periodId: String?

    public init(currentPosition: Int32, url: String?, periodId: String?) {
        self.currentPosition = currentPosition
        self.url = url
        self.periodId = periodId
    }
}

class DefaultSdkLifecycleListener: SdkLifecycleListener {
    func onDestroyed() {
        // TODO("Not yet implemented")
    }

    func onInitialized() {
        // TODO("Not yet implemented")
    }
}

public class FlowerSdk {
    private static var fingerPrintResolverViewModel = FingerPrintResolverViewModel()

    public static var root: some View {
        FingerPrintResolver(viewModel: fingerPrintResolverViewModel)
    }

    public static func doInit() {
        var DEFAULT_TIMEOUT: TimeInterval = 3_000

        let lm: Void = sdk_core.LifecycleManager().doInit(
                listener: DefaultSdkLifecycleListener(),
                instances: PlatformMap(storage: [
                    // Note: Let kmp core handle creating HttpClient[io.ktor.client.engine.darwin.DarwinClientEngine
                    // Thus, do not add instance sdk_core.SdkContainer.ClassName.httpClient: ,
                    sdk_core.SdkContainer.ClassName.deviceService: DeviceServiceImpl(fingerPrintResolverViewModel: fingerPrintResolverViewModel),
                    sdk_core.SdkContainer.ClassName.xmlUtil: XmlUtilImpl(),
                    sdk_core.SdkContainer.ClassName.adPlayer: FlowerAdPlayerImpl(),
                    sdk_core.SdkContainer.ClassName.platformAnalyticsResolver: PlatformAnalyticsResolverImpl(),
                    sdk_core.SdkContainer.ClassName.manipulationProxy: ManipulationServerImpl(),
                    sdk_core.SdkContainer.ClassName.cacheService: CacheServiceImpl(),
                ]),
                factories: PlatformMap(storage: [
                    sdk_core.SdkContainer.ClassName.mediaPlayerAdapter: MediaPlayerAdapterFactory(),
                    sdk_core.SdkContainer.ClassName.platformFile: PlatformFileImplFactory(),
                ])
        )

    }

    static func getEnv() -> String {
        return sdk_core.SdkContainer.companion.getInstance().env
    }


    public static func setEnv(env: String) {
        switch env {
        case "local",
             "dev",
             "prod":
            sdk_core.SdkContainer.companion.getInstance().env = env
            break;
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

    public static func setPrecacheAdChunk(precacheAdChunk: Bool) {
        sdk_core.SdkContainer.companion
            .getInstance().flowerConfigService
            .saveEphemeralStartupConfig(block: { startupConfig in
                startupConfig
                    .doCopy(
                        version: startupConfig.version,
                        maxCacheStorage: startupConfig.maxCacheStorage,
                        minFreeStorage: startupConfig.minFreeStorage,
                        precacheAdChunk: precacheAdChunk,
                        useCachedAdsOnly: startupConfig.useCachedAdsOnly
                    )
            })
    }

    public static func setUseCachedAdsOnly(useCachedAdsOnly: Bool) {
        sdk_core.SdkContainer.companion
            .getInstance().flowerConfigService
            .saveEphemeralStartupConfig(block: { startupConfig in
                startupConfig
                    .doCopy(
                        version: startupConfig.version,
                        maxCacheStorage: startupConfig.maxCacheStorage,
                        minFreeStorage: startupConfig.minFreeStorage,
                        precacheAdChunk: startupConfig.precacheAdChunk,
                        useCachedAdsOnly: useCachedAdsOnly
                    )
            })
    }
}
