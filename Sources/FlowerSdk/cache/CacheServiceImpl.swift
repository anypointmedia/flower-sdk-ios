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

    override init() {
        super.init()

        try? FileManager.default.createDirectory(
            at: (cacheDir as! PlatformFileImpl).fileURL,
            withIntermediateDirectories: true,
            attributes: nil
        )
        logger.info { "CacheService: Using cache dir: \((self.cacheDir as! PlatformFileImpl).path)" }

        try? listTempFiles().forEach { file in
            try file.delete()
        }
    }

    override func getFreeStorageSize() throws -> KotlinWrapped<KotlinLong> {
        guard let systemAttributes = try? FileManager.default.attributesOfFileSystem(forPath: (cacheDir as! PlatformFileImpl).path),
              let freeSize = systemAttributes[.systemFreeSize] as? NSNumber else {
            return KotlinWrapped(value: KotlinLong(0))
        }

        return KotlinWrapped(value: KotlinLong(value: Int64(freeSize.int64Value)))
    }
}
