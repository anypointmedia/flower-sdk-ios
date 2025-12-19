import sdk_core

class MediaPlayerAdapterWrapper: CoreMediaPlayerAdapter {
    private let platformMediaPlayerAdapter: MediaPlayerAdapter

    init(platformMediaPlayerAdapter: MediaPlayerAdapter) {
        self.platformMediaPlayerAdapter = platformMediaPlayerAdapter
    }

    func getCurrentMedia() throws -> Media {
        try platformMediaPlayerAdapter.getCurrentMedia()
    }

    func getVolume() throws -> KotlinWrapped<KotlinFloat> {
        KotlinWrapped(value: KotlinFloat(value: try platformMediaPlayerAdapter.getVolume()))
    }

    func isPlaying() throws -> KotlinWrapped<KotlinBoolean> {
        KotlinWrapped(value: KotlinBoolean(value: try platformMediaPlayerAdapter.isPlaying()))
    }

    func getHeight() throws -> KotlinWrapped<KotlinInt> {
        KotlinWrapped(value: KotlinInt(value: try platformMediaPlayerAdapter.getHeight()))
    }

    func pause_() throws {
        try platformMediaPlayerAdapter.pause()
    }

    func resume_() throws {
        try platformMediaPlayerAdapter.resume()
    }

    func enqueuePlayItem(playItem: PlayItem) throws {
        try platformMediaPlayerAdapter.enqueuePlayItem(playItem: playItem)
    }

    func removePlayItem(playItem: PlayItem) throws {
        try platformMediaPlayerAdapter.removePlayItem(playItem: playItem)
    }

    func playNextItem() throws {
        try platformMediaPlayerAdapter.playNextItem()
    }

    func bitmovinPlayerCurrentTime() -> KotlinDouble? {
        if let time = platformMediaPlayerAdapter.bitmovinPlayerCurrentTime() {
            return KotlinDouble(value: time)
        } else {
            return nil
        }
    }
}
