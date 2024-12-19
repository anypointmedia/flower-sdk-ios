import Foundation
import SwiftUI
import sdk_core

public class FlowerAdView: FlowerAdViewStub, ObservableObject {
    let logger = sdk_core.KmLog()

    @Published var isFlowerAdViewVisible = false
    @Published var isAdPlayerViewVisible = false
    @Published var isGoogleAdViewVisible = false
    @Published var isFlowerAdUIViewVisible = false

    lazy var playerView: AdPlayerViewImpl = AdPlayerViewImpl(flowerAdView: self)
    lazy var googleAdView: GoogleAdViewImpl = GoogleAdViewImpl(flowerAdView: self)
    lazy var flowerAdUIView: FlowerAdUIViewImpl = FlowerAdUIViewImpl(flowerAdView: self)
    lazy var flowerAdViewBody: FlowerAdViewBody = FlowerAdViewBody(flowerAdView: self)

    public lazy var adsManager: FlowerAdsManager = FlowerAdsManagerImpl(
        flowerAdView: self,
        playerView: playerView,
        googleAdView: googleAdView,
        flowerAdUIView: flowerAdUIView
    )

    public init() {
    }

    public var body: some View {
        flowerAdViewBody
    }

    public func getWidth() -> Int32 {
        return flowerAdViewBody.width
    }

    public func getHeight() -> Int32 {
        return flowerAdViewBody.height
    }

    public func show() {
        logger.debug { "Showing FlowerAdView" }
        self.isFlowerAdViewVisible = true
        self.flowerAdUIView.show()
        self.playerView.show()
        self.googleAdView.show()
    }

    public func hide() {
        logger.debug { "Hiding FlowerAdView" }
        self.isFlowerAdViewVisible = false
        self.flowerAdUIView.hide()
        self.playerView.hide()
        self.googleAdView.hide()
    }

    public func isShow() -> Bool {
        return isFlowerAdViewVisible
    }

    struct FlowerAdViewBody: View {
        @ObservedObject var flowerAdView: FlowerAdView
        @State var width: Int32 = 0
        @State var height: Int32 = 0

        var body: some View {
            if (flowerAdView.isFlowerAdViewVisible) {
                GeometryReader { geometry in
                    ZStack {
                        flowerAdView.playerView.body
                        flowerAdView.googleAdView.body
                        flowerAdView.flowerAdUIView.body
                    }
                    .frame(maxWidth: .infinity, maxHeight: .infinity)
                    .onAppear {
                        width = Int32(geometry.size.width)
                        height = Int32(geometry.size.height)
                    }
                }
            }
        }
    }
}
