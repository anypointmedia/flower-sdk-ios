#if canImport(ProgrammaticAccessLibrary)
import Foundation
import CryptoKit
import sdk_core
import ProgrammaticAccessLibrary

class GooglePalManagerImpl: GooglePalManager {
    private let logger = FLogging(tag: "GooglePalManagerImpl").logger
    private let settings: Settings
    private var nonceLoaders: [String: NonceLoader] = [:]
    private var nonceManagers: [String: NonceManager] = [:]
    // NonceLoader.delegate is weak, so the delegate must be retained here until it fires.
    private var nonceDelegates: [String: NonceLoaderCallbackDelegate] = [:]
    private var deviceService: DeviceService {
        SdkContainer.companion.getInstance().deviceService
    }

    init() {
        self.settings = Settings()
    }

    func loadNonce(transactionId: String, descriptionUrl: String?, playerType: String?, playerVersion: String?, windowHeight: KotlinInt?, windowWidth: KotlinInt?, callback: @escaping (String?) -> Void) {
        let nonceLoader = NonceLoader(settings: settings)
        nonceLoaders[transactionId] = nonceLoader

        let request = NonceRequest()
        if let descriptionUrl = descriptionUrl {
            request.descriptionURL = URL(string: descriptionUrl)
        }
        if let playerType = playerType {
            request.playerType = playerType
        }
        if let playerVersion = playerVersion {
            request.playerVersion = playerVersion
        }
        if let height = windowHeight?.int32Value, height > 0 {
            logger.debug { "windowHeight: \(height)" }
            request.videoPlayerHeight = UInt(height)
        }
        if let width = windowWidth?.int32Value, width > 0 {
            logger.debug { "windowWidth: \(width)" }
            request.videoPlayerWidth = UInt(width)
        }
        if let deviceId = deviceService.getDeviceId(), !deviceId.isEmpty {
            request.ppid = Self.sha256(deviceId)
        }
        request.sessionID = transactionId
        request.willAdAutoPlay = .on
        request.willAdPlayMuted = .off
        request.continuousPlayback = .on
        request.skippablesSupported = true

        let delegate = NonceLoaderCallbackDelegate(
            onLoaded: { [weak self] nonceManager in
                guard let self = self else {
                    callback(nil)
                    return
                }
                self.nonceManagers[transactionId] = nonceManager
                self.nonceDelegates.removeValue(forKey: transactionId)
                self.logger.debug { "loadNonce[\(transactionId)] success" }
                callback(nonceManager.nonce)
            },
            onFailed: { [weak self] error in
                guard let self = self else {
                    callback(nil)
                    return
                }
                self.nonceLoaders.removeValue(forKey: transactionId)
                self.nonceDelegates.removeValue(forKey: transactionId)
                self.logger.error { "loadNonce[\(transactionId)] failed: \(error)" }
                callback(nil)
            }
        )
        nonceDelegates[transactionId] = delegate
        nonceLoader.delegate = delegate
        nonceLoader.loadNonceManager(with: request)
    }

    func sendPlaybackStart(transactionId: String) {
        nonceManagers[transactionId]?.sendPlaybackStart()
        logger.debug { "sendPlaybackStart[\(transactionId)]" }
    }

    func sendPlaybackEnd(transactionId: String) {
        nonceManagers[transactionId]?.sendPlaybackEnd()
        logger.debug { "sendPlaybackEnd[\(transactionId)]" }
    }

    func sendAdClick(transactionId: String) {
        nonceManagers[transactionId]?.sendAdClick()
        logger.debug { "sendAdClick[\(transactionId)]" }
    }

    func sendAdError(transactionId: String, errorCode: Int32) {
        nonceManagers[transactionId]?.sendPlaybackEnd()
        logger.debug { "sendAdError[\(transactionId)] errorCode: \(errorCode)" }
    }

    func release(transactionId: String) {
        nonceLoaders.removeValue(forKey: transactionId)
        nonceManagers.removeValue(forKey: transactionId)
        nonceDelegates.removeValue(forKey: transactionId)
        logger.debug { "release[\(transactionId)]" }
    }

    private static func sha256(_ input: String) -> String {
        let digest = SHA256.hash(data: Data(input.utf8))
        return digest.map { String(format: "%02x", $0) }.joined()
    }
}

/// Bridges PAL's delegate-based `NonceLoader` API to a closure-based callback.
private final class NonceLoaderCallbackDelegate: NSObject, NonceLoaderDelegate {
    private let onLoaded: (NonceManager) -> Void
    private let onFailed: (Error) -> Void

    init(onLoaded: @escaping (NonceManager) -> Void, onFailed: @escaping (Error) -> Void) {
        self.onLoaded = onLoaded
        self.onFailed = onFailed
    }

    func nonceLoader(_ nonceLoader: NonceLoader, with request: NonceRequest, didLoad nonceManager: NonceManager) {
        onLoaded(nonceManager)
    }

    func nonceLoader(_ nonceLoader: NonceLoader, with request: NonceRequest, didFailWith error: any Error) {
        onFailed(error)
    }
}
#endif
