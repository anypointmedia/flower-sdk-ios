import Foundation
import sdk_core
import SwiftUI

class FlowerAdUIViewImpl: FlowerAdUIView {
    let logger = FLogging(tag: nil).logger

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

    func isShow() -> Bool {
        return flowerAdUIViewImplBody.isShow()
    }

    func showClickUi(ad: Ad, postClick: @escaping () -> Void) {
        flowerAdUIViewImplBody.showClickUi(ad: ad, postClick: postClick)
    }

    func showSkipUi(ad: Ad, postSkip: @escaping () -> Void) {
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
        let logger = FLogging(tag: nil).logger

        @ObservedObject var flowerAdView: FlowerAdView
        @ObservedObject var observer = FlowerAdUIViewImplBodyObserver()
        @State var width: Int32 = 0
        @State var height: Int32 = 0

        var body: some View {
            GeometryReader { geometry in
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
                        }
                        .buttonStyle(.bordered)
                        .position(x: geometry.size.width - 80, y: geometry.size.height - 40)
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
                        }
                        .buttonStyle(.bordered)
                        .position(x: geometry.size.width - 80, y: geometry.size.height - 80)
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

            logger.debug { "Showing FlowerAdUIView" }
            flowerAdView.isFlowerAdUIViewVisible = true
        }

        func hide() {
            if (!isShow()) {
                return
            }

            logger.debug { "Hiding FlowerAdUIView" }
            flowerAdView.isFlowerAdUIViewVisible = false
            observer.clickThroughButtonAd = nil
            observer.skipButtonAd = nil
        }

        func isShow() -> Bool {
            flowerAdView.isFlowerAdUIViewVisible
        }

        func showClickUi(ad: Ad, postClick: @escaping () -> Void) {
            if observer.clickThroughButtonAd == ad {
                return
            }

            logger.debug { "Showing FlowerAdUIView click ui" }

            observer.clickThroughButtonAd = ad
            show()
            observer.postClick = postClick
        }

        func showSkipUi(ad: Ad, postSkip: @escaping () -> Void) {
            if observer.skipButtonAd == ad {
                return
            }

            logger.debug { "Showing FlowerAdUIView skip ui" }

            observer.skipButtonAd = ad
            show()
            observer.postSkip = postSkip
        }

        func hideSkipUi() {
            if observer.skipButtonAd == nil {
                return
            }

            logger.debug { "Hiding FlowerAdUIView skip ui" }
            observer.skipButtonAd = nil
        }
    }
}
