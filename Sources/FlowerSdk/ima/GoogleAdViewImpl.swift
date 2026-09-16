import Foundation
import SwiftUI
import sdk_core

// `flowerAdView` is only ever assigned once at init and every other stored property is either
// immutable or only ever touched from the main thread, so it's safe to declare this
// Kotlin-facing wrapper `Sendable` and let it cross into `Task`/closures without the compiler's
// conservative "sending self" diagnostics.
class GoogleAdViewImpl: GoogleAdView, @unchecked Sendable {

    func setFocusable(focusable: Bool) {
    }
    
    let logger = FLogging(tag: "GoogleAdView").logger

    var flowerAdView: FlowerAdView
    // Not `lazy`: Swift's lazy initialisation is not atomic, and getWidth/getHeight are called
    // from Kotlin's IO workers - the two wrapper ads of one ad break ask for the player size
    // concurrently, which would let both threads run the initialiser and over-release one of
    // the two instances.
    let googleAdViewImplBody: GoogleAdViewImplBody
    private let measuredSize = MeasuredSize()

    public var body: some View {
        googleAdViewImplBody
    }

    init(flowerAdView: FlowerAdView) {
        self.flowerAdView = flowerAdView
        self.googleAdViewImplBody = GoogleAdViewImplBody(
            flowerAdView: flowerAdView,
            measuredSize: measuredSize
        )
    }

    // Read from the lock-guarded mirror rather than from the body's `@State`: callers are Kotlin
    // workers, and SwiftUI's state storage is main-thread-only and not thread safe.
    func getWidth() -> Int32 {
        return measuredSize.width
    }

    func getHeight() -> Int32 {
        return measuredSize.height
    }

    func show() {
        DispatchQueue.main.async {
            self.logger.debug { "Showing GoogleAdView" }
            self.flowerAdView.isGoogleAdViewVisible = true
        }
    }

    func hide() {
        DispatchQueue.main.async {
            self.logger.debug { "Hiding GoogleAdView" }
            self.flowerAdView.isGoogleAdViewVisible = false
        }
    }

    func isShow() -> any DeferredStub {
        return DeferredStubImpl(task: Task { SendableBox(value: KotlinBoolean(value: flowerAdView.isGoogleAdViewVisible)) })
    }

    func addView(view: any GoogleAdView) {
    }

    func removeView(view: any GoogleAdView) {
    }

    /// The player size measured by SwiftUI, mirrored out of the view graph so that non-main
    /// threads can read it. The view writes it on the main thread; Kotlin reads it from its own
    /// workers, and both go through the lock.
    final class MeasuredSize: @unchecked Sendable {
        private let lock = NSLock()
        private var size: (width: Int32, height: Int32) = (0, 0)

        var width: Int32 {
            lock.lock()
            defer { lock.unlock() }
            return size.width
        }

        var height: Int32 {
            lock.lock()
            defer { lock.unlock() }
            return size.height
        }

        func update(width: Int32, height: Int32) {
            lock.lock()
            defer { lock.unlock() }
            size = (width, height)
        }
    }

    struct GoogleAdViewImplBody: View {
        @ObservedObject var flowerAdView: FlowerAdView
        let measuredSize: MeasuredSize

        var body: some View {
            GeometryReader { geometry in
                Color.clear
                .frame(maxWidth: .infinity, maxHeight: .infinity)
                .onAppear {
                    measuredSize.update(
                        width: Int32(geometry.size.width),
                        height: Int32(geometry.size.height)
                    )
                }
            }
        }
    }
}
