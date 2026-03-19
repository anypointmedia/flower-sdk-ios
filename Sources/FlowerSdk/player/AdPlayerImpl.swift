import Foundation
import AVKit
import AVFoundation
import SwiftUI
import sdk_core

class AdPlayerImpl: AdPlayer {
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

    init(player: AVQueuePlayer? = nil) {
        self.externalPlayer = player
    }

    func load(mediaUrls: NSMutableArray, totalDuration: Int32, adPlayerView: AdPlayerView) {
        let mediaUrls = mediaUrls as! [String]
        if mediaUrls.count == 0 {
            logger.warn { "empty mediaUrls" }
            fatalError("empty mediaUrls")
        }
        self.adPlayerView = adPlayerView as? AdPlayerViewImpl
        loadJob?.cancel()
        loadJob = DispatchWorkItem { [weak self] in
            guard let self = self else {return}

            do {
                // Save original sources only once, but always update position
                if let existingPlayer = self.player {
                    if self.originalMediaUrls.isEmpty {
                        self.originalMediaUrls = existingPlayer.items().compactMap { item in
                            (item.asset as? AVURLAsset)?.url.absoluteString
                        }
                    }
                    self.originalPosition = CMTimeGetSeconds(existingPlayer.currentTime()) * 1000
                    self.logger.info { "saved original from player: urls=\(self.originalMediaUrls.count), position=\(self.originalPosition)" }
                }

                self.release()

                self.adCount = mediaUrls.count
                self.mediaUrls = mediaUrls + self.originalMediaUrls
                self.totalDuration = totalDuration
                self.durations = []


                let mediaSources = convertMediaSource()
                for source in mediaSources {
                    durations.append(CMTimeGetSeconds(source.asset.duration)*1000)
                }

                if let externalPlayer = self.externalPlayer {
                    // Reuse external player: clear existing items, insert new ones
                    self.logger.info { "Reusing external player (externalPlayer provided)" }
                    externalPlayer.removeAllItems()
                    for source in mediaSources {
                        externalPlayer.insert(source, after: nil)
                    }
                    player = externalPlayer
                } else {
                    // Note: Initialize in this order
                    // AVQueuePlayer > AVPlayerLayer > adPlayerView.layer.addSublayer(playerLayer)
                    self.logger.info { "Creating new AVQueuePlayer (no externalPlayer)" }
                    player = AVQueuePlayer(items: mediaSources)
                }

                // Pre-seek original items while ads are still playing
                self.preSeekOriginalItems()

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

        guard let player = self.player else {
            logger.warn { "ad player is not initialized" }
            return
        }

        DispatchQueue.main.async {
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
                player!.removeAllItems()
                adPlayerView.removePlayerLayer()
                logger.info { "ad player release" }
            }
        } catch {
            logger.error { "failed to release player" }
        }
        do {
            isAdPlaying = false
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
            return DeferredStubImpl(task: Task { AdProgress.companion.NOT_READY })
        }
        
        let playTime: Double = player.currentTime().seconds * 1000
        let playingItemCount = player.items().count
        
        if playingItemCount == 0 {
            return DeferredStubImpl(task: Task { AdProgress.companion.NOT_READY })
        }
                
        return DeferredStubImpl(task: Task { AdProgress(currentTime: Int32(exactly: playTime.rounded() ) ?? 0, duration: Int32(durations[durations.count - playingItemCount])) })
    }

    func getCurrentPeriodIndex() -> Int {
        guard let currentItem = player?.currentItem else {
            return 0
        }

        if let playerItems = player?.items(),
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
        return DeferredStubImpl(task: Task { KotlinBoolean(value: await player?.rate == 0.0) })
    }

    func playNextItem_() -> any DeferredStub {
        guard let player = self.player else {
            logger.warn { "playNextItem_: player is nil" }
            return DeferredStubImpl(task: Task { KotlinBoolean(value: false) })
        }

        let itemCount = player.items().count
        logger.info { "playNextItem_: itemCount=\(itemCount)" }

        if itemCount > 1 {
            // Original items are already pre-seeked, just advance
            player.advanceToNextItem()
            return DeferredStubImpl(task: Task { KotlinBoolean(value: true) })
        } else {
            logger.info { "playNextItem_: No more media items to play" }
            return DeferredStubImpl(task: Task { KotlinBoolean(value: false) })
        }
    }

    private var statusObservation: NSKeyValueObservation?

    /// Pre-seek original items in the queue so they start at the correct position
    /// when AVQueuePlayer auto-advances to them (avoids first-frame flash)
    private func preSeekOriginalItems() {
        guard let player = self.player,
              !originalMediaUrls.isEmpty,
              originalPosition > 0 else { return }

        let items = player.items()
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
        } else if let firstItem = player.items().first {
            firstItem.seek(to: time)
        }
    }

    func enqueueNextItem(mediaUrl: String) {
        guard let player = self.player else {
            logger.warn {
                "ad player is not initialized"
            }
            return
        }

        let url = URL(string: mediaUrl)!
        let playerItem = AVPlayerItem(url: url)
        player.insert(playerItem, after: nil)
        mediaUrls.append(mediaUrl)
        durations.append(0) // Duration will be updated when loaded
    }

    func removeNextItem(mediaUrl: String) {
        guard let player = self.player else {
            logger.warn {
                "ad player is not initialized"
            }
            return
        }

        if let index = mediaUrls.firstIndex(of: mediaUrl) {
            if index < player.items().count {
                let item = player.items()[index]
                player.remove(item)
            }
            mediaUrls.remove(at: index)
            if index < durations.count {
                durations.remove(at: index)
            }
        }
    }
}

