import SwiftUI
import AVFoundation
import sdk_core

open class FlowerAVPlayer: AVQueuePlayer {
    let logger = FLogging(tag: "FlowerAVPlayer").logger

    private var adConfig: FlowerAdConfig?
    internal let flowerAdView = FlowerAdView()
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

    @available(*, deprecated, message: "Use replaceCurrentItem() instead")
    public func setAdConfig(adConfig: FlowerLinearTvAdConfig) {
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

        final class PrerollEventListener: FlowerAdsManagerListener {
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
                onPrerollCompletedProvider()()

                if playFlagProvider() {
                    setPrerollPrepared(nil)
                    DispatchQueue.main.async {
                        self.play()
                    }
                } else {
                    setPrerollPrepared(true)
                }
            }

            func onError(error: FlowerError?) {
            }

            func onAdSkipped(reason: Int32) {
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

            if let prerollAdTagUrl = linearConfig.prerollAdTagUrl {
                prerollPrepared = false

                onPrerollCompleted = {
                    DispatchQueue.main.async {
                        super.replaceCurrentItem(with: newMediaItem)
                    }
                }

                flowerAdView.adsManager.addListener(adsManagerListener: prerollEventListener)

                if let adsManagerImpl = flowerAdView.adsManager as? FlowerAdsManagerImpl {
                    adsManagerImpl.requestAdImpl(
                        adTagUrl: prerollAdTagUrl,
                        extraParams: linearConfig.extraParams ?? [:],
                        adTagHeaders: linearConfig.adTagHeaders ?? [:],
                        contentId: linearConfig.channelId,
                        mediaPlayerHook: MediaPlayerHookImpl { self },
                    )
                }
            } else {
                super.replaceCurrentItem(with: newMediaItem)
            }

        case let vodConfig as FlowerVodAdConfig:
            let minPrepareDuration = vodConfig.minPrepareDuration ?? VodAdHandler.companion.DEFAULT_MIN_PREPARE_DURATION
            let rewindDuration = vodConfig.rewindDuration ?? VodAdHandler.companion.DEFAULT_REWIND_DURATION

            prerollPrepared = false

            onPrerollCompleted = {
                var currentPosition: Int64 = 0
                var midrollPrepared = false

                final class MidrollEventListener: FlowerAdsManagerListener {
                    private let logger: Logger_
                    private let flowerAdView: FlowerAdView
                    private let minPrepareDuration: Int64
                    private let rewindDuration: Int64
                    private var midrollPrepared: UnsafeMutablePointer<Bool>
                    private var currentPosition: UnsafeMutablePointer<Int64>
                    private let mediaUri: URL
                    private let currentTime: () -> CMTime
                    private let replaceCurrentItem: (AVPlayerItem) -> Void
                    private let seek: (CMTime) -> Void

                    init(
                        logger: Logger_,
                        flowerAdView: FlowerAdView,
                        minPrepareDuration: Int64,
                        rewindDuration: Int64,
                        midrollPrepared: UnsafeMutablePointer<Bool>,
                        currentPosition: UnsafeMutablePointer<Int64>,
                        mediaUri: URL,
                        currentTime: @escaping () -> CMTime,
                        replaceCurrentItem: @escaping (AVPlayerItem) -> Void,
                        seek: @escaping (CMTime) -> Void,
                    ) {
                        self.logger = logger
                        self.flowerAdView = flowerAdView
                        self.minPrepareDuration = minPrepareDuration
                        self.rewindDuration = rewindDuration
                        self.midrollPrepared = midrollPrepared
                        self.currentPosition = currentPosition
                        self.mediaUri = mediaUri
                        self.currentTime = currentTime
                        self.replaceCurrentItem = replaceCurrentItem
                        self.seek = seek
                    }

                    func onPrepare(adDurationMs: Int32) {
                        logger.info { "Midroll is prepared." }
                        midrollPrepared.pointee = true

                        DispatchQueue.global().async {
                            Thread.sleep(forTimeInterval: TimeInterval(self.minPrepareDuration) / 1000.0)

                            let position: Int64 = DispatchQueue.main.sync {
                                let position = CMTimeGetSeconds(self.currentTime())

                                return (position.isInfinite || position.isNaN) ? 0 : Int64(position * 1000)
                            }
                            self.currentPosition.pointee = position

                            self.flowerAdView.adsManager.play()
                        }
                    }

                    func onPlay() {
                    }

                    func onCompleted() {
                        logger.info { "Midroll is completed." }

                        if midrollPrepared.pointee {
                            midrollPrepared.pointee = false

                            DispatchQueue.main.async {
                                let newPosition = max(self.currentPosition.pointee - self.rewindDuration, 0)
                                let newMediaItem = AVPlayerItem(url: self.mediaUri)

                                self.replaceCurrentItem(newMediaItem)
                                self.seek(CMTimeMake(value: newPosition, timescale: 1000))
                            }
                        }
                    }

                    func onError(error: FlowerError?) {
                    }

                    func onAdSkipped(reason: Int32) {
                    }
                }

                var midrollPreparedPtr = midrollPrepared
                var currentPositionPtr = currentPosition

                withUnsafeMutablePointer(to: &midrollPreparedPtr) { midrollPreparedFlagPtr in
                    withUnsafeMutablePointer(to: &currentPositionPtr) { currentPositionValPtr in
                        let midrollListener = MidrollEventListener(
                            logger: self.logger,
                            flowerAdView: self.flowerAdView,
                            minPrepareDuration: minPrepareDuration,
                            rewindDuration: rewindDuration,
                            midrollPrepared: midrollPreparedFlagPtr,
                            currentPosition: currentPositionValPtr,
                            mediaUri: mediaUri,
                            currentTime: { super.currentTime() },
                            replaceCurrentItem: { item in super.replaceCurrentItem(with: item) },
                            seek: { position in super.seek(to: position) },
                        )
                        self.flowerAdView.adsManager.addListener(adsManagerListener: midrollListener)
                    }
                }

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

    @available(*, unavailable, message: "FlowerAVPlayer does not support this method")
    open override nonisolated func advanceToNextItem() {
    }

    @available(*, unavailable, message: "FlowerAVPlayer does not support this method")
    open override nonisolated func canInsert(_ item: AVPlayerItem, after afterItem: AVPlayerItem?) -> Bool {
        false
    }

    @available(*, unavailable, message: "FlowerAVPlayer does not support this method")
    open override nonisolated func insert(_ item: AVPlayerItem, after afterItem: AVPlayerItem?) {
    }

    @available(*, unavailable, message: "FlowerAVPlayer does not support this method")
    open override nonisolated func remove(_ item: AVPlayerItem) {
    }

    @available(*, unavailable, message: "FlowerAVPlayer does not support this method")
    open override nonisolated func removeAllItems() {
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
