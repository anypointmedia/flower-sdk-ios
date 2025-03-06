import Foundation
import sdk_core

class CacheServiceImpl: CacheService {
    private var logger: Logger_ {
        Companion().logger
    }

    override var cacheDir: any PlatformFile {
        PlatformFileImpl(
            fileURL: FileManager.default.urls(for: .cachesDirectory, in: .userDomainMask).first!
                .appendingPathComponent(CacheService.companion.ROOT_DIR)
        )
    }

    override var fileSaveQueue: ConcurrentQueue {
        ConcurrentQueue()
    }

    override init() {
        super.init()

        try? FileManager.default.createDirectory(
            at: (cacheDir as! PlatformFileImpl).fileURL,
            withIntermediateDirectories: true,
            attributes: nil
        )
        logger.info { "CacheService: Using cache dir: \(self.cacheDir.path)" }

        try? listTempFiles().forEach { file in
            try file.delete()
        }
    }

    override func getFreeStorageSize() -> Int64 {
        guard let systemAttributes = try? FileManager.default.attributesOfFileSystem(forPath: cacheDir.path),
              let freeSize = systemAttributes[.systemFreeSize] as? NSNumber else {
            return 0
        }

        return freeSize.int64Value
    }
}
