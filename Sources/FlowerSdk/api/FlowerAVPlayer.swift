import SwiftUI
import AVFoundation
import sdk_core

open class FlowerAVPlayer: AVQueuePlayer {
    let logger = FLogging(tag: "FlowerAVPlayer").logger

    private var adConfig: FlowerAdConfig?
    // Public so integrators can reach `flowerAdView.adsManager`.
    // Exposes only the already-public FlowerAdsManager.
    public let flowerAdView = FlowerAdView()
    private var changedChannelUrl: String? = nil
    private var prerollPrepared: Bool? = nil
    private var playFlag = false

    public override init() {
        super.init()
    }

    public init(url URL: URL, adConfig: FlowerAdConfig) {
        super.init()
        replaceCurrentItem(with: AVPlayerItem(url: URL), adConfig: adConfig)
    }

    public init(playerItem item: AVPlayerItem, adConfig: FlowerAdConfig) {
        super.init()
        replaceCurrentItem(with: item, adConfig: adConfig)
    }

    /// Rebuilds the current item during stall recovery, bypassing `handleMediaItemWithAds`
    /// so the (already running) ad pipeline is not torn down/re-initialized — this is a
    /// transport-only recovery. After this raw replace, `prerollPrepared` stays nil, so a
    /// subsequent `play()` resolves straight to `super.play()`.
    ///
    /// Called by ``PlayerDiagnostics`` (attached via the media player hook) on a fatal
    /// live stall; integrators do not call this directly.
    internal func replaceCurrentItemForRecovery(_ item: AVPlayerItem) {
        super.replaceCurrentItem(with: item)
    }

    public func setAdConfig(adConfig: FlowerLinearTvAdConfig) {
        logger.info { "setAdConfig - adTagUrl: \(adConfig.adTagUrl), channelId: \(adConfig.channelId), prerollAdTagUrl: \(adConfig.prerollAdTagUrl ?? "nil")" }
        self.adConfig = adConfig
    }

    public func addAdListener(listener: FlowerAdsManagerListener) {
        flowerAdView.adsManager.addListener(adsManagerListener: listener)
    }

    public func removeAdListener(listener: FlowerAdsManagerListener) {
        flowerAdView.adsManager.removeListener(adsManagerListener: listener)
    }

    open override func replaceCurrentItem(with item: AVPlayerItem?) {
        logger.debug { "replaceCurrentItem(with)" }
        handleMediaItemWithAds(mediaItem: item)
    }

    public func replaceCurrentItem(with item: AVPlayerItem?, adConfig: FlowerAdConfig) {
        logger.debug { "replaceCurrentItem(with, adConfig)" }
        handleMediaItemWithAds(mediaItem: item, adConfig: adConfig)
    }

