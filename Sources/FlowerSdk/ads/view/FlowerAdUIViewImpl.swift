import Foundation
import UIKit
import sdk_core

class FlowerAdUIViewImpl: UIView, FlowerAdUIView {
    private let viewMoreButton = UIButton(type: .system)
    private var showingAd: Ad?
    internal var isClicked: Bool = false
    var isShowingQR: Bool = false

    // TODO: Remove when pip flags are no longer needed
    private var isUsingPip: Bool = false

    func showClickUi(ad: Ad, postClick: @escaping () -> Void) {
        
        if ad.click?.clickThroughUrl == nil { return }
        if showingAd == ad {
            return
        } else {
            viewMoreButton.removeFromSuperview()
        }
        
        
        let uiModeManager = UIDevice.current.userInterfaceIdiom
        if uiModeManager == .tv {

        } else if uiModeManager == .phone {

        } else if uiModeManager == .pad {

        } else {

        }

        // TODO: Implement Pip checxk
        //        if isContextPipAvailable(context) {
        //            if let activity = context as? UIViewController, activity.isInPictureInPictureMode {
        //                return
        //            }
        //        }

        showingAd = ad
        viewMoreButton.setTitle("View More", for: .normal)
        viewMoreButton.translatesAutoresizingMaskIntoConstraints = false
        viewMoreButton.setTitleColor(.white, for: .normal)
        viewMoreButton.backgroundColor = UIColor(red: 52/255, green: 152/255, blue: 219/255, alpha: 1)
        viewMoreButton.layer.cornerRadius = 8
        viewMoreButton.titleLabel?.font = UIFont.systemFont(ofSize: 16, weight: .semibold)

        addSubview(viewMoreButton)

        viewMoreButton.isHidden = false

        NSLayoutConstraint.activate([
            viewMoreButton.bottomAnchor.constraint(equalTo: bottomAnchor, constant: -20),
            viewMoreButton.trailingAnchor.constraint(equalTo: trailingAnchor, constant: -20),
            viewMoreButton.heightAnchor.constraint(equalToConstant: 40),
            viewMoreButton.widthAnchor.constraint(equalToConstant: 120)
        ])

        viewMoreButton.addTarget(self, action: #selector(viewMoreButtonTapped(_:)), for: .touchUpInside)

        // Store the postClick closure to be called when the button is tapped
        objc_setAssociatedObject(viewMoreButton, &AssociatedKeys.postClickClosure, postClick, .OBJC_ASSOCIATION_COPY_NONATOMIC)
    }

    func hideClickUi(ad: Ad) {
        if showingAd == ad {
            viewMoreButton.isHidden = true
//            viewMoreButton.removeFromSuperview()
            showingAd = nil
        }
    }

    func show() {
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
            self.frame = CGRect(x: 0, y: 0, width: screenWidth, height: height)
        } else {
            let width = screenHeight * (16.0 / 9.0)
            self.frame = CGRect(x: 0, y: 0, width: width, height: screenHeight)
        }
    }


    func hide() {
        isHidden = true
        self.frame = CGRect(x: 0, y: 0, width: 0, height: 0)
    }


    func isShow() -> Bool {
        return !isHidden
    }

    private func handleViewMoreClick(click: Ad.Click) {
        guard let clickThroughUrl = click.clickThroughUrl else {
            return
        }

        // TODO: Implement pip
//        if (isContextPipAvailable(context)) {
//            if (!(context as Activity).isInPictureInPictureMode) {
//                if (context.packageManager.hasSystemFeature(PackageManager.FEATURE_PICTURE_IN_PICTURE)) {
//                    val aspectRatio = Rational(16, 9)
//                    val params = PictureInPictureParams.Builder()
//                        .setAspectRatio(aspectRatio)
//                        .build()
//
//                    (context as Activity).enterPictureInPictureMode(params)
//                }
//            }
//        }

        if let url = URL(string: clickThroughUrl), UIApplication.shared.canOpenURL(url) {
            UIApplication.shared.open(url, options: [:], completionHandler: nil)
        }
    }

    @objc private func viewMoreButtonTapped(_ sender: UIKit.UIButton) {
        if let postClick = objc_getAssociatedObject(viewMoreButton, &AssociatedKeys.postClickClosure) as? () -> Void {
            postClick()
        }

        if let ad = showingAd, let click = ad.click {
            handleViewMoreClick(click: click)
        }
    }

    private struct AssociatedKeys {
        static var postClickClosure = "postClickClosure"
    }

    // TODO: Implement pip
//    fun isContextPipAvailable(context: Context): Boolean {
//        return isUsingPip && context is Activity && Build.VERSION.SDK_INT >= Build.VERSION_CODES.O
//    }


    func getHeight() -> Int32 {
        return Int32(frame.height)
    }

    func getWidth() -> Int32 {
        return Int32(frame.width)
    }

    func hideQRWithCountDown() {
        // TODO: Implementå
    }
}
