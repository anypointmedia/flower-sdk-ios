#if canImport(ProgrammaticAccessLibrary)
import Foundation
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

    func loadNonce(transactionId: String, descriptionUrl: String?, playerType: String?, playerVersion: String?, callback: @escaping (String?) -> Void) {
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
        request.ppid = deviceService.getDeviceId() ?? ""
        request.sessionID = transactionId
        request.willAdAutoPlay = true
        request.willAdPlayMuted = false
        request.continuousPlayback = true

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
}
#endif
