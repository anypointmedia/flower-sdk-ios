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
//    private let rendererFactory: RenderersFactory
    private var player: AVQueuePlayer?
    private var adPlayerCallbacks = AdPlayerCallbacks()
    private var mediaUrls: [String] = []
    private var stopJob: DispatchWorkItem?
    private var loadJob: DispatchWorkItem?
    private var playStartTime: Int64 = 0
    private var adPlayerView: AdPlayerViewImpl!

    private var durations: [Double] = []

    func load(mediaUrls: PlatformList<NSString>, totalDuration: Int32, adPlayerView: AdPlayerView) {
        let mediaUrls = mediaUrls.array as! [String]
        if mediaUrls.count == 0 {
            logger.warn { "empty mediaUrls" }
            fatalError("empty mediaUrls")
        }
        self.adPlayerView = adPlayerView as? AdPlayerViewImpl
        loadJob?.cancel()
        loadJob = DispatchWorkItem { [weak self] in
            guard let self = self else {return}

            do {
                self.release()

                self.mediaUrls = mediaUrls
                self.totalDuration = totalDuration
                self.durations = []


                let mediaSources = convertMediaSource()
                for source in mediaSources {
                    durations.append(CMTimeGetSeconds(source.asset.duration)*1000)
                }

                // Note: Initialize in this order
                // AVQueuePlayer > AVPlayerLayer > adPlayerView.layer.addSublayer(playerLayer)
                player = AVQueuePlayer(items: mediaSources)

                for item in player!.items() {
                    NotificationCenter.default.addObserver(self, selector: #selector(adPlayerDidFinishPlaying(_:)), name: .AVPlayerItemDidPlayToEndTime, object: item)
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

    func next() {
        guard let player = self.player else {
            stop()
            return
        }

        if player.items().index(of: player.currentItem!)! < player.items().count - 1 {
            player.advanceToNextItem()
        } else {
            stop()
        }
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
        stopJob = DispatchWorkItem { [weak self] in
            guard let self = self else {return}
            do {
                self.adPlayerView.hide()
                player.pause()
                logger.info { "ad player stop" }
                self.release()
                adPlayerCallbacks.onStopped()
            }
        }
        DispatchQueue.main.async(execute: stopJob!)
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
            player = nil
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
        adPlayerCallbacks.onStopped()
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

    @objc func adPlayerDidFinishPlaying(_ notification: Notification) {
        // if player has completed the last ad
        NotificationCenter.default.removeObserver(self, name: .AVPlayerItemDidPlayToEndTime, object: player!.currentItem)
        if player!.items().count == 1 {
            stop()
        }
    }

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
        next()
        return DeferredStubImpl(task: Task { true })
    }
}
