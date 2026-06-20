#if canImport(ProgrammaticAccessLibrary)
import Foundation
import CryptoKit
import sdk_core
import ProgrammaticAccessLibrary

class GooglePalManagerImpl: GooglePalManager {
    private let logger = FLogging(tag: "GooglePalManagerImpl").logger
    private let settings: PALSettings
    private var nonceLoaders: [String: PALNonceLoader] = [:]
    private var nonceManagers: [String: PALNonceManager] = [:]
    private var deviceService: DeviceService {
        SdkContainer.companion.getInstance().deviceService
    }

    init() {
        let settings = PALSettings()
        settings.allowStorage = true
        self.settings = settings
    }

    func loadNonce(transactionId: String, descriptionUrl: String?, playerType: String?, playerVersion: String?, windowHeight: KotlinInt?, windowWidth: KotlinInt?, callback: @escaping (String?) -> Void) {
        let nonceLoader = PALNonceLoader(settings: settings)
        nonceLoaders[transactionId] = nonceLoader

        let request = PALNonceRequest()
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
            request.videoPlayerHeight = height
        }
        if let width = windowWidth?.int32Value, width > 0 {
            logger.debug { "windowWidth: \(width)" }
            request.videoPlayerWidth = width
        }
        if let deviceId = deviceService.getDeviceId(), !deviceId.isEmpty {
            request.ppid = Self.sha256(deviceId)
        }
        request.sessionID = transactionId
        request.willAdAutoPlay = true
        request.willAdPlayMuted = false
        request.continuousPlayback = true
        request.skippablesSupported = true

        Task {
            do {
                let nonceManager = try await nonceLoader.loadNonceManager(with: request)
                nonceManagers[transactionId] = nonceManager
                let nonce = nonceManager.nonce
                logger.debug { "loadNonce[\(transactionId)] success" }
                callback(nonce)
            } catch {
                logger.error { "loadNonce[\(transactionId)] failed: \(error)" }
                nonceLoaders.removeValue(forKey: transactionId)
                callback(nil)
            }
        }
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
        logger.debug { "release[\(transactionId)]" }
    }

    private static func sha256(_ input: String) -> String {
        let digest = SHA256.hash(data: Data(input.utf8))
        return digest.map { String(format: "%02x", $0) }.joined()
    }
}
#endif
