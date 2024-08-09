import Foundation
import sdk_core

class ErrorLogSenderImpl: sdk_core.ErrorLogSender {
    
    func resolvePlatformFields() -> ErrorLogPlatformFields {
        ErrorLogPlatformFields(
                sdkType: "iOS",
                sdkVersion: Bundle.main.infoDictionary?["CFBundleShortVersionString"] as? String ?? ""
        )
    }
}

struct ErrorLogPlatformFields {
    let sdkType: String
    let sdkVersion: String

    init(sdkType: String, sdkVersion: String) {
        self.sdkType = sdkType
        self.sdkVersion = sdkVersion
    }
}
