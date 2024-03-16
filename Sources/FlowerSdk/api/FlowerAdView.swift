import Foundation
import SwiftUI
import UIKit
import AVKit
import sdk_core

public class FlowerAdViewInternal: UIView, FlowerAdViewStubWrapper {
    var flowerAdUIView: FlowerAdUIView = FlowerAdUIViewImpl()
    var playerView: AdPlayerView = AdPlayerViewImpl()
    var googleAdView: GoogleAdView = GoogleAdViewImpl()
    
    var isInitiated = false

    public weak var observer: FlowerAdViewObserverInternal?

    public override var isHidden: Bool {
        didSet {
            observer?.adViewDidChangeIsHidden(isHidden)
        }
    }

    public lazy var adsManager: FlowerAdsManager = FlowerAdsManagerImpl(
        flowerAdView: self,
        playerView: playerView,
        googleAdView: googleAdView,
        flowerAdUIView: flowerAdUIView
    )

    override init(frame: CGRect) {
        super.init(frame: CGRect(x: 0, y: 0, width: 0, height: 0))
    }

    public required init?(coder: NSCoder) {
        super.init(coder: coder)
    }

    public func commonInit() {
        if (isInitiated) {
            return
        }
        isInitiated = true
        
        isHidden = true
        backgroundColor = .clear
        self.frame = CGRect(x: 0, y: 0, width: 0, height: 0)

        addSubview(playerView as! UIView)
        (playerView as! UIView).isHidden = true
        (playerView as! UIView).frame = self.bounds
        (playerView as! UIView).backgroundColor = .clear

        addSubview(googleAdView as! UIView)
        (googleAdView as! UIView).isHidden = true
        (googleAdView as! UIView).frame = self.bounds
        (googleAdView as! UIView).backgroundColor = .clear

        addSubview(flowerAdUIView as! UIView)
        (flowerAdUIView as! UIView).isHidden = true
        (flowerAdUIView as! UIView).frame = self.bounds
        (flowerAdUIView as! UIView).backgroundColor = .clear

    }

    public func hide() {
        isHidden = true
        self.frame = CGRect(x: 0, y: 0, width: 0, height: 0)
        (playerView as! UIView).frame = self.bounds
        (playerView as! UIView).isHidden = true
        (googleAdView as! UIView).frame = self.bounds
        (googleAdView as! UIView).isHidden = true
        (flowerAdUIView as! UIView).frame = self.bounds
        (flowerAdUIView as! UIView).isHidden = true
    }

    public func show() {
        isHidden = false

        var screenWidth: CGFloat
        var screenHeight: CGFloat
        
        if let parentView = self.superview {
            screenWidth = parentView.bounds.width
            screenHeight = parentView.bounds.height
        } else {
            screenWidth = UIScreen.main.bounds.width
            screenHeight = UIScreen.main.bounds.height
        }

        // Calculate height based on the assumed 16:9 aspect ratio
        let height = screenWidth * (9.0 / 16.0)

        if height <= screenHeight {
            self.frame = CGRect(x: 0, y: (screenHeight - height) / 2, width: screenWidth, height: height)
        } else {
            let width = screenHeight * (16.0 / 9.0)
            self.frame = CGRect(x: (screenWidth - width) / 2, y: 0, width: width, height: screenHeight)
        }
        (playerView as! UIView).frame = self.bounds
        (playerView as! UIView).isHidden = false
        (playerView as! UIView).isHidden = false
        (googleAdView as! UIView).frame = self.bounds
        (googleAdView as! UIView).isHidden = false
        (flowerAdUIView as! UIView).frame = self.bounds
        (flowerAdUIView as! UIView).isHidden = false
    }

    public func isShow() -> Bool {
        return !isHidden
    }


    public func getHeight() -> Int32 {
        return Int32(frame.height)
    }

    public func getWidth() -> Int32 {
        return Int32(frame.width)
    }
}

public struct FlowerAdView: UIViewRepresentable {
    public var adView: FlowerAdViewInternal = FlowerAdViewInternal()
    public let observer: FlowerAdViewObserver
    
    public var adsManager: FlowerAdsManager {
        get {
            return adView.adsManager
        }
    }
    
    public init(observer: FlowerAdViewObserver) {
        self.observer = observer
        adView.observer = observer
    }
    
    public func makeCoordinator() -> Coordinator {
        Coordinator()
    }
    
    public  class Coordinator: NSObject {
        // You can add a coordinator if needed
    }

    public func makeUIView(context: Context) -> FlowerAdViewInternal {
        return adView
    }

    public func updateUIView(_ uiView: FlowerAdViewInternal, context: Context) {
        // Update the FlowerAdView here if needed
        adView.commonInit()
    }
    
    public func getAdView() -> FlowerAdViewInternal {
        return adView
    }
}

public protocol FlowerAdViewObserverInternal: AnyObject {
    func adViewDidChangeIsHidden(_ isHidden: Bool)
}

public class FlowerAdViewObserver: FlowerAdViewObserverInternal, ObservableObject {
    @Published public var isAdViewHidden = false
    public var showOrHideAdLayer: (() -> Void)?
    
    public init() {}
    
    public func adViewDidChangeIsHidden(_ isHidden: Bool) {
        isAdViewHidden = isHidden
    }
}
