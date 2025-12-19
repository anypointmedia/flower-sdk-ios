import Foundation
import SwiftUI
import sdk_core

class GoogleAdViewImpl: GoogleAdView {
    let logger = FLogging(tag: "GoogleAdView").logger

    var flowerAdView: FlowerAdView
    lazy var googleAdViewImplBody = GoogleAdViewImplBody(flowerAdView: flowerAdView)

    public var body: some View {
        googleAdViewImplBody
    }

    init(flowerAdView: FlowerAdView) {
        self.flowerAdView = flowerAdView
    }

    func getWidth() -> Int32 {
        return googleAdViewImplBody.width
    }

    func getHeight() -> Int32 {
        return googleAdViewImplBody.height
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
        return DeferredStubImpl(task: Task { KotlinBoolean(value: flowerAdView.isGoogleAdViewVisible) })
    }

    func addView(view: any GoogleAdView) {
    }

    func removeView(view: any GoogleAdView) {
    }

    struct GoogleAdViewImplBody: View {
        @ObservedObject var flowerAdView: FlowerAdView
        @State var width: Int32 = 0
        @State var height: Int32 = 0

        var body: some View {
            GeometryReader { geometry in
                Color.clear
                .frame(maxWidth: .infinity, maxHeight: .infinity)
                .onAppear {
                    width = Int32(geometry.size.width)
                    height = Int32(geometry.size.height)
                }
            }
        }
    }
}
