import Foundation
import AVKit
import AVFoundation
import SwiftUI
import sdk_core

// All mutable state on this Kotlin-facing player wrapper is only ever mutated on the main
// thread (every mutation below is already dispatched via `DispatchQueue.main.async`/`.sync`),
// so it's safe to declare it `Sendable` and let it cross into `Task`/closures without the
// compiler's conservative "sending self" diagnostics.
class AdPlayerImpl: AdPlayer, @unchecked Sendable {
    private var logger = FLogging(tag: "AdPlayerImpl").logger
    private let sdkContainer = sdk_core.SdkContainer.companion.getInstance()
    private var isAdPlaying = false
    private var totalDuration: Int32 = -1
    private let externalPlayer: AVQueuePlayer?
    private var player: AVQueuePlayer?
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
    private var originalItemObservation: NSKeyValueObservation?
    /// Ad items prepared by `load()`. They only reach the player when `play()` runs.
    private var adPlayerItems: [AVPlayerItem] = []
    /// True once the ad items have displaced whatever the player was showing.
    private var adItemsAttached = false
    /// Playback speed the host app was using, restored when the original content comes back.
    private var originalRate: Float = 1.0
    private var currentItemObservation: NSKeyValueObservation?

    init(player: AVQueuePlayer? = nil) {
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
            guard let self = self else {return}

            do {
                // Clearing the host queue is how an ad would be "loaded" into an external player,
                // and that ends the content before the caller has asked for the ad to start.
                // Loading therefore only prepares the ad items; the queue swap, and recording what
                // it displaced, happens in `play()`.
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


                let mediaSources = convertMediaSource()
                for source in mediaSources {
                    durations.append(CMTimeGetSeconds(source.asset.duration)*1000)
                }
                self.adPlayerItems = mediaSources

                if self.externalPlayer == nil {
                    // Note: Initialize in this order
                    // AVQueuePlayer > AVPlayerLayer > adPlayerView.layer.addSublayer(playerLayer)
                    self.logger.info { "Creating new AVQueuePlayer (no externalPlayer)" }
                    player = AVQueuePlayer(items: mediaSources)
                    self.adItemsAttached = true
                } else {
                    self.logger.info { "Reusing external player (externalPlayer provided) - queue swap deferred to play()" }
                }

                adPlayerCallbacks.onLoaded(mediaUrl: mediaUrls[0], duration: totalDuration)
            } catch let error {
                logger.error { "failed to load play set \(error)" }
                adPlayerCallbacks.onError(mediaUrl: mediaUrls[0], t: error as! KotlinThrowable)
            }
        }
        DispatchQueue.main.async(execute: loadJob!)
    }

    // Note: Due to OS differences, returning [AVPlayerItem] instead of MediaSource
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

    /// Puts the prepared ad items into the player's queue and returns it, or nil if there is
    /// nothing to play.
    ///
    /// For an external player this is the moment the content is displaced, and it is deliberately
    /// not done in `load()`: until the caller asks for the ad to start the host app is still
    /// playing, and clearing its queue would end that playback. The displaced sources and the
    /// position are recorded here so the break can hand playback back afterwards.
    private func attachAdItems() -> AVQueuePlayer? {
        guard let externalPlayer = self.externalPlayer else {
            return self.player
        }
        if adItemsAttached {
            return self.player
        }
        if adPlayerItems.isEmpty {
            return nil
        }

        // Ads always play at normal speed, so a host app watching at 1.5x must get its speed back
        // with the content. A rate of 0 means the app was paused, which is not a speed to restore.
        originalRate = externalPlayer.rate > 0 ? externalPlayer.rate : 1.0

        let existingUrls = externalPlayer.flowerItems().compactMap { item in
            (item.asset as? AVURLAsset)?.url.absoluteString
        }
        if !existingUrls.isEmpty {
            let position = CMTimeGetSeconds(externalPlayer.currentTime()) * 1000
            originalMediaUrls = existingUrls
            originalPosition = position.isFinite ? max(0, position) : 0
            mediaUrls = mediaUrls + originalMediaUrls
            logger.info { "saved original from player: urls=\(self.originalMediaUrls.count), position=\(self.originalPosition)" }
        }

        // Rebuild the original items rather than re-inserting the displaced ones: an AVPlayerItem
        // cannot be handed back to a queue it has already been removed from.
        let originalItems = originalMediaUrls.compactMap { URL(string: $0) }.map { AVPlayerItem(url: $0) }
        for _ in originalItems {
            // The original's own duration is never read for ad progress, and measuring it here
            // would force a synchronous asset load on the main thread.
            durations.append(0)
        }

        // Pause before the swap. `rate` survives the queue change, so a host app watching at 1.5x
        // would otherwise run the ad at 1.5x for the window between the swap and the `play()` that
        // follows - and `play()` is what puts the ad back at 1.0.
        externalPlayer.pause()
        externalPlayer.flowerRemoveAllItems()
        for source in adPlayerItems + originalItems {
            externalPlayer.flowerInsert(source, after: nil)
        }
        self.player = externalPlayer
        adItemsAttached = true
        observeReturnToOriginal(on: externalPlayer)

        // Pre-seek original items while ads are still playing
        preSeekOriginalItems()
        return externalPlayer
    }

    /// Restores the host app's playback speed once the queue reaches the original content.
    ///
    /// `rate` is a player property, not an item one, so a host app watching at 1.5x would otherwise
    /// have every ad played at 1.5x and would never get its speed back. An AVQueuePlayer advances
    /// on its own, so the hand-back has to be observed rather than hooked onto `playNextItem`.
    private func observeReturnToOriginal(on player: AVQueuePlayer) {
        currentItemObservation?.invalidate()
        currentItemObservation = player.observe(\.currentItem, options: [.new]) { [weak self] observed, _ in
            guard let self = self else { return }
            // The queue only shrinks, so what is left tells us how far it has advanced.
            let playedIndex = self.mediaUrls.count - observed.flowerItems().count
            guard playedIndex >= self.adCount, observed.rate > 0 else { return }
            observed.rate = self.originalRate
            self.currentItemObservation?.invalidate()
            self.currentItemObservation = nil
        }
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
                player!.pause()
                player!.replaceCurrentItem(with: nil)
                player!.flowerRemoveAllItems()
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
            currentItemObservation?.invalidate()
            currentItemObservation = nil
            // Don't nil out external player - it's owned by the caller
            if externalPlayer == nil {
                player = nil
            }
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
        let playingItemCount = player.flowerItems().count
        
        if playingItemCount == 0 {
            return DeferredStubImpl(task: Task { SendableBox(value: AdProgress.companion.NOT_READY) })
        }
                
        return DeferredStubImpl(task: Task { SendableBox(value: AdProgress(currentTime: Int32(exactly: playTime.rounded() ) ?? 0, duration: Int32(durations[durations.count - playingItemCount]))) })
    }

    func getCurrentPeriodIndex() -> Int {
        guard let currentItem = player?.currentItem else {
            return 0
        }

        if let playerItems = player?.flowerItems(),
           let currentIndex = playerItems.firstIndex(of: currentItem) {
            return currentIndex
        }
        return 0
    }

