import UIKit

@MainActor
protocol VendorIdentifierProviding {
    var identifierForVendor: UUID? { get }
}

extension UIDevice: VendorIdentifierProviding {}
