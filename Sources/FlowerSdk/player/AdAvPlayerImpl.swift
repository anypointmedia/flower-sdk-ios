import Foundation
import AVKit
import AVFoundation
import SwiftUI
import sdk_core

class AdAvPlayerImpl: AdPlayer {
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

    init(player: AVPlayer? = nil) {
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
            guard let self = self else { return }

            do {
                if let existingPlayer = self.player,
                   let currentItem = existingPlayer.currentItem,
                   let urlAsset = currentItem.asset as? AVURLAsset {
                    self.originalMediaUrls = [urlAsset.url.absoluteString]
                    self.originalPosition = CMTimeGetSeconds(existingPlayer.currentTime()) * 1000
                    self.logger.info { "saved original from player: url=\(urlAsset.url.absoluteString), position=\(self.originalPosition)" }
                }

                self.release()

                self.adCount = mediaUrls.count
                self.mediaUrls = mediaUrls + self.originalMediaUrls
                self.totalDuration = totalDuration
                self.durations = []
                self.currentIndex = 0

                let playerItems = self.convertMediaSource()
                for item in playerItems {
                    self.durations.append(CMTimeGetSeconds(item.asset.duration) * 1000)
                }

                guard let firstItem = playerItems.first else { return }
                if let externalPlayer = self.externalPlayer {
                    // Reuse external player
                    self.logger.info { "Reusing external player (externalPlayer provided)" }
                    externalPlayer.replaceCurrentItem(with: firstItem)
                    self.player = externalPlayer
                } else {
                    self.logger.info { "Creating new AVPlayer (no externalPlayer)" }
                    self.player = AVPlayer(playerItem: firstItem)
                }

                NotificationCenter.default.addObserver(
                    self,
                    selector: #selector(self.adPlayerDidFinishPlaying(_:)),
                    name: .AVPlayerItemDidPlayToEndTime,
                    object: firstItem
                )

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
            return DeferredStubImpl(task: Task { AdProgress.companion.NOT_READY })
        }

        let playTime: Double = player.currentTime().seconds * 1000

        if currentIndex >= mediaUrls.count {
            return DeferredStubImpl(task: Task { AdProgress.companion.NOT_READY })
        }

        return DeferredStubImpl(task: Task { AdProgress(currentTime: Int32(exactly: playTime.rounded()) ?? 0, duration: Int32(self.durations[self.currentIndex])) })
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
                        self?.player?.play()
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
        return DeferredStubImpl(task: Task { KotlinBoolean(value: await self.player?.rate == 0.0) })
    }

    func playNextItem_() -> any DeferredStub {
        guard let player = self.player else {
            return DeferredStubImpl(task: Task { KotlinBoolean(value: false) })
        }

        if currentIndex < mediaUrls.count - 1 {
            let nextIndex = currentIndex + 1
            playItem(at: nextIndex)
            return DeferredStubImpl(task: Task { KotlinBoolean(value: true) })
        } else {
            logger.info { "No more media items to play" }
            return DeferredStubImpl(task: Task { KotlinBoolean(value: false) })
        }
    }

    func seekTo(offsetMs: Double) {
        guard let player = self.player else { return }
        let seconds = offsetMs / 1000.0
        let time = CMTime(seconds: seconds, preferredTimescale: CMTimeScale(NSEC_PER_SEC))
        player.seek(to: time)
    }

    func enqueueNextItem(mediaUrl: String) {
        mediaUrls.append(mediaUrl)
        durations.append(0)
    }

    func removeNextItem(mediaUrl: String) {
        if let index = mediaUrls.firstIndex(of: mediaUrl) {
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
