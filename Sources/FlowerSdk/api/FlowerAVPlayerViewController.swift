import UIKit
import AVKit

public class FlowerAVPlayerViewController: AVPlayerViewController {
    // `deinit` on this non-final, publicly-subclassable @MainActor-isolated view controller is
    // nonisolated by default (Swift can't guarantee isolated deinit across unknown subclasses),
    // yet it needs to tear down this view on teardown. Deinit is guaranteed to run with sole,
    // non-concurrent ownership of `self`, so `nonisolated(unsafe)` is safe here.
    private nonisolated(unsafe) var adHostingController: FlowerAdView.HostingController?
    private var flowerPlayer: FlowerAVPlayer?
    private lazy var adsManagerListener = AVPlayerViewControllerListener(controller: self)

    override public var player: AVPlayer? {
        didSet {
            setupAdView()
        }
    }

    override public func viewDidLoad() {
        super.viewDidLoad()
        setupAdView()
    }

    override public func viewDidLayoutSubviews() {
        super.viewDidLayoutSubviews()
        if let adHostingController = adHostingController, adHostingController.view.superview == contentOverlayView {
            contentOverlayView?.bringSubviewToFront(adHostingController.view)
        }
    }

    private func setupAdView() {
        self.adHostingController?.view.removeFromSuperview()
        self.adHostingController = nil

        if let flowerPlayer = self.flowerPlayer {
            flowerPlayer.removeAdListener(listener: adsManagerListener)
        }
        self.flowerPlayer = nil

        guard let flowerPlayer = player as? FlowerAVPlayer else {
            return
        }

        self.flowerPlayer = flowerPlayer

        let hostingController = FlowerAdView.HostingController(adView: flowerPlayer.flowerAdView)
        self.adHostingController = hostingController

        flowerPlayer.addAdListener(listener: adsManagerListener)

        guard let contentOverlayView = contentOverlayView else {
            return
        }

        contentOverlayView.addSubview(hostingController.view)
        hostingController.view.translatesAutoresizingMaskIntoConstraints = false

        NSLayoutConstraint.activate([
            hostingController.view.topAnchor.constraint(equalTo: contentOverlayView.topAnchor),
            hostingController.view.bottomAnchor.constraint(equalTo: contentOverlayView.bottomAnchor),
            hostingController.view.leadingAnchor.constraint(equalTo: contentOverlayView.leadingAnchor),
            hostingController.view.trailingAnchor.constraint(equalTo: contentOverlayView.trailingAnchor)
        ])

        contentOverlayView.bringSubviewToFront(hostingController.view)
    }

    deinit {
        if let flowerPlayer = self.flowerPlayer {
            flowerPlayer.removeAdListener(listener: adsManagerListener)
        }

        self.adHostingController?.view.removeFromSuperview()
    }
}

// `controller` is the only stored state and is an immutable reference set once at init;
// all mutations of its MainActor-isolated properties are always dispatched onto the main
// thread below, so it is safe to hand this type to `DispatchQueue.main.async`'s `@Sendable`
// closures without triggering Swift 6's conservative "sending" data-race diagnostics.
private class AVPlayerViewControllerListener: FlowerAdsManagerListener, @unchecked Sendable {
    func onAdPlay(adInfo: AdInfo) {
        
    }
    
    func onAdUserAction(action: String, adInfo: AdInfo) {
    }
    
    let controller: FlowerAVPlayerViewController

    init(controller: FlowerAVPlayerViewController) {
        self.controller = controller
    }

    public func onPrepare(adDurationMs: Int32) {
        DispatchQueue.main.async {
            self.controller.showsPlaybackControls = false
        }
    }

    public func onAdBreakPrepare(adInfos: NSMutableArray) {
        controller.showsPlaybackControls = false
    }
    
    public func onPlay() {
        DispatchQueue.main.async {
            self.controller.showsPlaybackControls = false
        }
    }

    public func onCompleted() {
        DispatchQueue.main.async {
            self.controller.showsPlaybackControls = true
        }
    }

    public func onError(error: FlowerError?) {
        DispatchQueue.main.async {
            self.controller.showsPlaybackControls = true
        }
    }

    public func onAdBreakSkipped(reason: Int32) {
        DispatchQueue.main.async {
            self.controller.showsPlaybackControls = true
        }
    }
}
