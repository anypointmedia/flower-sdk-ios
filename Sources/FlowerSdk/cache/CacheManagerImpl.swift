import Foundation
import sdk_core
import SwiftUI
import OSLog

// TODO: Make sure to test if any usage of core functionalities and if files are reading/writing as expected
class CacheManagerImpl: sdk_core.CacheManager {
    var rootDir: URL?
    lazy var httpClient: Ktor_client_coreHttpClient = SdkContainer.Companion().getInstance().httpClient
    var logger = sdk_core.LoggingKmLog()

    class CacheManagerImplCompanion {
        static let isCachable = true
        static let isContentCachable = false
        static let rootDir = "_r"
        static let minFreeSize = 500 * 1024 * 1024 // 500MB
        static let maxCacheSize = 200 * 1024 * 1024 // 200MB
    }

    init(appContext: Any) {
        do {
            // Get the URL to the app's cache directory
            rootDir = try FileManager.default.url(for: .cachesDirectory, in: .userDomainMask, appropriateFor: nil, create: true)
            logger.info { "CacheManager: cacheDir: \(String(describing: self.rootDir))"}
            // You can append additional path components if needed
            // For example: cacheDirectoryURL.appendingPathComponent("yourSubdirectory")
        } catch {
            // Handle the error, if any
            logger.error { "Error getting cache directory: \(error)" }
        }
    }

    func loadData(key: String, url: String) -> DeferredStub {
        return DeferredStubImpl(
            task: Task {
                logger.verbose { "loadData - key: \(key), url: \(url)"}
                let hash = url.hashValue
                let cacheFileURL = self.rootDir!.appendingPathComponent("\(key)/\(hash)")

                if CacheManagerImpl.CacheManagerImplCompanion.isCachable, FileManager.default.fileExists(atPath: cacheFileURL.path) {
                    do {
                        try FileManager.default.setAttributes([.modificationDate: Date()], ofItemAtPath: cacheFileURL.path)
                        logger.verbose { "read from cache - url: \(url)" }
                        let cachedContent = try String(contentsOf: cacheFileURL, encoding: .utf8)
                        return cachedContent
                    } catch {
                        // TODO: Handle error reading or updating cache file
                        logger.error { "CacheManager: Error reading or updating cache file \(error)" }
                    }
                } else if CacheManagerImpl.CacheManagerImplCompanion.isCachable && !(FileManager.default.fileExists(atPath: cacheFileURL.path)) {
                    // Create directory and file
                    do {
                        let newDir = self.rootDir!.appendingPathComponent("\(key)") // Leave out hash because hash is the file not directory
                        try FileManager.default.createDirectory(atPath: newDir.path, withIntermediateDirectories: true, attributes: nil)
                    } catch {
                        logger.error { "CacheManager: Error \(error)" }
                    }
                }

                let requestBuilder = Ktor_client_coreHttpRequestBuilder()
                requestBuilder.ios_url(urlString: url)
                let response = try await httpClient.ios_request(builder: requestBuilder)

                if !(200...299).contains(response.status.value) {
                    throw NSError(domain: "FlowerSdk", code: 1, userInfo: ["message": "failed to get response body: \(url)"])
                }

                let body = try await response.ios_bodyAsUtf8Text()
                if CacheManagerImpl.CacheManagerImplCompanion.isCachable, makeRoom(size: body.count) {
                    logger.verbose { "CacheManager: write to cache - url: \(url)" }
                    do {
                        // atmoically set to false since write is called multiple times in a row which will throw write error
                        try body.write(to: cacheFileURL, atomically: false, encoding: .utf8)
                    } catch {
                        // TODO: Handle error
                        logger.error { "CacheManager: Error writing to cacheFileURL: \(error)" }
                    }
                }
                return body
            }
        )
    }

    func makeRoom(size: Int) -> Bool {
        // Get the file system attributes for the volume containing the root directory
        var freeSize: Int
        var usedSize: Int
        do {
            let systemAttributes = try FileManager.default.attributesOfFileSystem(forPath: rootDir!.path)
            freeSize = (systemAttributes[.systemFreeSize] as? NSNumber)!.intValue
            usedSize = (Int(calculateDirectorySize(atPath: rootDir!.path) ?? 0)) as Int
        } catch {
            return false
        }

        guard var cacheFiles = try? FileManager.default.contentsOfDirectory(at: rootDir!, includingPropertiesForKeys: [.contentModificationDateKey], options: .skipsHiddenFiles).sorted(by: { (url1, url2) -> Bool in
            do {
                let date1 = try url1.resourceValues(forKeys: [.contentModificationDateKey]).contentModificationDate
                let date2 = try url2.resourceValues(forKeys: [.contentModificationDateKey]).contentModificationDate
                return date1 ?? Date() < date2 ?? Date()
            } catch {
                return false
            }
        }).makeIterator() else {
            return false
        }

        while freeSize - size < CacheManagerImpl.CacheManagerImplCompanion.minFreeSize || usedSize + size > CacheManagerImpl.CacheManagerImplCompanion.maxCacheSize {
            let oldFileUrl = cacheFiles.next()
            if oldFileUrl != nil {
                do {
                    let oldFileSize = try oldFileUrl!.resourceValues(forKeys: [.fileSizeKey]).fileSize ?? 0
                    freeSize += oldFileSize
                    try FileManager.default.removeItem(at: oldFileUrl!)
                } catch {
                    // TODO: Handle error deleting old file
                    logger.error { "CacheManager: makeRoom Error deleting old file: \(error)" }
                }
            } else {
                logger.debug { "CacheManager: can't cache - cache size: \(size), freeSize: \(freeSize), usedSize: \(usedSize)" }
                return false
            }
        }

        logger.verbose { "CacheManager: can cache - cache size: \(size), freeSize: \(freeSize), usedSize: \(usedSize)" }
        return true
    }

