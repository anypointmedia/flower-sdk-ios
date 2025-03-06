import Foundation
import AVKit
import SwiftUI
import sdk_core

class AdPlayerViewImpl: AdPlayerView {
    let logger = FLogging().logger

    var flowerAdView: FlowerAdView
    lazy var adPlayerViewImplBody = AdPlayerViewImplBody(flowerAdView: flowerAdView)

    public var body: some View {
        adPlayerViewImplBody
    }

    init(flowerAdView: FlowerAdView) {
        self.flowerAdView = flowerAdView
    }

    func getWidth() -> Int32 {
        return adPlayerViewImplBody.width
    }

    func getHeight() -> Int32 {
        return adPlayerViewImplBody.height
    }

    func show() {
        logger.debug { "Showing AdPlayerView" }
        flowerAdView.isAdPlayerViewVisible = true
    }

    func hide() {
        logger.debug { "Hiding AdPlayerView" }
        flowerAdView.isAdPlayerViewVisible = false
    }

    func isShow() -> Bool {
        return flowerAdView.isAdPlayerViewVisible
    }

    func addPlayerLayer(playerLayer: AVPlayerLayer) {
        adPlayerViewImplBody.observer.playerLayerRepresentable = AVPlayerLayerRepresentable(playerLayer: playerLayer)
    }

    func removePlayerLayer() {
        adPlayerViewImplBody.observer.playerLayerRepresentable = nil
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