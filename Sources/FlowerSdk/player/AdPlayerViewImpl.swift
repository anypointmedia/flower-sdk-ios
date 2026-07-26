import Foundation
import AVKit
import SwiftUI
import sdk_core

// The `sending` AVPlayerLayer crossing into the main-actor `onMainAsync` closure below isn't
// provably `Sendable`; it's handed off exactly once to the main thread, so box it for the transfer.
private struct UnsafeSendableBox<Value>: @unchecked Sendable {
    let value: Value
}

// `flowerAdView` is only ever assigned once at init and every other stored property is either
// immutable or (as documented below) only ever touched from the main thread, so it's safe to
// declare this Kotlin-facing wrapper `Sendable` and let it cross into `Task`/`MainActor`
// closures without the compiler's conservative "sending self" diagnostics.
class AdPlayerViewImpl: AdPlayerView, @unchecked Sendable {
    let logger = FLogging(tag: "AdPlayerView").logger

    var flowerAdView: FlowerAdView
    // `AdPlayerViewImplBody` is a SwiftUI `View`-conforming type, which Swift 6 isolates to
    // `@MainActor` in its entirety (including its synthesized initializer). `AdPlayerView`/
    // `UIElement` are Kotlin-exported (@objc) protocols whose requirements must stay nonisolated,
    // so this storage can't be `@MainActor` without every access below needing to hop actors.
    // These entry points are always invoked from the main thread by the Kotlin Multiplatform
    // bridge, so `nonisolated(unsafe)` (with the one-time construction bridged via
    // `MainActor.assumeIsolated`) is a safe, minimal way to expose it to the nonisolated API.
    // (`nonisolated` alone is rejected here since the SwiftUI `AdPlayerViewImplBody` value type
    // isn't `Sendable`, even though the enclosing class is.)
    nonisolated(unsafe) lazy var adPlayerViewImplBody = MainActor.assumeIsolated {
        AdPlayerViewImplBody(flowerAdView: flowerAdView)
    }

    public var body: some View {
        adPlayerViewImplBody
    }

    init(flowerAdView: FlowerAdView) {
        self.flowerAdView = flowerAdView
    }

    func getWidth() -> Int32 {
        onMain { self.adPlayerViewImplBody.width }
    }

    func getHeight() -> Int32 {
        onMain { self.adPlayerViewImplBody.height }
    }

    func show() {
        DispatchQueue.main.async {
            self.logger.debug { "Showing AdPlayerView" }
            self.flowerAdView.isAdPlayerViewVisible = true
        }
    }

    func hide() {
        DispatchQueue.main.async {
            self.logger.debug { "Hiding AdPlayerView" }
            self.flowerAdView.isAdPlayerViewVisible = false
        }
    }

    func isShow() -> any DeferredStub {
        return DeferredStubImpl(task: Task { SendableBox(value: KotlinBoolean(value: flowerAdView.isAdPlayerViewVisible)) })
    }

    func setCoverImage(url: String) {
        // no-op on iOS
    }

    func showCoverImage() {
        // no-op on iOS
    }

    func hideCoverImage() {
        // no-op on iOS
    }

    func addPlayerLayer(playerLayer: sending AVPlayerLayer) {
        let box = UnsafeSendableBox(value: playerLayer)
        onMainAsync { self.adPlayerViewImplBody.observer.playerLayerRepresentable = AVPlayerLayerRepresentable(playerLayer: box.value) }
    }

    func removePlayerLayer() {
        onMainAsync { self.adPlayerViewImplBody.observer.playerLayerRepresentable = nil }
    }

    // The Kotlin bridge invokes these entry points from coroutine background threads (e.g.
    // LinearTVAdHandler on kotlinx DarwinGlobalQueueDispatcher). We must NOT block the caller with
    // `DispatchQueue.main.sync`: the Kotlin bridge can be holding the main thread waiting on the
    // same coroutine, which deadlocks and freezes the screen. So UI mutations hop to the main
    // thread asynchronously. Only synchronous value getters that are never called while the main
    // thread is blocked use `onMain` below.
    private func onMainAsync(_ work: @escaping @MainActor () -> Void) {
        if Thread.isMainThread {
            MainActor.assumeIsolated(work)
        } else {
            DispatchQueue.main.async { MainActor.assumeIsolated(work) }
        }
    }

    private func onMain<T: Sendable>(_ work: @MainActor () -> T) -> T {
        if Thread.isMainThread {
            return MainActor.assumeIsolated(work)
        }
        return DispatchQueue.main.sync { MainActor.assumeIsolated(work) }
    }

    struct AVPlayerLayerRepresentable: UIViewRepresentable {
        let playerLayer: AVPlayerLayer

        func makeUIView(context: Context) -> UIView {
            return PlayerContainer(playerLayer: playerLayer)
        }

        func updateUIView(_ uiView: UIView, context: Context) {
        }

        class PlayerContainer: UIView {

            init(playerLayer: AVPlayerLayer) {
                super.init(frame: .zero)
                layer.addSublayer(playerLayer)
            }

            required init?(coder: NSCoder) {
                fatalError("init(coder:) has not been implemented")
            }

            override func layoutSubviews() {
                super.layoutSubviews()
                layer.sublayers?.first?.frame = frame
            }
        }
    }

    class AdPlayerViewImplBodyObserver: ObservableObject {
        @Published var playerLayerRepresentable: AVPlayerLayerRepresentable?
    }

    struct AdPlayerViewImplBody: View {
        @ObservedObject var flowerAdView: FlowerAdView
        @ObservedObject var observer = AdPlayerViewImplBodyObserver()
        @State var width: Int32 = 0
        @State var height: Int32 = 0

        var body: some View {
            GeometryReader { geometry in
                observer.playerLayerRepresentable
                .background(Color.black)
                .frame(maxWidth: .infinity, maxHeight: .infinity)
                .onAppear {
                    width = Int32(geometry.size.width)
                    height = Int32(geometry.size.height)
                }
            }
        }
    }
}
