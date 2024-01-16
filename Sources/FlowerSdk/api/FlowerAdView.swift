import Foundation
import SwiftUI
import core

public typealias MediaPlayerHook = core.MediaPlayerHook

public struct FlowerAdViewBody: View {
    public var body: some View {
        ZStack {
        }
    }
}

// TODO: Implement class FlowerAdViewImpl : FrameLayout, FlowerAdView {
public class FlowerAdView: FlowerAdViewInterface {
    var flowerAdUIView: FlowerAdUIView = FlowerAdUIViewImpl()
    var playerView: AdPlayerView = AdPlayerViewImpl()
    var googleAdView: GoogleAdView = GoogleAdViewImpl()

    public var body = FlowerAdViewBody()

    public lazy var adManager: FlowerAdManager = FlowerAdManagerImpl(flowerAdView: self, playerView: playerView, googleAdView: googleAdView, flowerAdUIView: flowerAdUIView)

    public init(/* context: any View */) {
        // TODO: Implement
//        visibility = GONE
//        setBackgroundColor(Color.TRANSPARENT)
//
//        playerView.layoutParams = LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.MATCH_PARENT)
//        playerView.visibility = GONE
//        addView(playerView)
//
//        googleAdView.layoutParams = LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.MATCH_PARENT)
//        googleAdView.setBackgroundColor(0)
//        googleAdView.visibility = GONE
//        addView(googleAdView)
//
//        flowerAdUIView.layoutParams = LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.MATCH_PARENT)
//        flowerAdUIView.setBackgroundColor(Color.TRANSPARENT)
//        flowerAdUIView.visibility = GONE
//        addView(flowerAdUIView)
    }

    // TODO: Implement
    // override
    public func hide() {
    }

    // TODO: Implement
    // override
    public func show() {

    }

    public func getHeight() -> Int32 {
        0
    }

    public func getWidth() -> Int32 {
        0
    }
}