    // Recursively do a deep check of all of the files at path to calculate size of the directory
    // Note: Only call calculateDirectorySize after having checked that the directory already exists.
    func calculateDirectorySize(atPath path: String) -> Int64? {
        do {
            var totalSize: Int64 = 0
            let contents = try FileManager.default.contentsOfDirectory(atPath: path)

            for content in contents {
                let contentPath = (path as NSString).appendingPathComponent(content)
                if let attributes = try? FileManager.default.attributesOfItem(atPath: contentPath) {
                    if let fileSize = attributes[.size] as? Int64 {
                        totalSize += fileSize
                    }
                } else if let subdirectorySize = calculateDirectorySize(atPath: contentPath) {
                    totalSize += subdirectorySize
                }
            }

            return totalSize
        } catch {
            // Handle error
            logger.error { "CacheManager: Error calculating directory size: \(error)" }
            return nil
        }
    }

    func loadStream(originalUrl: String, requestBuilder: Ktor_client_coreHttpRequestBuilder) -> DeferredStub {
        return DeferredStubImpl(
            task: Task {
                let key = originalUrl.hashValue
                let cacheDir = self.rootDir!.appendingPathComponent("_c/\(key)")
                let dataFile = cacheDir.appendingPathComponent("data")

                if CacheManagerImpl.CacheManagerImplCompanion.isCachable, CacheManagerImpl.CacheManagerImplCompanion.isContentCachable, FileManager.default.fileExists(atPath: cacheDir.path) {
                    logger.verbose { "CacheManager: load from cache - key: \(key), url: \(requestBuilder.url)" }

                    let headersFileURL = cacheDir.appendingPathComponent("headers")

                    // Read headers from file
                    var headers: [AnyHashable: Any] = [:]
                    if let headersData = try? Data(contentsOf: headersFileURL),
                       let unarchivedHeaders = try? NSKeyedUnarchiver.unarchiveTopLevelObjectWithData(headersData) as? [AnyHashable: Any] {
                        headers = unarchivedHeaders
                    }

                    // Build Headers instance
//                    var headersInstance: Ktor_httpHeaders = [:] as! Ktor_httpHeaders
                    let headersInstance: [String: [String]] = [:]
                    headers.forEach { (key, value) in
                        if let values = value as? [String] {
                            headersInstance[key as! String, default: values]
                        }
                    }

                    sdk_core.StreamCacheResponse(
                        originalUrl: originalUrl,
                        statusCode: Ktor_httpHttpStatusCode(value: 200, description: "OK"),
                        headers: headersInstance as! any Ktor_httpHeaders,
                        data: InputStream(url: dataFile) as! any Ktor_ioByteReadChannel
                    )
                }

                let response = try await httpClient.ios_request(builder: requestBuilder) as Ktor_client_coreHttpResponse

                if !(200...299).contains(response.status.value) {
                    throw NSError(domain: "FlowerSdk", code: 1, userInfo: ["message": "Invalid status code: \(response.status.value)"])
                }

                // TODO: Check if availableForRead is the same as .contentLength!
                let cacheAvailable = CacheManagerImpl.CacheManagerImplCompanion.isCachable && CacheManagerImpl.CacheManagerImplCompanion.isContentCachable && makeRoom(size: Int(response.content.availableForRead ))

                let headers: [AnyHashable: Any] = [:]
                if cacheAvailable {
                    do {
                        let headersData = try NSKeyedArchiver.archivedData(withRootObject: headers, requiringSecureCoding: false)
                        try headersData.write(to: cacheDir.appendingPathComponent("headers"))
                    } catch {
                        // TODO: Handle error with header
                        logger.error { "Error with header handler: \(error)" }
                    }
                }

                var responseStream: InputStream
                if cacheAvailable {
                    let cacheInputStream = try await CacheInputStream(
                        sourceInputStream: InputStream(data: response.ios_bodyAsChannel() as! Data),
                        cacheFile: dataFile
                    )
                    responseStream = cacheInputStream
                } else {
                    responseStream = try await InputStream(data: response.ios_bodyAsChannel() as! Data)
                }
                var buffer = [UInt8](repeating: 0, count: 1024)
                return StreamCacheResponse(
                    originalUrl: originalUrl,
                    statusCode: response.status,
                    headers: headers as! Ktor_httpHeaders,
                    data: responseStream.toByteReadChannel() as! Ktor_ioByteReadChannel
                )
            }
        )
    }
}
