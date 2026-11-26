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
    private var prerollListener: FlowerAdsManagerListener?

    private func removePrerollListener() {
        if let listener = prerollListener {
            flowerAdView.adsManager.removeListener(adsManagerListener: listener)
        }
        prerollListener = nil
    }

    /// 채널 프리롤의 끝(첫 onCompleted 또는 onError)만 onEnd로 알린다. 나머지 이벤트는 쓰지 않는다.
    private final class ChannelPrerollListener: FlowerAdsManagerListener, @unchecked Sendable {
        private let onEnd: (ChannelPrerollListener) -> Void

        init(onEnd: @escaping (ChannelPrerollListener) -> Void) {
            self.onEnd = onEnd
        }

        func onCompleted() { onEnd(self) }
        func onError(error: FlowerError?) { onEnd(self) }
        func onPrepare(adDurationMs: Int32) {}
        func onPlay() {}
        func onAdPlay(adInfo: AdInfo) {}
        func onAdUserAction(action: String, adInfo: AdInfo) {}
        func onAdBreakSkipped(reason: Int32) {}
        func onAdBreakPrepare(adInfos: NSMutableArray) {}
    }

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
            removePrerollListener()
            flowerAdView.adsManager.stop()
            changedChannelUrl = nil
            prerollPrepared = nil
            self.adConfig = nil
            playFlag = false
            super.replaceCurrentItem(with: nil)
            return
        }

        // 새 아이템을 넣을 때마다 이전 호출의 프리롤 대기를 끝낸다. 광고 없이 넣는 경우도 같다.
        // 리스너가 남아 있으면 이전 채널의 프리롤 끝 이벤트(stop()으로 파괴된 프리롤 핸들러가 광고 진행 감시를
        // 취소하며 보내는 onCompleted 포함)가 이전 채널의 프록시 URL(이미 닫힘)로 지금 아이템을 덮어쓴다.
        // prerollPrepared가 false로 남으면 이 아이템의 play()가 계속 보류된다.
        removePrerollListener()
        prerollPrepared = nil

        let adConfig = adConfig ?? self.adConfig

        guard let adConfig = adConfig else {
            logger.warn{ "Flower player will play without ad insertion since adConfig was not properly set." }
            super.replaceCurrentItem(with: mediaItem)
            return
        }

        guard let mediaUri = (mediaItem.asset as? AVURLAsset)?.url else {
            logger.warn{ "Flower player will play without ad insertion since mediaItem uri is null" }
            super.replaceCurrentItem(with: mediaItem)
            return
        }

        // 이전 아이템을 비운다. 아래 changeChannelUrl()·requestVodAdImpl()의 stop()이 그 아이템의 프록시를 닫고, 새 아이템은
        // 프리롤이 끝난 뒤에 넣는다. 그동안 이전 아이템이 남아 재생을 이어 가면 닫힌 프록시에 연결이 거부된다.
        // 첫 진입과 같은 빈 상태에서 프리롤을 시작한다. 첫 진입처럼 이미 비어 있으면 nil을 다시 넣지 않는다.
        // 빈 플레이어에 nil을 다시 넣으면 첫 진입 프리롤 광고가 보이지 않았다(실기기 확인).
        if currentItem != nil {
            super.replaceCurrentItem(with: nil)
        }

        switch adConfig {
        case let linearConfig as FlowerLinearTvAdConfig:
            setLinearTvMedia(mediaItem: mediaItem, mediaUri: mediaUri.absoluteString, adConfig: linearConfig)

        case let vodConfig as FlowerVodAdConfig:
            setVodMedia(mediaItem: mediaItem, mediaUri: mediaUri.absoluteString, adConfig: vodConfig)

        default:
            super.replaceCurrentItem(with: mediaItem)
        }
    }

    private func setLinearTvMedia(mediaItem: AVPlayerItem, mediaUri: String, adConfig linearConfig: FlowerLinearTvAdConfig) {
        // 이전 세션을 먼저 정리한다. changeChannelUrl()도 처음에 stop()을 부르지만, 아래에서 프리롤 리스너를
        // 그보다 먼저 등록하므로 이전 핸들러를 파괴할 때 나오는 이벤트가 새 리스너에 닿지 않게 여기서 끝낸다.
        flowerAdView.adsManager.stop()

        // 채널 프리롤은 changeChannelUrl()이 맡는다. SDK가 프리롤을 요청해 자기 광고 플레이어로 재생하고,
        // 그동안 본편을 일시정지했다가 끝나면 재개한다. 같은 채널 재진입이면 건너뛰고 onCompleted만 보낸다.
        let prerollAdTagUrl = linearConfig.prerollAdTagUrl
        if prerollAdTagUrl != nil {
            // SDK는 본편을 프리롤이 준비된 순간(onPrepare)에야 일시정지한다. AVPlayer는 아이템을 넣는 순간 로드를
            // 시작하므로, 채널이 보이거나 광고와 함께 로드되지 않게 첫 onCompleted까지 새 아이템과 앱의 play()를
            // 보류한다(연동 가이드의 직접 연동 Pre-roll Ads와 같은 흐름). 프리롤이 없거나 실패해도 SDK는
            // onCompleted로 끝낸다.
            // 리스너는 changeChannelUrl() 전에 등록한다. 프리롤 요청은 그 안에서 시작되고 끝 이벤트는 그 순간
            // 등록된 리스너에게만 전달되므로, 요청이 바로 실패하면 changeChannelUrl()이 반환되기 전에 끝날 수 있다.
            prerollPrepared = false
            let listener = ChannelPrerollListener { listener in
                // SDK는 onError를 메인이 아닌 스레드에서 보낼 수 있다. 메인 큐에서 실행되므로 setLinearTvMedia()가
                // changedChannelUrl을 정한 다음이다.
                DispatchQueue.main.async {
                    // 지금 채널의 리스너가 처음 받은 끝 이벤트에서만 시작한다.
                    guard (self.prerollListener as AnyObject?) === listener,
                          let url = self.changedChannelUrl.flatMap({ URL(string: $0) }) else { return }
                    self.removePrerollListener()
                    // 프리롤이 끝났으므로 이후 앱의 play()는 바로 플레이어로 간다.
                    self.prerollPrepared = nil
                    super.replaceCurrentItem(with: AVPlayerItem(url: url))
                    // 앱이 프리롤 동안 미룬 play()를 실행한다. 프리롤이 끝나면 SDK도 본편 플레이어를 resume()한다.
                    if self.playFlag {
                        super.play()
                    }
                }
            }
            prerollListener = listener
            flowerAdView.adsManager.addListener(adsManagerListener: listener)
        }

        changedChannelUrl = flowerAdView.adsManager.changeChannelUrl(
            videoUrl: mediaUri,
            adTagUrl: linearConfig.adTagUrl,
            channelId: linearConfig.channelId,
            extraParams: linearConfig.extraParams ?? [:],
            mediaPlayerHook: MediaPlayerHookImpl { self },
            adTagHeaders: linearConfig.adTagHeaders ?? [:],
            channelStreamHeaders: linearConfig.channelStreamHeaders ?? [:],
            prerollAdTagUrl: prerollAdTagUrl
        )

        // 프리롤을 요청했으면 끝 이벤트를 기다린다. SDK가 프록시를 열지 못하면(잘못된 URL, 플레이어·프록시 생성
        // 실패) 프리롤을 요청하지 않고 원본 URL을 돌려주므로 끝 이벤트가 오지 않는다. 프리롤을 요청한 뒤의
        // 반환값은 항상 프록시 URL이라 원본과 같을 수 없다.
        if prerollAdTagUrl == nil || changedChannelUrl == nil || changedChannelUrl == mediaUri {
            removePrerollListener()
            prerollPrepared = nil
            if let changedChannelUrl, changedChannelUrl != mediaUri, let url = URL(string: changedChannelUrl) {
                super.replaceCurrentItem(with: AVPlayerItem(url: url))
            } else {
                // 프록시 URL을 받지 못했으면 앱이 넘긴 아이템을 그대로 재생한다.
                super.replaceCurrentItem(with: mediaItem)
            }
        }
    }

    private func setVodMedia(mediaItem: AVPlayerItem, mediaUri: String, adConfig vodConfig: FlowerVodAdConfig) {
        let minPrepareDuration = vodConfig.minPrepareDuration ?? VodAdHandler.companion.DEFAULT_MIN_PREPARE_DURATION
        let rewindDuration = vodConfig.rewindDuration ?? VodAdHandler.companion.DEFAULT_REWIND_DURATION

        prerollPrepared = false

        let onPrerollCompleted: () -> Void = {
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

            // 프리롤 리스너의 메인 큐 블록에서 부르므로 바로 넣는다. 한 번 더 예약하면 그 사이 들어온 교체·정지 뒤에
            // 이전 아이템을 넣는다.
            super.replaceCurrentItem(with: mediaItem)
        }

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
            private let releaseFromPlayer: (PrerollEventListener) -> Bool

            init(
                logger: Logger_,
                flowerAdView: FlowerAdView,
                playFlagProvider: @escaping () -> Bool,
                setPrerollPrepared: @escaping (Bool?) -> Void,
                onPrerollCompletedProvider: @escaping () -> (() -> Void),
                play: @escaping () -> Void,
                releaseFromPlayer: @escaping (PrerollEventListener) -> Bool,
            ) {
                self.logger = logger
                self.flowerAdView = flowerAdView
                self.playFlagProvider = playFlagProvider
                self.setPrerollPrepared = setPrerollPrepared
                self.onPrerollCompletedProvider = onPrerollCompletedProvider
                self.play = play
                self.releaseFromPlayer = releaseFromPlayer
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
                // isolation check and crashes.
                DispatchQueue.main.async {
                    // 플레이어의 prerollListener가 이 리스너를 계속 잡고 있으면, 리스너의 클로저가 잡은 플레이어와
                    // 서로를 잡아 둘 다 해제되지 않는다. 끝난 리스너는 여기서 놓는다.
                    // 이 블록이 실행되기 전에 새 아이템이 들어왔거나 정지됐으면(리스너가 바뀜) 이전 VOD 아이템을 넣지 않는다.
                    guard self.releaseFromPlayer(self) else { return }
                    self.onPrerollCompletedProvider()()

                    if self.playFlagProvider() {
                        self.setPrerollPrepared(nil)
                        self.play()
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
            play: { super.play() },
            releaseFromPlayer: { listener in
                // 지금 아이템의 리스너일 때만 놓고 true를 돌려준다. 새 아이템의 리스너가 들어왔거나 정지로 비워졌으면
                // 그대로 두고 false를 돌려준다.
                guard (self.prerollListener as AnyObject?) === listener else { return false }
                self.prerollListener = nil
                return true
            }
        )

        prerollListener = prerollEventListener
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
                videoUrl: mediaUri,
                requestTimeout: vodConfig.requestTimeout != nil ? KotlinLong(value: vodConfig.requestTimeout!) : nil,
                minPrepareDuration: minPrepareDuration != nil ? KotlinLong(value: minPrepareDuration) : nil,
                rewindDuration: rewindDuration != nil ? KotlinLong(value: rewindDuration) : nil,
            )
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
