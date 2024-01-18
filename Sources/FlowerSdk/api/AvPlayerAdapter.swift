import Foundation
import AVKit
import core

class AvPlayerAdapter: MediaPlayerAdapter {
    private var mediaPlayerHook: MediaPlayerHook!;
    private var player: AVPlayer {
        mediaPlayerHook.getPlayer() as! AVPlayer
    }

    func doInit(mediaPlayerHook: MediaPlayerHook) {
        self.mediaPlayerHook = mediaPlayerHook;
    }

    func getCurrentPlayItem() -> CurrentPlayItem {
        return CurrentPlayItem(currentPosition: getCurrentPosition(), url: nil, periodId: nil)
    }

    func getCurrentPosition() -> Int32 {
        Int32(CMTimeGetSeconds(player.currentTime()) * 1000)
    }

    func getVolume() -> Float {
        player.volume
    }
}
