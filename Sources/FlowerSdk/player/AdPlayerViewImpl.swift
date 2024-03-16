import Foundation
import SwiftUI
import UIKit
import sdk_core

class AdPlayerViewImpl: UIView, AdPlayerView {

    func getHeight() -> Int32 {
        return Int32(frame.height)
    }

    func getWidth() -> Int32 {
        return Int32(frame.width)
    }

    func hide() {
        isHidden = true
        self.frame = CGRect(x: 0, y: 0, width: 0, height: 0)
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

    func isShow() -> Bool {
        return !isHidden
    }

}
