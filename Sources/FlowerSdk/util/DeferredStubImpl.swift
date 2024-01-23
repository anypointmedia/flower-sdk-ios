import Foundation
import core

class DeferredStubImpl: DeferredStub {
    var task: Task<Any?, Error>

    init(task: Task<Any?, Error>) {
        self.task = task
    }

    func await() async throws -> Any? {
        try await task.result.get()
    }
}
