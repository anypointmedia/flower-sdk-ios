import Foundation
import sdk_core

/// Non-Sendable Kotlin/Native objects are wrapped here so they can be carried across the
/// `Task` boundary required by Swift 6 strict concurrency. These tasks are only ever
/// consumed on one side of the Kotlin bridge, so `@unchecked Sendable` is safe.
struct SendableBox: @unchecked Sendable {
    let value: Any?
}

class DeferredStubImpl: DeferredStub {
    var task: Task<SendableBox, Error>

    init(task: Task<SendableBox, Error>) {
        self.task = task
    }

    func await() async throws -> Any? {
        try await task.result.get().value
    }
}
