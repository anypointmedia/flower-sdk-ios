import sdk_core

func Throwable(message: String? = nil) -> NSError {
    NSError(
        domain: "tv.anypoint.flower.FlowerSdk",
        code: 1,
        userInfo: [NSLocalizedDescriptionKey: message]
    )
}
