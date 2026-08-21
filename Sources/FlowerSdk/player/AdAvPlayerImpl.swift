import Foundation
import AVKit
import AVFoundation
import SwiftUI
import sdk_core

// All mutable state on this Kotlin-facing player wrapper is only ever mutated on the main
// thread (every mutation below is already dispatched via `DispatchQueue.main.async`/`.sync`),
// so it's safe to declare it `Sendable` and let it cross into `Task`/closures without the
// compiler's conservative "sending self" diagnostics.
class AdAvPlayerImpl: AdPlayer, @unchecked Sendable {
    private var logger = FLogging(tag: "AdAvPlayerImpl").logger
    private let sdkContainer = sdk_core.SdkContainer.companion.getInstance()
    private var isAdPlaying = false
    private var totalDuration: Int32 = -1
    private let externalPlayer: AVPlayer?
    private var player: AVPlayer?
    private var adPlayerCallbacks = AdPlayerCallbacks()
    private var mediaUrls: [String] = []
    private var stopJob: DispatchWorkItem?
    private var loadJob: DispatchWorkItem?
    private var playStartTime: Int64 = 0
    private var adPlayerView: AdPlayerViewImpl!

    private var durations: [Double] = []
    private var originalMediaUrls: [String] = []
    private var originalPosition: Double = 0
    private var adCount: Int = 0
    private var currentIndex: Int = 0
    /// Ad items prepared by `load()`. They only reach the player when `play()` runs.
    private var adPlayerItems: [AVPlayerItem] = []
    /// True once the ad items have displaced whatever the player was showing.
    private var adItemsAttached = false
    /// Playback speed the host app was using, restored when the original content comes back.
    private var originalRate: Float = 1.0

    init(player: AVPlayer? = nil) {
        self.externalPlayer = player
    }

    func load(playItems: NSMutableArray, totalDuration: Int32, adPlayerView: AdPlayerView) {
        let playItemList = playItems as! [PlayItem]
        let mediaUrls = playItemList.map {
            $0.url
        }
        if mediaUrls.count == 0 {
            logger.warn { "empty mediaUrls" }
            fatalError("empty mediaUrls")
        }
        self.adPlayerView = adPlayerView as? AdPlayerViewImpl
        loadJob?.cancel()
        loadJob = DispatchWorkItem { [weak self] in
            guard let self = self else { return }

            do {
                // An AVPlayer holds a single item, so "loading" an ad into an external player could
                // only mean replacing what the host app is showing - which ends the content before
                // the caller has asked for the ad to start. Loading therefore only prepares the ad
                // items; displacing the content, and recording what was displaced, happens in
                // `play()`. Players with a real playlist enqueue instead and have no such problem.
                if self.externalPlayer == nil {
                    self.release()
                } else {
                    self.cancelReleaseAndStopJob()
                    self.adItemsAttached = false
                }

                self.adCount = mediaUrls.count
                self.mediaUrls = mediaUrls
                self.originalMediaUrls = []
                self.originalPosition = 0
                self.totalDuration = totalDuration
                self.durations = []
                self.currentIndex = 0

                self.adPlayerItems = self.convertMediaSource()
                for item in self.adPlayerItems {
                    self.durations.append(CMTimeGetSeconds(item.asset.duration) * 1000)
                }

                guard let firstItem = self.adPlayerItems.first else { return }
                if self.externalPlayer == nil {
                    self.logger.info { "Creating new AVPlayer (no externalPlayer)" }
                    self.player = AVPlayer(playerItem: firstItem)
                    self.observeEnd(of: firstItem)
                    self.adItemsAttached = true
                } else {
                    self.logger.info { "Reusing external player (externalPlayer provided) - item swap deferred to play()" }
                }

                self.adPlayerCallbacks.onLoaded(mediaUrl: mediaUrls[0], duration: totalDuration)
            } catch let error {
                self.logger.error { "failed to load play set \(error)" }
                self.adPlayerCallbacks.onError(mediaUrl: mediaUrls[0], t: error as! KotlinThrowable)
            }
        }
        DispatchQueue.main.async(execute: loadJob!)
    }

    func convertMediaSource() -> [AVPlayerItem] {
        return mediaUrls.map { AVPlayerItem(url: URL(string: $0)!) }
    }

    func play() {
        logger.info { "play flower ads" }
        self.isAdPlaying = true

        DispatchQueue.main.async {
            guard let player = self.attachAdItems() else {
                self.logger.warn { "ad player is not initialized" }
                return
            }

            do {
                self.adPlayerView.show()
                let playerLayer = AVPlayerLayer(player: player)
                self.adPlayerView.addPlayerLayer(playerLayer: playerLayer)
                try player.play()
                self.logger.info { "ad player start to play" }
                self.adPlayerCallbacks.onPlay(mediaUrl: self.mediaUrls[0] as! String)
            } catch let error {
                self.logger.error { "failed to play \(error)" }
                self.adPlayerCallbacks.onError(mediaUrl: self.mediaUrls[0] as! String, t: error as! KotlinThrowable)
            }
        }
    }

