import Foundation
import sdk_core
import SwiftUI

class FlowerAdUIViewImpl: FlowerAdUIView {
    let logger = FLogging().logger

    var flowerAdView: FlowerAdView
    var isShowingQR = false
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
        logger.debug { "Showing FlowerAdUIView" }
        flowerAdView.isFlowerAdUIViewVisible = true
    }

    func hide() {
        logger.debug { "Hiding FlowerAdUIView" }
        flowerAdView.isFlowerAdUIViewVisible = false
    }

    func isShow() -> Bool {
        return flowerAdView.isFlowerAdUIViewVisible
    }

    func showClickUi(ad: Ad, postClick: @escaping () -> Void) {
        flowerAdUIViewImplBody.showClickUi(ad: ad, postClick: postClick)
    }

    func hideClickUi(ad_ ad: Ad) {
        flowerAdUIViewImplBody.hideClickUi(ad: ad)
    }

    class FlowerAdUIViewImplBodyObserver: ObservableObject {
        @Published var currentVisibleAd: Ad?
        @Published var postClick: (() -> Void)?
    }

    struct FlowerAdUIViewImplBody: View {
        let logger = FLogging().logger

        @ObservedObject var flowerAdView: FlowerAdView
        @ObservedObject var observer = FlowerAdUIViewImplBodyObserver()
        @State var width: Int32 = 0
        @State var height: Int32 = 0

        var body: some View {
            GeometryReader { geometry in
                ZStack {
                    if observer.currentVisibleAd != nil {
                        Button(action: {
                            if let ad = observer.currentVisibleAd {
                                observer.postClick?()

                                if let clickThroughUrl = ad.click?.clickThroughUrl {
                                    if let url = URL(string: clickThroughUrl), UIApplication.shared.canOpenURL(url) {
                                        UIApplication.shared.open(url, options: [:], completionHandler: nil)
                                    }
                                }
                            }
                        }) {
                            Text("View More")
                            .foregroundColor(.white)
                            .font(.system(size: 16, weight: .semibold))
                        }
                        .frame(maxWidth: 120, maxHeight: 40)
                        .background(Color(red: 52 / 255, green: 152 / 255, blue: 219 / 255))
                        .frame(maxWidth: 120, maxHeight: 40)
                        .cornerRadius(8)
                        .position(x: geometry.size.width - 80, y: geometry.size.height - 40)
                    }
                }
                .frame(maxWidth: .infinity, maxHeight: .infinity)
                .onAppear {
                    width = Int32(geometry.size.width)
                    height = Int32(geometry.size.height)
                }
            }
        }

        func showClickUi(ad: Ad, postClick: @escaping () -> Void) {
            if ad.click?.clickThroughUrl == nil {
                return
            }

            if observer.currentVisibleAd == ad {
                return
            }

            logger.debug { "Showing FlowerAdUIView click ui" }

            observer.currentVisibleAd = ad
            observer.postClick = postClick
        }

        func hideClickUi(ad: Ad) {
            if observer.currentVisibleAd == ad {
                logger.debug { "Hiding FlowerAdUIView click ui" }
                observer.currentVisibleAd = nil
                observer.postClick = nil
            }
        }
    }
}
