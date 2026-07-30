// swift-tools-version: 5.9

import PackageDescription

let package = Package(
    name: "FlowerSdk",
    platforms: [
        .iOS(.v15)
    ],
    products: [
        .library(
            name: "FlowerSdk",
            targets: ["FlowerSdk"]),
    ],
    dependencies: [
        // Pulled in automatically so `canImport(ProgrammaticAccessLibrary)` holds and
        // GooglePalManagerImpl is used instead of GooglePalManagerDummyImpl.
        .package(
            url: "https://github.com/googleads/swift-package-manager-google-programmatic-access-library-ios",
            from: "3.2.3"
        ),
    ],
    targets: [
        .binaryTarget(
            name: "sdk_core",
            path: "Frameworks/sdk_core.xcframework"
        ),
        .target(
            name: "FlowerSdk",
            dependencies: [
                "sdk_core",
                .product(
                    name: "GoogleProgrammaticAccessLibrary",
                    package: "swift-package-manager-google-programmatic-access-library-ios"
                ),
            ]
        ),
    ]
)
