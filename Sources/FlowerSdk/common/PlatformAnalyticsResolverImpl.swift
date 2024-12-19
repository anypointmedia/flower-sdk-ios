import Foundation
import sdk_core

class PlatformAnalyticsResolverImpl: sdk_core.PlatformAnalyticsResolver {
    func resolve() -> PlatformAnalytics {
        PlatformAnalytics(
            sdkVersion: Bundle.main.infoDictionary?["CFBundleShortVersionString"] as? String ?? ""
        )
    }
}
