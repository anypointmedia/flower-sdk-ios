import sdk_core

class KotlinException: NSError {
    init(message: String) {
        super.init(
            domain: "tv.anypoint.flower.FlowerSdk",
            code: 1,
            userInfo: [NSLocalizedDescriptionKey: message]
        )
    }

    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
}