    private func handleMediaItemWithAds(
        mediaItem: AVPlayerItem?,
        adConfig: FlowerAdConfig? = nil
    ) {
        guard let mediaItem = mediaItem else {
            logger.info { "Stopping FlowerAVPlayer"}
            flowerAdView.adsManager.stop()
            changedChannelUrl = nil
            prerollPrepared = nil
            self.adConfig = nil
            playFlag = false
            super.replaceCurrentItem(with: nil)
            return
        }

        let adConfig = adConfig ?? self.adConfig

        guard let adConfig = adConfig else {
            logger.warn{ "Flower player will play without ad insertion since adConfig was not properly set." }
            return
        }

        guard let mediaUri = (mediaItem.asset as? AVURLAsset)?.url else {
            logger.warn{ "Flower player will play without ad insertion since mediaItem uri is null" }
            super.replaceCurrentItem(with: mediaItem)
            return
        }

        var onPrerollCompleted: () -> Void = {}

        // All captured closures/state are only ever invoked on the main thread (the
        // `DispatchQueue.main.async` hop below is the only mutation point), so this local
        // listener is safe to declare `Sendable` for closure-capture purposes.
        final class PrerollEventListener: FlowerAdsManagerListener, @unchecked Sendable {
            func onAdPlay(adInfo: AdInfo) {
                
            }
            
            func onAdUserAction(action: String, adInfo: AdInfo) {
            }
            
            private let logger: Logger_
            private let flowerAdView: FlowerAdView
            private let playFlagProvider: () -> Bool
            private let setPrerollPrepared: (Bool?) -> Void
            private let onPrerollCompletedProvider: () -> (() -> Void)
            private let play: () -> Void

            init(
                logger: Logger_,
                flowerAdView: FlowerAdView,
                playFlagProvider: @escaping () -> Bool,
                setPrerollPrepared: @escaping (Bool?) -> Void,
                onPrerollCompletedProvider: @escaping () -> (() -> Void),
                play: @escaping () -> Void,
            ) {
                self.logger = logger
                self.flowerAdView = flowerAdView
                self.playFlagProvider = playFlagProvider
                self.setPrerollPrepared = setPrerollPrepared
                self.onPrerollCompletedProvider = onPrerollCompletedProvider
                self.play = play
            }

            func onPrepare(adDurationMs: Int32) {
                logger.info { "Preroll is prepared." }

                if playFlagProvider() {
                    setPrerollPrepared(nil)
                    flowerAdView.adsManager.play()
                } else {
                    setPrerollPrepared(true)
                }
            }

            func onPlay() {
            }

            func onCompleted() {
                logger.info { "Preroll is completed." }
                flowerAdView.adsManager.removeListener(adsManagerListener: self)

                // The SDK calls this from a background coroutine thread, but
                // onPrerollCompleted and the player state behind the providers belong
                // to the main actor — calling them here trips Swift 6's runtime
                // isolation check and crashes. play() stays a separate hop so it still
                // runs after the replaceCurrentItem that onPrerollCompleted enqueues.
                DispatchQueue.main.async {
                    self.onPrerollCompletedProvider()()

                    if self.playFlagProvider() {
                        self.setPrerollPrepared(nil)
                        DispatchQueue.main.async {
                            self.play()
                        }
                    } else {
                        self.setPrerollPrepared(true)
                    }
                }
            }

            func onError(error: FlowerError?) {
            }

            func onAdBreakSkipped(reason: Int32) {
            }

            func onAdBreakPrepare(adInfos: NSMutableArray) {
            }
        }

        let prerollEventListener = PrerollEventListener(
            logger: logger,
            flowerAdView: flowerAdView,
            playFlagProvider: { self.playFlag },
            setPrerollPrepared: { value in self.prerollPrepared = value },
            onPrerollCompletedProvider: { onPrerollCompleted },
            play: { super.play() }
        )

        switch adConfig {
        case let linearConfig as FlowerLinearTvAdConfig:
            if changedChannelUrl != nil {
                flowerAdView.adsManager.stop()
            }

            changedChannelUrl = flowerAdView.adsManager.changeChannelUrl(
                videoUrl: mediaUri.absoluteString,
                adTagUrl: linearConfig.adTagUrl,
                channelId: linearConfig.channelId,
                extraParams: linearConfig.extraParams ?? [:],
                mediaPlayerHook: MediaPlayerHookImpl { self },
                adTagHeaders: linearConfig.adTagHeaders ?? [:],
                channelStreamHeaders: linearConfig.channelStreamHeaders ?? [:],
                prerollAdTagUrl: nil
            )

            guard let changedChannelUrl = changedChannelUrl else {
                // Fallback if changeChannelUrl failed
                super.replaceCurrentItem(with: mediaItem)
                return
            }

            let newMediaItem = AVPlayerItem(url: URL(string: changedChannelUrl)!)

            let adsManagerImpl = flowerAdView.adsManager as? FlowerAdsManagerImpl
            // A channel entered again right after itself (a restart) does not replay its pre-roll.
            if let prerollAdTagUrl = linearConfig.prerollAdTagUrl, adsManagerImpl?.isLinearTvPrerollSeen != true {
                prerollPrepared = false

                onPrerollCompleted = {
                    DispatchQueue.main.async {
                        super.replaceCurrentItem(with: newMediaItem)
                    }
                }

                flowerAdView.adsManager.addListener(adsManagerListener: prerollEventListener)

                adsManagerImpl?.requestAdImpl(
                    adTagUrl: prerollAdTagUrl,
                    extraParams: linearConfig.extraParams ?? [:],
                    adTagHeaders: linearConfig.adTagHeaders ?? [:],
                    contentId: linearConfig.channelId,
                    mediaPlayerHook: MediaPlayerHookImpl { self },
                    isLinearTvPreroll: true,
                )
            } else {
                super.replaceCurrentItem(with: newMediaItem)
            }

        case let vodConfig as FlowerVodAdConfig:
            let minPrepareDuration = vodConfig.minPrepareDuration ?? VodAdHandler.companion.DEFAULT_MIN_PREPARE_DURATION
            let rewindDuration = vodConfig.rewindDuration ?? VodAdHandler.companion.DEFAULT_REWIND_DURATION

            prerollPrepared = false

            onPrerollCompleted = {
                // The listener holds no state and touches the player only on the main thread, so it
                // is safe to declare `Sendable` for closure-capture purposes. It used to keep the
                // midroll state in pointers to locals of this closure - pointers that dangled once
                // the closure returned, so a midroll wrote into whatever stack frame was there by
                // then: the rewind never ran, or the app crashed. The rewind is the SDK's ad player's
                // now (`setReturnRewind`).
                final class MidrollEventListener: FlowerAdsManagerListener, @unchecked Sendable {
                    func onAdPlay(adInfo: AdInfo) {
                    
                    }
                    
                    func onAdUserAction(action: String, adInfo: AdInfo) {
                    }
                    
                    private let logger: Logger_
                    private let flowerAdView: FlowerAdView
                    private let currentTime: () -> CMTime

                    init(
                        logger: Logger_,
                        flowerAdView: FlowerAdView,
                        currentTime: @escaping () -> CMTime,
                    ) {
                        self.logger = logger
                        self.flowerAdView = flowerAdView
                        self.currentTime = currentTime
                    }

                    // The SDK holds onPrepare until the content reaches the midroll's offset, so the
                    // ad plays right away - the same as an app driving adsManager by hand.
                    func onPrepare(adDurationMs: Int32) {
                        logger.info { "Midroll is prepared." }

                        DispatchQueue.main.async {
                            let seconds = CMTimeGetSeconds(self.currentTime())
                            let position = (seconds.isInfinite || seconds.isNaN) ? 0 : Int64(seconds * 1000)

                            self.logger.info { "Midroll play - position: \(position)" }
                            self.flowerAdView.adsManager.play()
                        }
                    }

                    func onPlay() {
                    }

                    // The SDK's ad player hands the content back itself, rewindDuration before
                    // where the midroll interrupted it.
                    func onCompleted() {
                        logger.info { "Midroll is completed." }
                    }

                    func onError(error: FlowerError?) {
                    }

                    func onAdBreakSkipped(reason: Int32) {
                    }

                    func onAdBreakPrepare(adInfos: NSMutableArray) {
                    }
                }

                let midrollListener = MidrollEventListener(
                    logger: self.logger,
                    flowerAdView: self.flowerAdView,
                    currentTime: { super.currentTime() },
                )
                self.flowerAdView.adsManager.addListener(adsManagerListener: midrollListener)

                DispatchQueue.main.async {
                    super.replaceCurrentItem(with: mediaItem)
                }
            }

            flowerAdView.adsManager.addListener(adsManagerListener: prerollEventListener)

            if let adsManagerImpl = flowerAdView.adsManager as? FlowerAdsManagerImpl {
                adsManagerImpl.requestVodAdImpl(
                    adTagUrl: vodConfig.adTagUrl,
                    contentId: vodConfig.contentId,
                    durationMs: vodConfig.contentDuration,
                    extraParams: vodConfig.extraParams ?? [:],
                    mediaPlayerHook: MediaPlayerHookImpl { self },
                    platformMediaPlayerAdapter: nil,
                    adTagHeaders: vodConfig.adTagHeaders ?? [:],
                    videoUrl: mediaUri.absoluteString,
                    requestTimeout: vodConfig.requestTimeout != nil ? KotlinLong(value: vodConfig.requestTimeout!) : nil,
                    minPrepareDuration: minPrepareDuration != nil ? KotlinLong(value: minPrepareDuration) : nil,
                    rewindDuration: rewindDuration != nil ? KotlinLong(value: rewindDuration) : nil,
                )
            }

        default:
            super.replaceCurrentItem(with: mediaItem)
        }
    }