    /// Hands the prepared ad items to the player and returns it, or nil if there is nothing to play.
    ///
    /// For an external player this is the moment the content is displaced, and it is deliberately
    /// not done in `load()`: until the caller asks for the ad to start the host app is still
    /// playing, and a single-item AVPlayer cannot hold an ad without ending that playback. The
    /// displaced source and its position are recorded here so the break can hand playback back.
    private func attachAdItems() -> AVPlayer? {
        guard let externalPlayer = self.externalPlayer else {
            return self.player
        }
        if adItemsAttached {
            return self.player
        }
        guard let firstItem = adPlayerItems.first else {
            return nil
        }

        // Ads always play at normal speed, so a host app watching at 1.5x must get its speed back
        // with the content. A rate of 0 means the app was paused, which is not a speed to restore.
        originalRate = externalPlayer.rate > 0 ? externalPlayer.rate : 1.0

        if let currentItem = externalPlayer.currentItem,
           let urlAsset = currentItem.asset as? AVURLAsset {
            let position = CMTimeGetSeconds(externalPlayer.currentTime()) * 1000
            originalMediaUrls = [urlAsset.url.absoluteString]
            originalPosition = position.isFinite ? max(0, position) : 0
            mediaUrls = mediaUrls + originalMediaUrls
            // The original's own duration is never read for ad progress, and measuring it here
            // would force a synchronous asset load on the main thread. `enqueueNextItem` reports 0
            // for the same reason.
            durations.append(0)
            logger.info { "saved original from player: url=\(urlAsset.url.absoluteString), position=\(self.originalPosition)" }
        }

        // Pause before the swap. `rate` survives `replaceCurrentItem`, so a host app watching at
        // 1.5x would otherwise run the ad at 1.5x for the window between the swap and the `play()`
        // that follows - and `play()` is what puts the ad back at 1.0.
        externalPlayer.pause()
        externalPlayer.replaceCurrentItem(with: firstItem)
        self.player = externalPlayer
        observeEnd(of: firstItem)
        adItemsAttached = true
        return externalPlayer
    }

    private func observeEnd(of item: AVPlayerItem) {
        NotificationCenter.default.addObserver(
            self,
            selector: #selector(adPlayerDidFinishPlaying(_:)),
            name: .AVPlayerItemDidPlayToEndTime,
            object: item
        )
    }

    func stop() {
        logger.info { "stop flower ads" }
        guard let player = self.player else {
            logger.warn { "ad player is not initialized" }
            return
        }
        cancelPlayerJobs()
        let work = {
            self.adPlayerView.hide()
            player.pause()
            self.logger.info { "ad player stop" }
            self.release()
            self.adPlayerCallbacks.onStopped()
        }
        if Thread.isMainThread {
            work()
        } else {
            DispatchQueue.main.sync { work() }
        }
    }

    func cancelPlayerJobs() {
        logger.info { "cancel load playSet job..." }
        if loadJob != nil {
            self.loadJob?.cancel()
            self.loadJob = nil
        }
        playStartTime = 0
    }

    func release() {
        if player == nil {
            logger.warn { "ad player is not initialized" }
            return
        }
        cancelReleaseAndStopJob()
        releasePlayer()
    }

    func releasePlayer() {
        do {
            if player != nil {
                NotificationCenter.default.removeObserver(self, name: .AVPlayerItemDidPlayToEndTime, object: player!.currentItem)
                player!.pause()
                player!.replaceCurrentItem(with: nil)
                adPlayerView.removePlayerLayer()
                logger.info { "ad player release" }
            }
        } catch {
            logger.error { "failed to release player" }
        }
        do {
            isAdPlaying = false
            adItemsAttached = false
            adPlayerItems = []
            // Don't nil out external player - it's owned by the caller
            if externalPlayer == nil {
                player = nil
            }
            currentIndex = 0
            logger.info { "exit releasePlayer" }
        }
    }

    func cancelReleaseAndStopJob() {
        do {
            if stopJob != nil {
                stopJob!.cancel()
                stopJob = nil
            }
        } catch {
            logger.warn { "releaseJob canceled" }
        }
    }

    func addCallback(adPlayerCallback: AdPlayerCallback) {
        adPlayerCallbacks.addCallback(callback: adPlayerCallback)
    }

    func removeCallback(adPlayerCallback: AdPlayerCallback) {
        adPlayerCallbacks.removeCallback(callback: adPlayerCallback)
    }

    func getCurrentAdProgress() -> any DeferredStub {
        guard let player = self.player else {
            return DeferredStubImpl(task: Task { SendableBox(value: AdProgress.companion.NOT_READY) })
        }

        let playTime: Double = player.currentTime().seconds * 1000

        if currentIndex >= mediaUrls.count {
            return DeferredStubImpl(task: Task { SendableBox(value: AdProgress.companion.NOT_READY) })
        }

        return DeferredStubImpl(task: Task { SendableBox(value: AdProgress(currentTime: Int32(exactly: playTime.rounded()) ?? 0, duration: Int32(self.durations[self.currentIndex]))) })
    }

