import Foundation
import core

class CommonJobImpl<T>: CommonJob {
    var job: Task<T, Error>

    init(originalJob: Task<T, Error>) {
        self.job = originalJob
    }

    func join() async throws -> Any? {
        try await job.result.get()
    }
}
