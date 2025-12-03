public protocol FlowerAdConfig {}

public final class FlowerLinearTvAdConfig: FlowerAdConfig {
    public let adTagUrl: String
    public let prerollAdTagUrl: String?
    public let channelId: String
    public let extraParams: [String: String]?
    public let adTagHeaders: [String: String]?
    public let channelStreamHeaders: [String: String]?

    /// - Parameters:
    ///   - adTagUrl: url from flower system. You must file a request to Anypoint Media to receive an adTagUrl.
    ///   - prerollAdTagUrl: url for linear tv preroll ads from flower system.
    ///   - channelId: unique channel id in your service.
    ///   - extraParams: values you can provide for targeting.
    ///   - adTagHeaders: values included in headers for ad request.
    ///   - channelStreamHeaders: values included in headers for channel stream request.
    public init(
        adTagUrl: String,
        prerollAdTagUrl: String? = nil,
        channelId: String,
        extraParams: [String: String]? = nil,
        adTagHeaders: [String: String]? = nil,
        channelStreamHeaders: [String: String]? = nil
    ) {
        self.adTagUrl = adTagUrl
        self.prerollAdTagUrl = prerollAdTagUrl
        self.channelId = channelId
        self.extraParams = extraParams
        self.adTagHeaders = adTagHeaders
        self.channelStreamHeaders = channelStreamHeaders
    }
}

public final class FlowerVodAdConfig: FlowerAdConfig {
    public let adTagUrl: String
    public let contentId: String
    public let contentDuration: Int64
    public let extraParams: [String: String]?
    public let adTagHeaders: [String: String]?
    public let requestTimeout: Int64?
    public let minPrepareDuration: Int64?
    public let rewindDuration: Int64?

    public init(
        adTagUrl: String,
        contentId: String,
        contentDuration: Int64,
        extraParams: [String: String]? = nil,
        adTagHeaders: [String: String]? = nil,
        requestTimeout: Int64? = nil,
        minPrepareDuration: Int64? = nil,
        rewindDuration: Int64? = nil
    ) {
        self.adTagUrl = adTagUrl
        self.contentId = contentId
        self.contentDuration = contentDuration
        self.extraParams = extraParams
        self.adTagHeaders = adTagHeaders
        self.requestTimeout = requestTimeout
        self.minPrepareDuration = minPrepareDuration
        self.rewindDuration = rewindDuration
    }
}