    func getCurrentPeriodIndex() -> Int {
        return currentIndex
    }

    func currentMediaUrl() -> String? {
        return nil
    }

    func onPlayerError(error: Any) {
        let nsMutableArray = NSMutableArray(array: [])
        adPlayerCallbacks.onError(mediaUrl: mediaUrls[0], t: error as! KotlinThrowable)
    }

    func onPlayWhenReadyChange(playWhenReady: Bool, reason: Int) {
        logger.debug { "onPlayWhenReadyChanged: playWhenReady=\(playWhenReady), reason=\(reason)" }
    }

    @objc func adPlayerDidFinishPlaying(_ notification: Notification) {
        NotificationCenter.default.removeObserver(self, name: .AVPlayerItemDidPlayToEndTime, object: notification.object)
        if currentIndex < mediaUrls.count - 1 {
            let nextIndex = currentIndex + 1
            // If transitioning to original content, seek after ready
            let shouldSeek = nextIndex >= adCount && !originalMediaUrls.isEmpty && originalPosition > 0
            playItem(at: nextIndex, seekToOriginal: shouldSeek)
        }
    }

    private var statusObservation: NSKeyValueObservation?

    private func cleanupAdState() {
        originalMediaUrls = []
        originalPosition = 0
        adCount = 0
        logger.info { "Ad state cleaned up" }
    }

    private func playItem(at index: Int, seekToOriginal: Bool = false) {
        guard let player = self.player, index < mediaUrls.count else { return }

        currentIndex = index
        let newItem = AVPlayerItem(url: URL(string: mediaUrls[index])!)

        NotificationCenter.default.addObserver(
            self,
            selector: #selector(adPlayerDidFinishPlaying(_:)),
            name: .AVPlayerItemDidPlayToEndTime,
            object: newItem
        )

        let shouldSeek = seekToOriginal || (index >= adCount && !originalMediaUrls.isEmpty && originalPosition > 0)
        if shouldSeek {
            let seekTime = CMTime(seconds: originalPosition / 1000.0, preferredTimescale: CMTimeScale(NSEC_PER_SEC))
            statusObservation?.invalidate()
            statusObservation = newItem.observe(\.status, options: [.new]) { [weak self] item, _ in
                if item.status == .readyToPlay {
                    self?.player?.seek(to: seekTime, toleranceBefore: .zero, toleranceAfter: .zero) { _ in
                        self?.startPlayback(atIndex: index)
                    }
                    self?.statusObservation?.invalidate()
                    self?.statusObservation = nil
                } else if item.status == .failed {
                    self?.logger.error { "seekWhenReady: item failed - \(item.error?.localizedDescription ?? "unknown")" }
                    self?.statusObservation?.invalidate()
                    self?.statusObservation = nil
                }
            }
            player.replaceCurrentItem(with: newItem)
        } else {
            player.replaceCurrentItem(with: newItem)
            startPlayback(atIndex: index)
        }
    }

    /// Starts the item at `index`, at normal speed for an ad and at the host app's speed once the
    /// original content is back. `rate` is a player property, not an item one, so a host app
    /// watching at 1.5x would otherwise have every ad played at 1.5x and would never get its speed
    /// back afterwards.
    private func startPlayback(atIndex index: Int) {
        guard let player = self.player else { return }
        if index >= adCount {
            player.rate = originalRate
        } else {
            player.play()
        }
    }

    func pause() {
        player?.pause()
    }

    func resume() {
        player?.play()
    }

    func isPause() -> any DeferredStub {
        return DeferredStubImpl(task: Task { SendableBox(value: KotlinBoolean(value: await self.player?.rate == 0.0)) })
    }

    func playNextItem_() -> any DeferredStub {
        guard let player = self.player else {
            return DeferredStubImpl(task: Task { SendableBox(value: KotlinBoolean(value: false)) })
        }

        if currentIndex < mediaUrls.count - 1 {
            let nextIndex = currentIndex + 1
            playItem(at: nextIndex)
            return DeferredStubImpl(task: Task { SendableBox(value: KotlinBoolean(value: true)) })
        } else {
            logger.info { "No more media items to play" }
            return DeferredStubImpl(task: Task { SendableBox(value: KotlinBoolean(value: false)) })
        }
    }

    func seekTo(offsetMs: Double) {
        guard let player = self.player else { return }
        let seconds = offsetMs / 1000.0
        let time = CMTime(seconds: seconds, preferredTimescale: CMTimeScale(NSEC_PER_SEC))
        player.seek(to: time)
    }

    func enqueueNextItem(playItem: PlayItem) {
        mediaUrls.append(playItem.url)
        durations.append(0)
    }

    func removeNextItem(playItem: PlayItem) {
        if let index = mediaUrls.firstIndex(of: playItem.url) {
            // Don't remove the currently playing item
            if index != currentIndex {
                mediaUrls.remove(at: index)
                if index < durations.count {
                    durations.remove(at: index)
                }
                // Adjust currentIndex if needed
                if index < currentIndex {
                    currentIndex -= 1
                }
            }
        }
    }
}
