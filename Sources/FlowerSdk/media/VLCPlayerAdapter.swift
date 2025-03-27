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

    private var referenceGuard: Any? = nil

    init(mediaPlayerHook: MediaPlayerHook, flowerAdsManager: FlowerAdsManagerImpl) {
        self.mediaPlayerHook = mediaPlayerHook
        self.flowerAdsManager = flowerAdsManager
    }

    func getCurrentPosition() throws -> KotlinWrapped<KotlinInt> {
        let returnValue = KotlinWrapped(value: KotlinInt(value: try mediaPlayer.time.intValue))
        referenceGuard = returnValue
        return returnValue
    }

    func getCurrentMediaChunk() throws -> any MediaChunkStub {
        guard let media = try mediaPlayer.media else {
            throw KotlinException(message: "No media available")
        }

        let returnValue = MediaChunk(
            currentPosition: try getCurrentPosition().value!.int32Value,
            url: nil,
            periodId: nil
        )
        referenceGuard = returnValue
        return returnValue
    }

    func getCurrentMedia() throws -> Media {
        let player = try mediaPlayer

        guard let media = player.media else {
            throw KotlinException(message: "No media available")
        }

        guard let url = media.url else {
            throw KotlinException(message: "No media URL available")
        }

        let returnValue = Media(
            url: url.absoluteString,
            duration: media.length.intValue,
            position: player.time.intValue
        )
        referenceGuard = returnValue
        return returnValue
    }

    func getVolume() throws -> KotlinWrapped<KotlinFloat> {
        let returnValue = KotlinWrapped(value: KotlinFloat(value: AVAudioSession.sharedInstance().outputVolume))
        referenceGuard = returnValue
        return returnValue
    }

    func getHeight_() throws -> KotlinWrapped<KotlinInt> {
        let returnValue = KotlinWrapped(value: KotlinInt(value: Int32(try mediaPlayer.videoSize.height)))
        referenceGuard = returnValue
        return returnValue
    }

    func isPlaying() throws -> KotlinWrapped<KotlinBoolean> {
        let returnValue = KotlinWrapped(value: KotlinBoolean(value: try mediaPlayer.isPlaying))
        referenceGuard = returnValue
        return returnValue
    }

    func pause_() throws {
        fatalError("Not implemented")
    }

    func resume_() throws {
        fatalError("Not implemented")
    }

    func enqueue(mediaPlayerItem: MediaPlayerItem) throws {
        let media = VLCMedia(url: URL(string: mediaPlayerItem.url)!)
        var commonMediaOptions: [String:Any] = [
            "file-caching": 1500,
            "network-caching": 1500,
            "live-caching": 1500,
            "clock-jitter": 0,
            "clock-synchro": 0,
            "network-timeout": 10000,
        ]

        if (mediaPlayerItem.isAd) {
            commonMediaOptions["adaptive-logic"] = "rate"
        } else {
            commonMediaOptions["adaptive-logic"] = "highest"
        }

        media.addOptions(commonMediaOptions)

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
