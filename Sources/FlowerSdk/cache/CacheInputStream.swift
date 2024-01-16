import Foundation

class CacheInputStream: InputStream {
    private let sourceInputStream: InputStream
    private let cacheFile: URL
    private var outputStream: OutputStream

    init(sourceInputStream: InputStream, cacheFile: URL) {
        self.sourceInputStream = sourceInputStream
        self.cacheFile = cacheFile
        FileManager.default.createFile(atPath: cacheFile.path, contents: nil, attributes: nil)
        self.outputStream = OutputStream(url: cacheFile, append: true)!
        super.init(data: Data())
    }

    // Note: Differs from Android "override fun read(): Int" function due to OS differences
    override func read(_ buffer: UnsafeMutablePointer<UInt8>, maxLength len: Int) -> Int {
        let bytesRead = sourceInputStream.read(buffer, maxLength: len)
        outputStream.write(buffer, maxLength: bytesRead)
        return bytesRead
    }

    // Note: Differse from Android "override fun available(): Int" function due to OS differences
    override var hasBytesAvailable: Bool {
        return sourceInputStream.hasBytesAvailable
    }

    override func close() {
        outputStream.close()
        sourceInputStream.close()
        super.close()
    }
}
