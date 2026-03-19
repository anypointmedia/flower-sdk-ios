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

    func stop_() throws {
        try platformMediaPlayerAdapter.stop()
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

    func seekToPosition(absoluteStartTimeMs: KotlinWrapped<KotlinDouble>?, relativeStartTimeMs: KotlinWrapped<KotlinDouble>?, offsetMs: KotlinWrapped<KotlinDouble>?, windowDurationMs: KotlinWrapped<KotlinDouble>?, periodIndex: KotlinInt?) throws {
        var absTime: Double? = nil
        var relTime: Double? = nil
        var offset: Double? = nil
        var windowDur: Double? = nil

        if let wrapped = absoluteStartTimeMs, let kotlinDouble = wrapped.value {
            absTime = Double(kotlinDouble)
        }
        if let wrapped = relativeStartTimeMs, let kotlinDouble = wrapped.value {
            relTime = Double(kotlinDouble)
        }
        if let wrapped = offsetMs, let kotlinDouble = wrapped.value {
            offset = Double(kotlinDouble)
        }
        if let wrapped = windowDurationMs, let kotlinDouble = wrapped.value {
            windowDur = Double(kotlinDouble)
        }

        try platformMediaPlayerAdapter.seekToPosition(
            absoluteStartTimeMs: absTime,
            relativeStartTimeMs: relTime,
            offsetMs: offset,
            windowDurationMs: windowDur,
            periodIndex: periodIndex != nil ? Int32(truncating: periodIndex!) : nil
        )
    }

    func getCurrentAbsoluteTime(isPrintDetails: Bool) throws -> KotlinWrapped<KotlinDouble> {
        return KotlinWrapped(value: KotlinDouble(value: try platformMediaPlayerAdapter.getCurrentAbsoluteTime(isPrintDetails: isPrintDetails)))
    }

    func getPlayerType() -> String? {
        return platformMediaPlayerAdapter.getPlayerType()
    }

    func getPlayerVersion() -> String? {
        return platformMediaPlayerAdapter.getPlayerVersion()
    }
}

