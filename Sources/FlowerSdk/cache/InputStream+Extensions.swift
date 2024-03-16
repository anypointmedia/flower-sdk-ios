import Foundation

// In Swift, there isn't a direct equivalent to Ktor's InputStream.toByteReadChannel since the concepts and libraries are different.
extension InputStream {
    func toByteReadChannel() -> Data {
        var data = Data()
        var buffer = [UInt8](repeating: 0, count: 4096)
        var dataBuffer = DispatchData.empty
        var bytesRead = 0

        while bytesRead >= 0 {
            while bytesRead >= 0 {
                bytesRead = self.read(&buffer, maxLength: buffer.count)

                if bytesRead > 0 {
                    data.append(buffer, count: bytesRead)
                } else if bytesRead == 0 {
                    // End of stream
                    return data
                } else {
                    // Error reading from stream
                    return data
                }
            }

            // Error or end of stream
            return data
        }
    }
}
