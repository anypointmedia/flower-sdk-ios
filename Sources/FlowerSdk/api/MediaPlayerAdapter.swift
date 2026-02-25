import sdk_core

public typealias Media = sdk_core.Media

public protocol MediaPlayerAdapter {
    /**
     * Returns current playing media.
     */
    func getCurrentMedia() throws -> Media

    /**
     * Returns the audio volume that is between 0.0 and 1.0.
     */
    func getVolume() throws -> Float

    /**
     * Returns whether the player is playing.
     */
    func isPlaying() throws -> Bool

    /**
     * Returns the height of the video in pixels, or 0 if unknown or not applicable.
     */
    func getHeight() throws -> Int32

    /**
     * Pauses the playback.
     */
    func pause() throws

    /**
     * Resumes the playback.
     */
    func resume() throws

    /**
     * Enqueues new play item to the player.
     */
    func enqueuePlayItem(playItem: PlayItem) throws

    func removePlayItem(playItem: PlayItem) throws

    /**
     * Seeks to the next media item in the queue.
     */
    func playNextItem() throws

    /**
     * Seeks to the specified position using available time values.
     * @param absoluteStartTimeMs Absolute time in milliseconds
     * @param relativeStartTimeMs relative time from the first window in milliseconds
     * @param offsetMs Offset within the current window in milliseconds
     * @param windowDurationMs Total length of the current window in milliseconds
     */
    func seekToPosition(absoluteStartTimeMs: Double?, relativeStartTimeMs: Double?, offsetMs: Double?, windowDurationMs: Double?) throws

    func getCurrentAbsoluteTime(isPrintDetails: Bool) throws -> Double
}