    open override func play() {
        logger.debug { "play()" }
        if (prerollPrepared == nil) {
            super.play()
            return
        }

        if (prerollPrepared == true) {
            prerollPrepared = nil
            flowerAdView.adsManager.play()
        } else {
            playFlag = true
        }
    }

    @available(*, unavailable, message: "FlowerAVPlayer does not support this method")
    public override init(items: [AVPlayerItem]) {
        super.init()
    }

    @available(*, unavailable, message: "FlowerAVPlayer does not support this method")
    open override nonisolated func items() -> [AVPlayerItem] {
        return []
    }

    internal nonisolated func itemsInternal() -> [AVPlayerItem] {
        return super.items()
    }

    @available(*, unavailable, message: "FlowerAVPlayer does not support this method")
    open override nonisolated func advanceToNextItem() {
    }

    internal nonisolated func advanceToNextItemInternal() {
        super.advanceToNextItem()
    }

    @available(*, unavailable, message: "FlowerAVPlayer does not support this method")
    open override nonisolated func canInsert(_ item: AVPlayerItem, after afterItem: AVPlayerItem?) -> Bool {
        false
    }

    @available(*, unavailable, message: "FlowerAVPlayer does not support this method")
    open override nonisolated func insert(_ item: AVPlayerItem, after afterItem: AVPlayerItem?) {
    }

