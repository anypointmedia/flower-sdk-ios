import SwiftUI
import AVFoundation
import sdk_core

public class FlowerAVPlayer: AVQueuePlayer {
    let logger = FLogging(tag: nil).logger

    private var adConfig: FlowerAdConfig?
    internal let adView: FlowerAdView
    private var changedChannelUrl: String? = nil

    internal func getAdView() -> FlowerAdView {
        return adView
    }

    public override init() {
        adView = FlowerAdView()
        super.init()
    }

    public func setAdConfig(adConfig: FlowerLinearTvAdConfig) {
        self.adConfig = adConfig
    }

    public func addAdListener(listener: FlowerAdsManagerListener) {
        adView.adsManager.addListener(adsManagerListener: listener)
    }

    public func removeAdListener(listener: FlowerAdsManagerListener) {
        adView.adsManager.removeListener(adsManagerListener: listener)
    }

    public override func play() {
        guard let item = currentItem else {
            logger.warn { "FlowerAVPlayer will play without FlowerAds since currentItem is nil" }
            super.play()
            return
        }

        guard let urlAsset = item.asset as? AVURLAsset else {
            logger.warn { "FlowerAVPlayer will play without FlowerAds since item.asset is not an AVURLAsset" }
            super.play()
            return
        }

        guard let adConfig = adConfig as? FlowerLinearTvAdConfig else {
            logger.warn { "FlowerAVPlayer will play without FlowerAds since adConfig was not properly set." }
            super.play()
            return
        }

        if (changedChannelUrl != nil) {
            super.play()
            return
        }

        changedChannelUrl = adView.adsManager.changeChannelUrl(
            videoUrl: urlAsset.url.absoluteString,
            adTagUrl: adConfig.adTagUrl,
            channelId: adConfig.channelId,
            extraParams: adConfig.extraParams ?? [:],
            mediaPlayerHook: MediaPlayerHookImpl { [weak self] in
                self
            },
            adTagHeaders: adConfig.adTagHeaders ?? [:],
            channelStreamHeaders: adConfig.channelStreamHeaders ?? [:],
            prerollAdTagUrl: adConfig.prerollAdTagUrl
        )

        replaceCurrentItem(with: AVPlayerItem(url: URL(string: changedChannelUrl!)!))
        super.play()
    }

    public override func replaceCurrentItem(with item: AVPlayerItem?) {
        if item == nil {
            adView.adsManager.stop()
            changedChannelUrl = nil
        }
        super.replaceCurrentItem(with: item)
    }

    @available(*, unavailable, message: "FlowerAVPlayer does not support this method")
    public override nonisolated func items() -> [AVPlayerItem] {
        return []
    }

    @available(*, unavailable, message: "FlowerAVPlayer does not support this method")
    public override nonisolated func advanceToNextItem() {
    }

    @available(*, unavailable, message: "FlowerAVPlayer does not support this method")
    public override nonisolated func canInsert(_ item: AVPlayerItem, after afterItem: AVPlayerItem?) -> Bool {
        false
    }

    @available(*, unavailable, message: "FlowerAVPlayer does not support this method")
    public override nonisolated func insert(_ item: AVPlayerItem, after afterItem: AVPlayerItem?) {
    }

    @available(*, unavailable, message: "FlowerAVPlayer does not support this method")
    public override nonisolated func remove(_ item: AVPlayerItem) {
    }

    @available(*, unavailable, message: "FlowerAVPlayer does not support this method")
    public override nonisolated func removeAllItems() {
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
