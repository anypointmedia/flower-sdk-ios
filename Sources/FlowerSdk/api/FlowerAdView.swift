import Foundation
import Combine
import SwiftUI
import sdk_core

public class FlowerAdView: FlowerAdViewStub, ObservableObject {
    let logger = FLogging().logger

    @Published var isFlowerAdViewVisible = false
    @Published var isAdPlayerViewVisible = false
    @Published var isGoogleAdViewVisible = false
    @Published var isFlowerAdUIViewVisible = false

    lazy var adPlayerView: AdPlayerViewImpl = AdPlayerViewImpl(flowerAdView: self)
    lazy var googleAdView: GoogleAdViewImpl = GoogleAdViewImpl(flowerAdView: self)
    lazy var flowerAdUIView: FlowerAdUIViewImpl = FlowerAdUIViewImpl(flowerAdView: self)
    lazy var flowerAdViewBody: FlowerAdViewBody = FlowerAdViewBody(flowerAdView: self)

    public lazy var adsManager: FlowerAdsManager = FlowerAdsManagerImpl(
        flowerAdView: self,
        adPlayerView: adPlayerView,
        googleAdView: googleAdView,
        flowerAdUIView: flowerAdUIView
    )

    public init() {
    }

    public var body: FlowerAdViewBody {
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
        self.adPlayerView.show()
        self.googleAdView.show()
    }

    public func hide() {
        logger.debug { "Hiding FlowerAdView" }
        self.isFlowerAdViewVisible = false
        self.flowerAdUIView.hide()
        self.adPlayerView.hide()
        self.googleAdView.hide()
    }

    public func isShow() -> Bool {
        return isFlowerAdViewVisible
    }

    public struct FlowerAdViewBody: View {
        @ObservedObject var flowerAdView: FlowerAdView
        @State var width: Int32 = 0
        @State var height: Int32 = 0

        public var body: some View {
            GeometryReader { geometry in
                ZStack {
                    if (flowerAdView.isFlowerAdViewVisible) {
                        Color.black.opacity(0.0001)
                        flowerAdView.adPlayerView.body
                        flowerAdView.googleAdView.body
                        flowerAdView.flowerAdUIView.body
                    }
                }
                .frame(maxWidth: .infinity, maxHeight: .infinity)
                .onAppear {
                    width = Int32(geometry.size.width)
                    height = Int32(geometry.size.height)
                }
            }
        }
    }

    public class HostingController: UIHostingController<FlowerAdViewBody> {
        public let adView = FlowerAdView()

        var cancellables = Set<AnyCancellable>()

        public init() {
            super.init(rootView: adView.body)
        }

        @MainActor @preconcurrency required dynamic init?(coder aDecoder: NSCoder) {
            super.init(coder: aDecoder, rootView: adView.body)
        }

        public override func viewDidLoad() {
            super.viewDidLoad()

            view.backgroundColor = .clear

            adView.$isFlowerAdUIViewVisible
                .sink { [weak self] isFlowerAdUIViewVisible in
                    self?.view.isUserInteractionEnabled = isFlowerAdUIViewVisible
                }
                .store(in: &cancellables)
        }
    }
}
