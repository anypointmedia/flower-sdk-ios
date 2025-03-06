import sdk_core

class MediaPlayerHookException: KotlinException {
    init(expected: String, actual: String) {
        super.init(message: "MediaPlayerHook did not return valid player. Expected \(expected) but received \(actual).")
    }

    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
}