//    var volume

    func currentMediaUrl() -> String? {
        return nil
    }

    func onPlayerError(error: Any) { // Expect error: Kotlin.PlaybackException
        let nsMutableArray = NSMutableArray(array: [])
        adPlayerCallbacks.onError(mediaUrl: mediaUrls[0], t: error as! KotlinThrowable)
    }

    func onPlayWhenReadyChange(playWhenReady: Bool, reason: Int) {
        logger.debug { "onPlayWhenReadyChanged: playWhenReady=\(playWhenReady), reason=\(reason)" }
    }
//    func onVideoSizeChanged(videoSize: VideoSize) {
//
//    }

    /* Author: SEUNG
     * Note: As defined in Player.java
     *  int STATE_IDLE = 1;
     *  int STATE_BUFFERING = 2;
     *  int STATE_READY = 3;
     *  int STATE_ENDED = 4;
     */
//    func onPlaybackStateChanged(state: Int) {
//        switch state {
//        case 2:
//            print( "onPlaybackStateChanged: Player.STATE_BUFFERING" )
//        case 4:
//            print( "onPlaybackStateChanged: Player.STATE_ENDED" )
//            stop()
//        case 1:
//            print( "onPlaybackStateChanged: Player.STATE_IDLE" )
//        case 3:
//            print( "onPlaybackStateChanged: Player.STATE_READY" )
//        default:
//            print( "" )
//        }
//
//    }

    func pause() {
        player?.pause()
    }

    func resume() {
        player?.play()
    }

    func isPause() -> any DeferredStub {
        return DeferredStubImpl(task: Task { SendableBox(value: KotlinBoolean(value: await player?.rate == 0.0)) })
    }

    func playNextItem_() -> any DeferredStub {
        guard let player = self.player else {
            logger.warn { "playNextItem_: player is nil" }
            return DeferredStubImpl(task: Task { SendableBox(value: KotlinBoolean(value: false)) })
        }

        let itemCount = player.flowerItems().count
        logger.info { "playNextItem_: itemCount=\(itemCount)" }

        if itemCount > 1 {
            // Original items are already pre-seeked, just advance
            player.flowerAdvanceToNextItem()
            return DeferredStubImpl(task: Task { SendableBox(value: KotlinBoolean(value: true)) })
        } else {
            logger.info { "playNextItem_: No more media items to play" }
            return DeferredStubImpl(task: Task { SendableBox(value: KotlinBoolean(value: false)) })
        }
    }

    private var statusObservation: NSKeyValueObservation?

    /// Pre-seek original items in the queue so they start at the correct position
    /// when AVQueuePlayer auto-advances to them (avoids first-frame flash)
    private func preSeekOriginalItems() {
        guard let player = self.player,
              !originalMediaUrls.isEmpty,
              originalPosition > 0 else { return }

        let items = player.flowerItems()
        let seekTime = CMTime(seconds: originalPosition / 1000.0, preferredTimescale: CMTimeScale(NSEC_PER_SEC))

        // Original items start at index adCount
        for i in adCount..<items.count {
            let item = items[i]
            if item.status == .readyToPlay {
                logger.info { "preSeekOriginalItems: item[\(i)] already ready, seeking to \(self.originalPosition)ms" }
                item.seek(to: seekTime, toleranceBefore: .zero, toleranceAfter: .zero) { [weak self] finished in
                    self?.logger.info { "preSeekOriginalItems: item[\(i)] seek finished=\(finished)" }
                }
            } else {
                logger.info { "preSeekOriginalItems: item[\(i)] not ready, observing status" }
                originalItemObservation?.invalidate()
                originalItemObservation = item.observe(\.status, options: [.new]) { [weak self] observedItem, _ in
                    guard let self = self else { return }
                    if observedItem.status == .readyToPlay {
                        self.logger.info { "preSeekOriginalItems: item[\(i)] became ready, seeking to \(self.originalPosition)ms" }
                        observedItem.seek(to: seekTime, toleranceBefore: .zero, toleranceAfter: .zero) { finished in
                            self.logger.info { "preSeekOriginalItems: item[\(i)] seek finished=\(finished)" }
                        }
                        self.originalItemObservation?.invalidate()
                        self.originalItemObservation = nil
                    } else if observedItem.status == .failed {
                        self.logger.error { "preSeekOriginalItems: item[\(i)] failed - \(observedItem.error?.localizedDescription ?? "unknown")" }
                        self.originalItemObservation?.invalidate()
                        self.originalItemObservation = nil
                    }
                }
            }
        }
    }

    func seekTo(offsetMs: Double) {
        guard let player = self.player else {
            return
        }
        let seconds = offsetMs / 1000.0
        let time = CMTime(seconds: seconds, preferredTimescale: CMTimeScale(NSEC_PER_SEC))
        if let currentItem = player.currentItem {
            currentItem.seek(to: time)
        } else if let firstItem = player.flowerItems().first {
            firstItem.seek(to: time)
        }
    }

    func enqueueNextItem(playItem: PlayItem) {
        guard let player = self.player else {
            logger.warn {
                "ad player is not initialized"
            }
            return
        }

        let url = URL(string: playItem.url)!
        let playerItem = AVPlayerItem(url: url)
        player.flowerInsert(playerItem, after: nil)
        mediaUrls.append(playItem.url)
        durations.append(0) // Duration will be updated when loaded
    }

    func removeNextItem(playItem: PlayItem) {
        guard let player = self.player else {
            logger.warn {
                "ad player is not initialized"
            }
            return
        }

        if let index = mediaUrls.firstIndex(of: playItem.url) {
            let items = player.flowerItems()
            if index < items.count {
                player.flowerRemove(items[index])
            }
            mediaUrls.remove(at: index)
            if index < durations.count {
                durations.remove(at: index)
            }
        }
    }
}

