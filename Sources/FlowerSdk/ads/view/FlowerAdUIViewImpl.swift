import Foundation
import sdk_core
import SwiftUI

// Kotlin `Ad` values and escaping closures passed into the main-actor `onMain` closure below
// aren't provably `Sendable`. `onMain` runs synchronously, so these values are only touched on the
// main thread while the caller blocks — safe to box for the one-shot handoff.
private struct UnsafeSendableBox<Value>: @unchecked Sendable {
    let value: Value
}

// `flowerAdView` is only ever assigned once at init and every other stored property is either
// immutable or (as documented below) only ever touched from the main thread, so it's safe to
// declare this Kotlin-facing wrapper `Sendable` and let it cross into `Task`/`MainActor`
// closures without the compiler's conservative "sending self" diagnostics.
class FlowerAdUIViewImpl: FlowerAdUIView, @unchecked Sendable {
    let logger = FLogging(tag: "FlowerAdUIView").logger

    var flowerAdView: FlowerAdView
    // `FlowerAdUIViewImplBody` is a SwiftUI `View`-conforming type, which Swift 6 isolates to
    // `@MainActor` in its entirety (including its synthesized initializer). `FlowerAdUIView`/
    // `UIElement` are Kotlin-exported (@objc) protocols whose requirements must stay nonisolated,
    // so this storage can't be `@MainActor` without every access below needing to hop actors.
    // These entry points are always invoked from the main thread by the Kotlin Multiplatform
    // bridge, so `nonisolated(unsafe)` (with the one-time construction bridged via
    // `MainActor.assumeIsolated`) is a safe, minimal way to expose it to the nonisolated API.
    // (`nonisolated` alone is rejected here since the SwiftUI `FlowerAdUIViewImplBody` value
    // type isn't `Sendable`, even though the enclosing class is.)
    nonisolated(unsafe) lazy var flowerAdUIViewImplBody = MainActor.assumeIsolated {
        FlowerAdUIViewImplBody(flowerAdView: flowerAdView)
    }

    public var body: some View {
        flowerAdUIViewImplBody
    }

    init(flowerAdView: FlowerAdView) {
        self.flowerAdView = flowerAdView
    }

    func getWidth() -> Int32 {
        onMain { self.flowerAdUIViewImplBody.width }
    }

    func getHeight() -> Int32 {
        onMain { self.flowerAdUIViewImplBody.height }
    }

    func show() {
        onMainAsync { self.flowerAdUIViewImplBody.show() }
    }

    func hide() {
        onMainAsync { self.flowerAdUIViewImplBody.hide() }
    }

    func isShow() -> any DeferredStub {
        // Read the backing visibility flag directly (it lives on the non-isolated `flowerAdView`),
        // so this answers synchronously from the Kotlin bridge without hopping to the main thread.
        let isShow = flowerAdView.isFlowerAdUIViewVisible
        return DeferredStubImpl(task: Task { SendableBox(value: KotlinBoolean(value: isShow)) })
    }

    func showClickUi(ad: Ad, postClick: @escaping () -> Void) {
        let box = UnsafeSendableBox(value: (ad, postClick))
        onMainAsync { self.flowerAdUIViewImplBody.showClickUi(ad: box.value.0, postClick: box.value.1) }
    }

    func hideClickUi() {
        onMainAsync { self.flowerAdUIViewImplBody.hideClickUi() }
    }

    func showSkipUi(ad: Ad, nextAd: Ad?, postSkip: @escaping () -> Void) {
        let box = UnsafeSendableBox(value: (ad, postSkip))
        onMainAsync { self.flowerAdUIViewImplBody.showSkipUi(ad: box.value.0, postSkip: box.value.1) }
    }

