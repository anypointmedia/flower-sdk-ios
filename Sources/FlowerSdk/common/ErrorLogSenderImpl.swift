import Foundation
import sdk_core

class ErrorLogSenderImpl: sdk_core.ErrorLogSender {
    
    func resolvePlatformFields() -> ErrorLogPlatformFields {
        ErrorLogPlatformFields(
                sdkType: "iOS",
                sdkVersion: Bundle.main.infoDictionary?["CFBundleShortVersionString"] as? String ?? "",
                stackTrace: Thread.callStackSymbols.joined(separator: "\n")
        )
    }
}

struct ErrorLogPlatformFields {
    let sdkType: String
    let sdkVersion: String
    let stackTrace: String?
    
    init(sdkType: String, sdkVersion: String, stackTrace: String? = nil) {
        self.sdkType = sdkType
        self.sdkVersion = sdkVersion
        self.stackTrace = stackTrace
    }
}
