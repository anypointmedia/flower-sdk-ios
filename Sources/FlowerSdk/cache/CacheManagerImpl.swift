import Foundation
import core
import SwiftUI

// TODO: Implement class CacheManagerImpl(private val context: Context): CacheManager {
//class CacheManagerImpl: core.CacheManager {
class CacheManagerImpl: CacheManager {
    var rootDir: URL?
    lazy var httpClient: Ktor_client_coreHttpClient = SdkContainer.Companion().getInstance().httpClient
    var logger = core.LoggingKmLog()

    init(appContext: Any) {
        do {
            // Get the URL to the app's cache directory
            rootDir = try FileManager.default.url(for: .cachesDirectory, in: .userDomainMask, appropriateFor: nil, create: true)

            // You can append additional path components if needed
            // For example: cacheDirectoryURL.appendingPathComponent("yourSubdirectory")
        } catch {
            // Handle the error, if any
            print("Error getting cache directory: \(error)")
        }
    }

    func loadData(key: String, url: String) -> CommonJob {
        return CommonJobImpl(
                originalJob: Task {
                    logger.verbose {
                        "loadData - key: $key, url: $url"
                    }
                    let requestBuilder = Ktor_client_coreHttpRequestBuilder()
                    requestBuilder.ios_url(urlString: url)
                    let response = try await httpClient.ios_request(builder: requestBuilder)

                    if (response.status.value < 200 || response.status.value >= 300) {
                        throw NSError(domain: "FlowerSdk", code: 1, userInfo: ["message": "failed to get response body: \(url)"])
                    }

                    return try await response.ios_bodyAsUtf8Text()
                    // TODO caching
                }
        )
    }

    // TODO: Implement loadStream
    func loadStream(originalUrl: String, requestBuilder: Ktor_client_coreHttpRequestBuilder) -> CommonJob {
        return CommonJobImpl(
                originalJob: Task {
                    let key = originalUrl.hash
                    var originalResponse = try await httpClient.ios_request(builder: requestBuilder)

                    if (originalResponse.status.value < 200 || originalResponse.status.value >= 300) {
                        throw NSError(domain: "FlowerSdk", code: 1, userInfo: ["message": "Invalid status code: \(originalResponse.status.value)"])
                    }

                    return StreamCacheResponse(
                            originalUrl: originalUrl,
                            statusCode: originalResponse.status,
                            headers: originalResponse.headers,
                            data: try await originalResponse.ios_bodyAsChannel()
                    )
                }
        )
    }

    func getCacheDirectory() -> URL? {
        do {
            // Get the URL to the app's cache directory
            let cacheDirectoryURL = try FileManager.default.url(for: .cachesDirectory, in: .userDomainMask, appropriateFor: nil, create: true)

            // You can append additional path components if needed
            // For example: cacheDirectoryURL.appendingPathComponent("yourSubdirectory")

            return cacheDirectoryURL
        } catch {
            // Handle the error, if any
            print("Error getting cache directory: \(error)")
            return nil
        }
    }

}
