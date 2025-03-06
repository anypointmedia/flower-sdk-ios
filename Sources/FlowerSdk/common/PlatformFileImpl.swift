import Foundation
import sdk_core

class PlatformFileImplFactory: sdk_core.SdkContainerBeanFactory {
    func create(args: KotlinArray<AnyObject>) throws -> KotlinWrapped<AnyObject> {
        let parent = args.get(index: 0) as? PlatformFileImpl
        let name = args.get(index: 1) as! String

        return KotlinWrapped(
            value: PlatformFileImpl(
                fileURL: parent?.fileURL.appendingPathComponent(name) ?? URL(fileURLWithPath: name)
            )
        )
    }
}

class PlatformFileImpl: PlatformFile {
    let fileURL: URL

    var name: String { fileURL.lastPathComponent }
    var path: String { fileURL.path }

    init(fileURL: URL) {
        self.fileURL = fileURL
    }

    func size() -> Int64 {
        let attrs = try? FileManager.default.attributesOfItem(atPath: fileURL.path)
        return (attrs?[.size] as? NSNumber)?.int64Value ?? 0
    }

    func lastModified() -> Int64 {
        let attrs = try? FileManager.default.attributesOfItem(atPath: fileURL.path)
        if let date = attrs?[.modificationDate] as? Date {
            return Int64(date.timeIntervalSince1970 * 1_000)
        }
        return 0
    }

    func touch() -> Bool {
        if FileManager.default.fileExists(atPath: fileURL.path) {
            return false
        }
        return FileManager.default.createFile(atPath: fileURL.path, contents: nil, attributes: nil)
    }

    func exists() -> Bool {
        FileManager.default.fileExists(atPath: fileURL.path)
    }

    func setLastModified(time: Int64) -> Bool {
        let date = Date(timeIntervalSince1970: Double(time) / 1_000)
        do {
            try FileManager.default.setAttributes([.modificationDate: date], ofItemAtPath: fileURL.path)
            return true
        } catch {
            return false
        }
    }

    func read() throws -> KotlinByteArray {
        return try KtorExt_iosKt.NSDataToByteArray(data: (try Data(contentsOf: fileURL)) ?? Data())
    }

    func writeBytes(data: KotlinByteArray) throws {
        try data.toNSData().write(to: fileURL)
    }

    func delete() -> Bool {
        do {
            try FileManager.default.removeItem(at: fileURL)
            return true
        } catch {
            return false
        }
    }

    func renameTo(dest: PlatformFile) -> Bool {
        guard let destImpl = dest as? PlatformFileImpl else { return false }
        do {
            try FileManager.default.moveItem(at: fileURL, to: destImpl.fileURL)
            return true
        } catch {
            return false
        }
    }

    func listFiles(filter: ((PlatformFile, String) -> KotlinBoolean)? = nil) -> [PlatformFile] {
        guard let urls = try? FileManager.default.contentsOfDirectory(at: fileURL, includingPropertiesForKeys: nil, options: []) else {
            return []
        }
        return urls.compactMap { url in
            let file = PlatformFileImpl(fileURL: url)
            if let filter = filter {
                return filter(
                    self,
                    url.lastPathComponent
                ).boolValue ? file : nil
            }
            return file
        }
    }

    func mkdirs() -> Bool {
        do {
            try FileManager.default.createDirectory(at: fileURL, withIntermediateDirectories: true, attributes: nil)
            return true
        } catch {
            return false
        }
    }
}
