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
        .package(url: "https://github.com/cezheng/Fuzi", from: "3.1.3"),
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
                "Fuzi"
            ]
        ),
    ]
)
