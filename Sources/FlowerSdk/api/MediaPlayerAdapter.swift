import sdk_core

public typealias Media = sdk_core.Media
public typealias PlayItem = sdk_core.PlayItem

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
     * Stops the playback and releases resources.
     */
    func stop() throws

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
     * @param periodIndex Period index for DASH MPD live streams
     */
    func seekToPosition(absoluteStartTimeMs: Double?, relativeStartTimeMs: Double?, offsetMs: Double?, windowDurationMs: Double?, periodIndex: Int32?) throws

    func getCurrentAbsoluteTime(isPrintDetails: Bool) throws -> Double

    func getPlayerType() -> String?

    func getPlayerVersion() -> String?

    /**
     * How many times the player has left a spliced-in timeline and rejoined the main one, counted from
     * the start of playback and never decreasing - in other words, the number of ad breaks played to
     * their end.
     *
     * Only needed by a player that cannot read EXT-X-PROGRAM-DATE-TIME, where the SDK derives the
     * absolute clock from the position this adapter reports. That clock assumes a second of playback is
     * a second of stream timeline, which an ad break breaks: the break takes a different amount of wall
     * time than the origin span it stands in for, and the difference accumulates over a session.
     * Counting the breaks lets the SDK pin the clock back to an instant it knows exactly.
     *
     * Leave it alone for any player that reports PROGRAM-DATE-TIME - the default 0 keeps the SDK from
     * ever re-pinning, which is what those players want.
     */
    func getMainTimelineRejoinCount() -> Int32
}

/// Defaults for the members a host app should not have to think about.
///
/// Every one is `public` on purpose. A default in an internal extension is invisible outside this
/// module, which does not make the member optional for a host app's adapter - it makes it *required*,
/// because the app can see the protocol requirement but not the implementation that satisfies it. That
/// is the opposite of what a default is for.
extension MediaPlayerAdapter {
    public func getPlayerType() -> String? {
        nil
    }

    public func getPlayerVersion() -> String? {
        nil
    }

    public func getMainTimelineRejoinCount() -> Int32 {
        0
    }
}
