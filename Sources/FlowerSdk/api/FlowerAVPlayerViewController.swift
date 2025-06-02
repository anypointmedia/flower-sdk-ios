import UIKit
import AVKit

public class FlowerAVPlayerViewController: AVPlayerViewController {
    private var adHostingController: FlowerAdView.HostingController?
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

        let hostingController = FlowerAdView.HostingController(adView: flowerPlayer.getAdView())
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

private class AVPlayerViewControllerListener: FlowerAdsManagerListener {
    let controller: FlowerAVPlayerViewController

    init(controller: FlowerAVPlayerViewController) {
        self.controller = controller
    }

    public func onPrepare(adDurationMs: Int32) {
        controller.showsPlaybackControls = false
    }

    public func onPlay() {
        controller.showsPlaybackControls = false
    }

    public func onCompleted() {
        controller.showsPlaybackControls = true
    }

    public func onError(error: FlowerError?) {
        controller.showsPlaybackControls = true
    }

    public func onAdSkipped(reason: Int32) {
        controller.showsPlaybackControls = true
    }
}
