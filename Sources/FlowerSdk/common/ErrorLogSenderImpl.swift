import Foundation
import core

class ErrorLogSenderImpl : core.ErrorLogSender {
    var sdkContainer: SdkContainer
//    var httpClient
    var deviceService: DeviceService
    
    public init() {
        sdkContainer = core.SdkContainer()
        deviceService = sdkContainer.deviceService
    }
    
    func log(errorLog: ErrorLog) {
        if (sdkContainer.env == "local"){
            return
        }
        
        return

        // TODO: Implement
        //        try {
        //            setRequiredFields(errorLog)
        //
        //            httpClient.newCall(
        //                Request.Builder()
        //                    .url("$S3_BUCKET_HOST/${resolveS3Path(errorLog)}")
        //                    .put(
        //                        RequestBody.create(
        //                            "application/json".mediaType(),
        //                            gson.toJson(errorLog)
        //                        )
        //                    )
        //                    .build()
        //            ).enqueue(object : Callback {
        //                override fun onFailure(call: Call, e: IOException) {
        //                    logger.warn { "failed to send log - ${e.message}" }
        //                }
        //
        //                override fun onResponse(call: Call, response: Response) {
        //                    response.close()
        //                }
        //            })
        //        } catch (e: Exception) {
        //            logger.warn { "failed to send log - ${e.message}" }
        //        }
    }
    
    func setRequiredFields(errorLog: ErrorLog) {
        var calendar = Calendar.current
        calendar.timeZone = TimeZone(abbreviation: "UTC")!

        errorLog.timestamp = KotlinLong(value: Int64(calendar.date(bySettingHour: 0, minute: 0, second: 0, of: Date())!.timeIntervalSince1970 * 1000)) // In millis
        errorLog.sdkType = "iOS"
        errorLog.sdkVersion = Bundle.main.infoDictionary?["CFBundleShortVersionString"] as? String ?? ""
        errorLog.firmwareVersion = deviceService.getFwVer()
        errorLog.deviceModel = deviceService.getModel()
        errorLog.userAgent = ""
        errorLog.stackTrace = errorLog.stackTrace ?? Thread.callStackSymbols.joined(separator: "\n")
    }
    
    private func resolveS3Path(errorLog: ErrorLog) -> String {
        var calendar = Calendar(identifier: .gregorian)
        calendar.timeZone = TimeZone(identifier: "UTC")!

        guard let timestamp = errorLog.timestamp else {
            // TODO: Handle case when timestamp is nil
            return ""
        }

        let date = Date(timeIntervalSince1970: TimeInterval(truncating: timestamp) / 1000)
        let components = calendar.dateComponents([.year, .month, .day], from: date)

        let env = sdkContainer.env
        guard let year = components.year, let month = components.month, let day = components.day else {
            // TODO: Handle the case when year, month, or day is nil
            return ""
        }

        return "env=\(env)/year=\(year)/month=\(month)/day=\(day)/\(timestamp).json"
    }
    
}