    func hideSkipUi() {
        onMainAsync { self.flowerAdUIViewImplBody.hideSkipUi() }
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

    class FlowerAdUIViewImplBodyObserver: ObservableObject {
        @Published var clickThroughButtonAd: Ad?
        @Published var skipButtonAd: Ad?
        @Published var postClick: (() -> Void)?
        @Published var postSkip: (() -> Void)?
    }

    struct FlowerAdUIViewImplBody: View {
        let logger = FLogging(tag: "FlowerAdUIViewImpl").logger

        @ObservedObject var flowerAdView: FlowerAdView
        @ObservedObject var observer = FlowerAdUIViewImplBodyObserver()
        @State var width: Int32 = 0
        @State var height: Int32 = 0

        /// 화면 너비에 비례한 오른쪽 여백 (작은 화면에서 버튼이 오른쪽에 가깝게 위치)
        /// minOffset 60 = 버튼 minWidth 120의 절반 (position은 중심 기준)
        private func trailingOffset(for width: CGFloat) -> CGFloat {
            let ratio: CGFloat = 0.08
            let minOffset: CGFloat = 60
            return max(minOffset, width * ratio)
        }

        var body: some View {
            GeometryReader { geometry in
                let trailing = trailingOffset(for: geometry.size.width)
                ZStack {
                    if observer.clickThroughButtonAd != nil {
                        Button(action: {
                            if let ad = observer.clickThroughButtonAd {
                                if let clickThroughUrl = ad.click?.clickThroughUrl {
                                    if let url = URL(string: clickThroughUrl), let scheme = url.scheme {
                                        if UIApplication.shared.canOpenURL(url) {
                                            UIApplication.shared.open(url, options: [:], completionHandler: nil)
                                        } else {
                                            logger.warn { "Cannot open URL. URL: \(url)" }
                                        }
                                    } else {
                                        logger.warn { "clickThroughUrl does not have a scheme. Skipping opening browser. clickThroughUrl: \(clickThroughUrl)" }
                                    }
                                }

                                observer.postClick?()
                            }
                        }) {
                            Text(SdkContainer.Companion().getInstance().uiText.clickThrough)
                                .foregroundColor(.white)
                                .opacity(0.8)
                                .font(.system(size: 16, weight: .semibold))
                                .frame(minWidth: 120, minHeight: 44)
                                .background(Color.black.opacity(0.3))
                        }
                        .buttonStyle(.plain)
                        .position(x: geometry.size.width - trailing, y: geometry.size.height - 40)
                    }
                    if observer.skipButtonAd != nil {
                        Button(action: {
                            if let ad = observer.skipButtonAd {
                                observer.postSkip?()
                            }
                        }) {
                            Text(SdkContainer.Companion().getInstance().uiText.skip)
                                .foregroundColor(.white)
                                .opacity(0.8)
                                .font(.system(size: 16, weight: .semibold))
                                .frame(minWidth: 120, minHeight: 44)
                                .background(Color.black.opacity(0.3))
                        }
                        .buttonStyle(.plain)
                        .position(x: geometry.size.width - trailing, y: geometry.size.height - 100)
                    }
                }
                .frame(maxWidth: .infinity, maxHeight: .infinity)
                .onAppear {
                    width = Int32(geometry.size.width)
                    height = Int32(geometry.size.height)
                }
            }
        }

        func show() {
            if (isShow()) {
                return
            }

            DispatchQueue.main.async {
                self.logger.debug { "Showing FlowerAdUIView" }
                self.flowerAdView.isFlowerAdUIViewVisible = true
            }
        }

        func hide() {
            if (!isShow()) {
                return
            }

            DispatchQueue.main.async {
                self.logger.debug { "Hiding FlowerAdUIView" }
                self.flowerAdView.isFlowerAdUIViewVisible = false
                self.observer.clickThroughButtonAd = nil
                self.observer.skipButtonAd = nil
            }
        }

        func isShow() -> Bool {
            flowerAdView.isFlowerAdUIViewVisible
        }

        func showClickUi(ad: Ad, postClick: @escaping () -> Void) {
            if observer.clickThroughButtonAd == ad {
                return
            }

            DispatchQueue.main.async {
                self.logger.debug { "Showing FlowerAdUIView click ui" }

                self.observer.clickThroughButtonAd = ad
                self.observer.postClick = postClick
            }
        }

        func showSkipUi(ad: Ad, postSkip: @escaping () -> Void) {
            if observer.skipButtonAd == ad {
                return
            }

            DispatchQueue.main.async {
                self.logger.debug { "Showing FlowerAdUIView skip ui" }

                self.observer.skipButtonAd = ad
                self.observer.postSkip = postSkip
            }
        }

        func hideClickUi() {
            if observer.clickThroughButtonAd == nil {
                return
            }

            DispatchQueue.main.async {
                self.logger.debug { "Hiding FlowerAdUIView click ui" }
                self.observer.clickThroughButtonAd = nil
            }
        }

        func hideSkipUi() {
            if observer.skipButtonAd == nil {
                return
            }

            DispatchQueue.main.async {
                self.logger.debug { "Hiding FlowerAdUIView skip ui" }
                self.observer.skipButtonAd = nil
            }
        }
    }
}
