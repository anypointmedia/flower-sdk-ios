import Foundation


// Note: CacheInputStream is not using FileExt due to Swift supporting necessary functions with URL.
// Note: Expected to be depcrecated in ios-sdk unless a need arrives
extension FileManager {
    func fileSize(atPath path: String) -> Int64 {
        let fileAttributes = try? attributesOfItem(atPath: path)

        if let fileSize = fileAttributes?[.size] as? Int64 {
            return fileSize
        }

        return 0
    }

    func freeSize(atPath path: String) -> Int64 {
        let fileURL = URL(fileURLWithPath: path)
        let values = try? fileURL.resourceValues(forKeys: [.volumeAvailableCapacityForImportantUsageKey])

        if let freeSize = values?.volumeAvailableCapacityForImportantUsage {
            return freeSize
        }

        return 0
    }

    func createFile(atPath path: String) -> Bool {
        let fileURL = URL(fileURLWithPath: path)

        if fileExists(atPath: path) {
            return true
        }

        if !fileURL.deletingLastPathComponent().path.isEmpty && !fileExists(atPath: fileURL.deletingLastPathComponent().path) {
            try? createDirectory(atPath: fileURL.deletingLastPathComponent().path, withIntermediateDirectories: true, attributes: nil)
        }

        return createFile(atPath: path, contents: nil, attributes: nil)
    }
}

/* Example Usage

let filePath = "/path/to/your/file.txt"
let fileManager = FileManager.default

let fileSize = fileManager.fileSize(atPath: filePath)
print("File Size: \(fileSize) bytes")

let freeSize = fileManager.freeSize(atPath: filePath)
print("Free Size: \(freeSize) bytes")

let created = fileManager.createFile(atPath: filePath)
print("File Created: \(created)")

*/
