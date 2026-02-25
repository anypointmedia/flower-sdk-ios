import Foundation
import sdk_core
import SwiftUI

class FlowerAdUIViewImpl: FlowerAdUIView {
    let logger = FLogging(tag: "FlowerAdUIView").logger

    var flowerAdView: FlowerAdView
    lazy var flowerAdUIViewImplBody = FlowerAdUIViewImplBody(flowerAdView: flowerAdView)

    public var body: some View {
        flowerAdUIViewImplBody
    }

    init(flowerAdView: FlowerAdView) {
        self.flowerAdView = flowerAdView
    }

    func getWidth() -> Int32 {
        return flowerAdUIViewImplBody.width
    }

    func getHeight() -> Int32 {
        return flowerAdUIViewImplBody.height
    }

    func show() {
        flowerAdUIViewImplBody.show()
    }

    func hide() {
        flowerAdUIViewImplBody.hide()
    }

    func isShow() -> any DeferredStub {
        return DeferredStubImpl(task: Task { KotlinBoolean(value: flowerAdUIViewImplBody.isShow()) })
    }

    func showClickUi(ad: Ad, postClick: @escaping () -> Void) {
        flowerAdUIViewImplBody.showClickUi(ad: ad, postClick: postClick)
    }

    func hideClickUi() {
        flowerAdUIViewImplBody.hideClickUi()
    }

    func showSkipUi(ad: Ad, nextAd: Ad?, postSkip: @escaping () -> Void) {
        flowerAdUIViewImplBody.showSkipUi(ad: ad, postSkip: postSkip)
    }

    func hideSkipUi() {
        flowerAdUIViewImplBody.hideSkipUi()
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
