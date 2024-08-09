import AVFoundation
import sdk_core

struct HLSManifestForParsing {
    struct HLSSegment {
        let duration: Double
        let url: String
    }

    let segments: [HLSSegment]
}

struct DASHManifestForParsing {
    let periodID: String
}

class AvPlayerAdapterFactory: sdk_core.SdkContainerBeanFactory {
    func create(args: KotlinArray<AnyObject>) -> Any? {
        return AvPlayerAdapter(
            mediaPlayerHook: args.get(index: 0) as! MediaPlayerHook,
            flowerAdsManager: args.get(index: 1) as! FlowerAdsManagerImpl
        )
    }
}

class AvPlayerAdapter: MediaPlayerAdapter {

    private var mediaPlayerHook: MediaPlayerHook!
    private var flowerAdsManager: FlowerAdsManagerImpl!
    private var trackingDelayCounter: Int64 = 0

    init(mediaPlayerHook: MediaPlayerHook, flowerAdsManager: FlowerAdsManagerImpl) {
        self.mediaPlayerHook = mediaPlayerHook
        self.flowerAdsManager = flowerAdsManager
    }


    func getCurrentPosition() -> Int32 {
        if mediaPlayerHook.getPlayer() is AVPlayer {
            return Int32(CMTimeGetSeconds((mediaPlayerHook.getPlayer() as! AVPlayer).currentTime()) * 1000)
        }
        return 0
    }

    func getCurrentMediaChunk() -> MediaChunk {
        return MediaChunk(currentPosition: getCurrentPosition(), url: nil, periodId: nil)
//        guard let avPlayer = mediaPlayerHook.getPlayer() as? AVPlayer else {
//            return CurrentPlayItem(currentPosition: getCurrentPosition(), url: nil, periodId: nil)
//        }
//
//        let currentPosition = CMTimeGetSeconds(avPlayer.currentTime())
//        let currentItem = avPlayer.currentItem
//
//        // TODO: hlsManifest and dashManifest not yet tested.
//        // Note: In Android's Exoplayer finding the mediaPlaylist.segments and currentPeriodIndex is built in, but that is not the case with AVPlayer and needs to be manually calculated
//        if let hlsManifest = currentItem?.asset as? AVURLAsset, hlsManifest.url.absoluteString.lowercased().hasSuffix(".m3u8") {
//            if let hlsManifest = try? String(contentsOf: hlsManifest.url),
//               let hlsPlaylist = parseHLSManifest(hlsManifest) {
//                var accumulatedSegmentDuration: Double = 0
//
//                for segment in hlsPlaylist.segments {
//                    let durationMs = segment.duration / 1000
//
//                    if accumulatedSegmentDuration <= currentPosition && currentPosition <= accumulatedSegmentDuration + durationMs {
//                        return CurrentPlayItem(
//                            currentPosition: Int32(currentPosition - accumulatedSegmentDuration),
//                            url: segment.url,
//                            periodId: nil
//                        )
//                    }
//
//                    accumulatedSegmentDuration += durationMs
//                }
//            }
//        } else if let dashManifest = currentItem?.asset as? AVURLAsset, dashManifest.url.absoluteString.lowercased().hasSuffix(".mpd") {
//            if let dashManifest = try? String(contentsOf: dashManifest.url),
//               let dashPeriodID = parseDASHManifest(dashManifest)?.periodID {
//                return CurrentPlayItem(
//                    currentPosition: Int32(currentPosition),
//                    url: nil,
//                    periodId: dashPeriodID
//                )
//            }
//        }
//
//
//        return CurrentPlayItem(currentPosition: getCurrentPosition(), url: nil, periodId: nil)
    }

    func parseHLSManifest(_ manifest: String) -> HLSManifestForParsing? {
        var segments: [HLSManifestForParsing.HLSSegment] = []

            let lines = manifest.components(separatedBy: .newlines)

            var currentSegmentDuration: Double = 0
            var currentSegmentURL: String?

            for line in lines {
                if line.hasPrefix("#EXTINF:") {
                    // Extract segment duration
                    let durationString = line.replacingOccurrences(of: "#EXTINF:", with: "").components(separatedBy: ",").first ?? "0"
                    currentSegmentDuration = Double(durationString) ?? 0
                } else if line.hasPrefix("http") {
                    // Assume the URL directly follows the #EXTINF line
                    currentSegmentURL = line
                    // Add the completed segment to the list
                    segments.append(HLSManifestForParsing.HLSSegment(duration: currentSegmentDuration, url: currentSegmentURL!))
                    // Reset values for the next segment
                    currentSegmentDuration = 0
                    currentSegmentURL = nil
                }
            }

            return HLSManifestForParsing(segments: segments)
    }

    func parseDASHManifest(_ manifest: String) -> DASHManifestForParsing? {
        let lines = manifest.components(separatedBy: .newlines)

        for line in lines {
            if line.contains("Period id") {
                let components = line.components(separatedBy: "\"")
                if components.count > 1 {
                    return DASHManifestForParsing(periodID: components[1])
                }
            }
        }

        return nil
    }


    func isPlaying() -> Bool {
        var player: AVPlayer {
            mediaPlayerHook.getPlayer() as! AVPlayer
        }
        return player.rate != 0.0
    }

    func getVolume() -> Float {
        var player: AVPlayer {
            mediaPlayerHook.getPlayer() as! AVPlayer
        }
        return player.volume
    }

    func getHeight() -> Int32 {
        var player: AVPlayer {
            mediaPlayerHook.getPlayer() as! AVPlayer
        }
        return Int32(player.currentItem?.presentationSize.height ?? 0)
    }
}
