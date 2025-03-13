#if canImport(MobileVLCKit)
import AVFoundation
import sdk_core
import MobileVLCKit

class VLCPlayerAdapter: MediaPlayerAdapter {
    private var mediaPlayerHook: MediaPlayerHook
    private var flowerAdsManager: FlowerAdsManagerImpl

    private var vlcMedias: [VLCMedia] = []

    private var mediaPlayer: VLCMediaPlayer {
        get throws {
            let player = mediaPlayerHook.getPlayer()

            if let mediaPlayer = player as? VLCMediaPlayer {
                return mediaPlayer
            }

            if let mediaListPlayer = player as? VLCMediaListPlayer {
                return mediaListPlayer.mediaPlayer
            }

            throw MediaPlayerHookException(expected: "VLCMediaPlayer or VLCMediaListPlayer", actual: player == nil ? "nil" : String(describing: type(of: player!)))
        }
    }

    init(mediaPlayerHook: MediaPlayerHook, flowerAdsManager: FlowerAdsManagerImpl) {
        self.mediaPlayerHook = mediaPlayerHook
        self.flowerAdsManager = flowerAdsManager
    }

    func getCurrentPosition() throws -> KotlinWrapped<KotlinInt> {
        KotlinWrapped(value: KotlinInt(value: try mediaPlayer.time.intValue))
    }

    func getCurrentMediaChunk() throws -> any MediaChunkStub {
        guard let media = try mediaPlayer.media else {
            throw KotlinException(message: "No media available")
        }

        return MediaChunk(
            currentPosition: try getCurrentPosition().value!.int32Value,
            url: nil,
            periodId: nil
        )
    }

    func getCurrentMedia() throws -> Media {
        guard let media = try mediaPlayer.media else {
            throw KotlinException(message: "No media available")
        }

        return Media(
            url: media.url!.absoluteString,
            duration: media.length.intValue,
            position: try mediaPlayer.time.intValue
        )
    }

    func getVolume() throws -> KotlinWrapped<KotlinFloat> {
        KotlinWrapped(value: KotlinFloat(value: AVAudioSession.sharedInstance().outputVolume))
    }

    func getHeight_() throws -> KotlinWrapped<KotlinInt> {
        KotlinWrapped(value: KotlinInt(value: Int32(try mediaPlayer.videoSize.height)))
    }

    func isPlaying() throws -> KotlinWrapped<KotlinBoolean> {
        KotlinWrapped(value: KotlinBoolean(value: try mediaPlayer.isPlaying))
    }

    func pause_() throws {
        fatalError("Not implemented")
    }

    func resume_() throws {
        fatalError("Not implemented")
    }

    func enqueue(mediaPlayerItem: MediaPlayerItem) throws {
        let media = VLCMedia(url: URL(string: mediaPlayerItem.url)!)
        media.addOptions([
            "file-caching": 1500,
            "network-caching": 1500,
            "live-caching": 1500,
            "clock-jitter": 0,
            "clock-synchro": 0,
            "adaptive-logic": "highest"
        ])

        media.parse(options: [ .fetchLocal, .parseNetwork, .fetchNetwork ])

        if let mediaListPlayer = self.mediaPlayerHook.getPlayer() as? VLCMediaListPlayer {
            DispatchQueue.main.async {
                mediaListPlayer.mediaList!.add(media)
            }
        } else {
            let mediaPlayer = try self.mediaPlayer
            DispatchQueue.main.async {
                mediaPlayer.media = media
            }
        }
    }
}
#endif