    internal nonisolated func insertInternal(_ item: AVPlayerItem, after afterItem: AVPlayerItem?) {
        super.insert(item, after: afterItem)
    }

    @available(*, unavailable, message: "FlowerAVPlayer does not support this method")
    open override nonisolated func remove(_ item: AVPlayerItem) {
    }

    internal nonisolated func removeInternal(_ item: AVPlayerItem) {
        super.remove(item)
    }

    @available(*, unavailable, message: "FlowerAVPlayer does not support this method")
    open override nonisolated func removeAllItems() {
    }

    internal nonisolated func removeAllItemsInternal() {
        super.removeAllItems()
    }

    private class MediaPlayerHookImpl: MediaPlayerHook {
        public var getPlayerFn: () -> Any?

        public init(getPlayerFn: @escaping () -> Any?) {
            self.getPlayerFn = getPlayerFn
        }

        public func getPlayer() -> Any? {
            getPlayerFn()
        }
    }
}

/// Queue access for SDK-internal code that receives its player through a `MediaPlayerHook`.
///
/// `FlowerAVPlayer` marks the `AVQueuePlayer` queue API unavailable and overrides it with empty
/// bodies so integrators cannot reorder a queue the SDK owns. Those overrides are still dispatched
/// dynamically, so SDK code that calls `advanceToNextItem()`/`remove(_:)`/`insert(_:after:)` on a
/// hook-supplied player reaches the empty body and the call silently does nothing - an ad skip that
/// never advances, a pre-buffered item that is never dropped. Every SDK-internal queue operation
/// must therefore go through these helpers, which route to the internal counterparts when the
/// player turns out to be a `FlowerAVPlayer`.
extension AVQueuePlayer {
    nonisolated func flowerItems() -> [AVPlayerItem] {
        guard let flowerPlayer = self as? FlowerAVPlayer else {
            return items()
        }
        return flowerPlayer.itemsInternal()
    }

    nonisolated func flowerInsert(_ item: AVPlayerItem, after afterItem: AVPlayerItem?) {
        guard let flowerPlayer = self as? FlowerAVPlayer else {
            insert(item, after: afterItem)
            return
        }
        flowerPlayer.insertInternal(item, after: afterItem)
    }

    nonisolated func flowerRemove(_ item: AVPlayerItem) {
        guard let flowerPlayer = self as? FlowerAVPlayer else {
            remove(item)
            return
        }
        flowerPlayer.removeInternal(item)
    }

    nonisolated func flowerRemoveAllItems() {
        guard let flowerPlayer = self as? FlowerAVPlayer else {
            removeAllItems()
            return
        }
        flowerPlayer.removeAllItemsInternal()
    }

    nonisolated func flowerAdvanceToNextItem() {
        guard let flowerPlayer = self as? FlowerAVPlayer else {
            advanceToNextItem()
            return
        }
        flowerPlayer.advanceToNextItemInternal()
    }
}
