import Foundation
import sdk_core

class GooglePalManagerDummyImpl: GooglePalManager {
    private let logger = FLogging(tag: "GooglePalManagerDummyImpl").logger

    func loadNonce(transactionId: String, descriptionUrl: String?, playerType: String?, playerVersion: String?, windowHeight: KotlinInt?, windowWidth: KotlinInt?, callback: @escaping (String?) -> Void) {
        logger.debug { "loadNonce[\(transactionId)] dummy - returning nil" }
        callback(nil)
    }

    func sendPlaybackStart(transactionId: String) {
        logger.debug { "sendPlaybackStart[\(transactionId)] dummy - no-op" }
    }

    func sendPlaybackEnd(transactionId: String) {
        logger.debug { "sendPlaybackEnd[\(transactionId)] dummy - no-op" }
    }

    func sendAdClick(transactionId: String) {
        logger.debug { "sendAdClick[\(transactionId)] dummy - no-op" }
    }

    func sendAdError(transactionId: String, errorCode: Int32) {
        logger.debug { "sendAdError[\(transactionId)] dummy - no-op (errorCode: \(errorCode))" }
    }

    func release(transactionId: String) {
        logger.debug { "release[\(transactionId)] dummy - no-op" }
    }
}
