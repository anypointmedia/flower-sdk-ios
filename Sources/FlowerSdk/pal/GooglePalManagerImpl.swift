#if canImport(ProgrammaticAccessLibrary)
import Foundation
import CryptoKit
import sdk_core
import ProgrammaticAccessLibrary

/// Carries a value into a `@MainActor` closure that Swift 6 cannot prove `Sendable` on its own.
/// Every value boxed here is handed to exactly one consumer, on one thread, exactly once.
private struct UncheckedSendable<T>: @unchecked Sendable {
    let value: T
}

private extension NSLock {
    // NSLocking.withLock is iOS 16+; this target still ships iOS 15.
    func sync<T>(_ body: () throws -> T) rethrows -> T {
        lock()
        defer { unlock() }
        return try body()
    }
}

/// Every entry point below is reached from a different thread: `loadNonce` runs on Kotlin's
/// `Dispatchers.IO` workers (the two wrapper ads of one break request their nonce concurrently),
/// `send*`/`release` run on AdTracker's dispatchers, and the PAL delegate fires on the SDK's own
/// callback thread. A Swift Dictionary is copy-on-write and not thread safe, so an unsynchronised
/// resize racing a read frees the buffer the reader still points at - EXC_BAD_ACCESS, which no
/// `catch` on either side of the Kotlin bridge can intercept. Hence `lock` around every registry
/// access, and `@unchecked Sendable` to declare that the mutable state is guarded.
class GooglePalManagerImpl: GooglePalManager, @unchecked Sendable {
    private let logger = FLogging(tag: "GooglePalManagerImpl").logger
    private let settings: Settings
    private let lock = NSLock()
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
        // Unwrap the ObjC-backed KotlinInt and resolve the ppid here, off the main thread: only
        // plain values and the boxed callback should cross into the hop below.
        let height = windowHeight?.int32Value
        let width = windowWidth?.int32Value
        let ppid = deviceService.getDeviceId().flatMap { $0.isEmpty ? nil : Self.sha256($0) }
        let boxedCallback = UncheckedSendable(value: callback)

        // PAL gathers its signals from UIKit, so the loader is built and started on the main
        // thread instead of on whichever Kotlin worker happened to call in.
        onMainAsync { [self] in
            let callback = boxedCallback.value
            let nonceLoader = NonceLoader(settings: settings)

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
            if let height = height, height > 0 {
                logger.debug { "windowHeight: \(height)" }
                request.videoPlayerHeight = UInt(height)
            }
            if let width = width, width > 0 {
                logger.debug { "windowWidth: \(width)" }
                request.videoPlayerWidth = UInt(width)
            }
            if let ppid = ppid {
                request.ppid = ppid
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
                    // `nonceDelegates` holds the only strong reference to the delegate this
                    // closure belongs to, so keep it alive until the callback has returned.
                    let firedDelegate = self.lock.sync { () -> NonceLoaderCallbackDelegate? in
                        self.nonceManagers[transactionId] = nonceManager
                        return self.nonceDelegates.removeValue(forKey: transactionId)
                    }
                    withExtendedLifetime(firedDelegate) {
                        self.logger.debug { "loadNonce[\(transactionId)] success" }
                        callback(nonceManager.nonce)
                    }
                },
                onFailed: { [weak self] error in
                    guard let self = self else {
                        callback(nil)
                        return
                    }
                    let firedDelegate = self.lock.sync { () -> NonceLoaderCallbackDelegate? in
                        self.nonceLoaders.removeValue(forKey: transactionId)
                        return self.nonceDelegates.removeValue(forKey: transactionId)
                    }
                    withExtendedLifetime(firedDelegate) {
                        self.logger.error { "loadNonce[\(transactionId)] failed: \(error)" }
                        callback(nil)
                    }
                }
            )
            lock.sync {
                nonceLoaders[transactionId] = nonceLoader
                nonceDelegates[transactionId] = delegate
            }
            nonceLoader.delegate = delegate
            nonceLoader.loadNonceManager(with: request)
        }
    }

    func sendPlaybackStart(transactionId: String) {
        onMainWithNonceManager(transactionId) { $0.sendPlaybackStart() }
        logger.debug { "sendPlaybackStart[\(transactionId)]" }
    }

    func sendPlaybackEnd(transactionId: String) {
        onMainWithNonceManager(transactionId) { $0.sendPlaybackEnd() }
        logger.debug { "sendPlaybackEnd[\(transactionId)]" }
    }

    func sendAdClick(transactionId: String) {
        onMainWithNonceManager(transactionId) { $0.sendAdClick() }
        logger.debug { "sendAdClick[\(transactionId)]" }
    }

    func sendAdError(transactionId: String, errorCode: Int32) {
        onMainWithNonceManager(transactionId) { $0.sendPlaybackEnd() }
        logger.debug { "sendAdError[\(transactionId)] errorCode: \(errorCode)" }
    }

    func release(transactionId: String) {
        let removed = lock.sync {
            (nonceLoaders.removeValue(forKey: transactionId),
             nonceManagers.removeValue(forKey: transactionId),
             nonceDelegates.removeValue(forKey: transactionId))
        }
        // The PAL objects were created and driven on the main thread; let their last reference
        // drop there too rather than on whichever dispatcher called release.
        let boxedRemoved = UncheckedSendable(value: removed)
        onMainAsync { withExtendedLifetime(boxedRemoved.value) {} }
        logger.debug { "release[\(transactionId)]" }
    }

    /// Resolves the manager under the lock, then drives PAL from the main thread.
    private func onMainWithNonceManager(_ transactionId: String, _ body: @escaping (NonceManager) -> Void) {
        guard let manager = lock.sync({ nonceManagers[transactionId] }) else { return }
        let boxedWork = UncheckedSendable(value: { body(manager) })
        onMainAsync { boxedWork.value() }
    }

    private func onMainAsync(_ work: @escaping @MainActor () -> Void) {
        if Thread.isMainThread {
            MainActor.assumeIsolated(work)
        } else {
            DispatchQueue.main.async { MainActor.assumeIsolated(work) }
        }
    }

    private static func sha256(_ input: String) -> String {
        let digest = SHA256.hash(data: Data(input.utf8))
        return digest.map { String(format: "%02x", $0) }.joined()
    }
}

/// Bridges PAL's delegate-based `NonceLoader` API to a closure-based callback.
///
/// The callback resumes a Kotlin `CancellableContinuation`, which throws `IllegalStateException`
/// when resumed twice - thrown from an ObjC frame, where neither Swift nor Kotlin can catch it.
/// So the first of `didLoad`/`didFailWith` to arrive wins and any later delegate call is dropped.
private final class NonceLoaderCallbackDelegate: NSObject, NonceLoaderDelegate {
    private let lock = NSLock()
    private var hasFired = false
    private let onLoaded: (NonceManager) -> Void
    private let onFailed: (Error) -> Void

    init(onLoaded: @escaping (NonceManager) -> Void, onFailed: @escaping (Error) -> Void) {
        self.onLoaded = onLoaded
        self.onFailed = onFailed
    }

    private func claim() -> Bool {
        lock.sync {
            if hasFired { return false }
            hasFired = true
            return true
        }
    }

    func nonceLoader(_ nonceLoader: NonceLoader, with request: NonceRequest, didLoad nonceManager: NonceManager) {
        guard claim() else { return }
        onLoaded(nonceManager)
    }

    func nonceLoader(_ nonceLoader: NonceLoader, with request: NonceRequest, didFailWith error: any Error) {
        guard claim() else { return }
        onFailed(error)
    }
}
#endif
