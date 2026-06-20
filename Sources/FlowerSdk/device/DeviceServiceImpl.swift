import Foundation
import sdk_core
import UIKit
import AdSupport
import AppTrackingTransparency
import Combine
import CryptoKit

class DeviceServiceImpl: DeviceService {
    let keyValueStore: KeyValueStore = KeyValueStoreImpl(prefix: "FlowerSDK_")

    private let logger = FLogging(tag: "DeviceServiceImpl").logger

    private var appleAdId: String? = nil
    private var fingerPrintId: String? = nil
    private var deviceUuid: String? = nil
    private var appName: String? = nil

    init() {
        Task {
            loadAppleAdId()
            await loadFingerprintId()
            loadDeviceUuid()
        }
    }

    private func loadAppleAdId() {
        let adId = ASIdentifierManager.shared().advertisingIdentifier.uuidString

        if adId == "" || adId == "00000000-0000-0000-0000-000000000000" {
            logger.warn { "Apple Ads ID is disabled." }
            return
        }

        appleAdId = adId
        logger.info { "Load Apple Ads ID: \(adId)" }
    }

    private func loadFingerprintId() async {
        // stabilityLevel: stable vs optimal vs unique
        // optimal 및 unique는 하나의 기기에서도 앱마다 다른 값이 로드됨
        // https://github.com/fingerprintjs/fingerprintjs-ios?tab=readme-ov-file#fingerprint-stability-levels
        let configuration = Configuration(version: .v6, stabilityLevel: .stable, algorithm: .sha256)
        let fingerprinter = FingerprinterFactory.getInstance(configuration)
        if let fingerprint = await fingerprinter.getFingerprint() {
            if fingerprint != "" {
                fingerPrintId = uuidFromSeed(seed: fingerprint)
                logger.info { "Load fingerprint ID: \(self.fingerPrintId ?? "none")(\(fingerprint))" }
                return
            }
        }

        logger.warn { "Failed to load Fingerprint ID." }
    }

    private func loadDeviceUuid() {
        let savedDeviceId = keyValueStore.getString(key: DeviceServiceCompanion().DEVICE_ID_KEY)
        if savedDeviceId == nil || savedDeviceId == "" {
            setDeviceId(deviceId: generateUuid())
        } else {
            logger.info { "Load existing deviceId: \(savedDeviceId!)" }
            deviceUuid = savedDeviceId
        }
    }

    private func generateUuid() -> String {
        if let appleAdId = appleAdId {
            return appleAdId
        }

        if let fingerPrintId = fingerPrintId {
            return fingerPrintId
        }

        return UUID().uuidString
    }

    func getDeviceId() -> String? {
        deviceUuid
    }

    func setDeviceId(deviceId: String) {
        logger.info { "reset deviceId: \(deviceId)" }
        deviceUuid = deviceId
        keyValueStore.putString(key: DeviceServiceCompanion().DEVICE_ID_KEY, value: deviceId)
    }

    func getFwVer() -> String? {
        UIDevice().systemVersion
    }

    func getIPAddress(useIPv4: Bool = true) -> String? {
        var address: String?

        var ifaddr: UnsafeMutablePointer<ifaddrs>?
        guard getifaddrs(&ifaddr) == 0 else { return nil }
        guard let firstAddr = ifaddr else { return nil }

        for ifptr in sequence(first: firstAddr, next: { $0.pointee.ifa_next }) {
            let interface = ifptr.pointee

            let addrFlags = Int32(ifptr.pointee.ifa_flags)
            if (addrFlags & (IFF_UP|IFF_RUNNING|IFF_LOOPBACK)) != (IFF_UP|IFF_RUNNING) {
                continue
            }

            let addr = interface.ifa_addr.pointee
            if addr.sa_family != UInt8(AF_INET) && addr.sa_family != UInt8(AF_INET6) {
                continue
            }

            var hostname = [CChar](repeating: 0, count: Int(NI_MAXHOST))
            if (getnameinfo(interface.ifa_addr, socklen_t(interface.ifa_addr.pointee.sa_len), &hostname, socklen_t(hostname.count), nil, 0, NI_NUMERICHOST) == 0) {
                let addressStr = String(cString: hostname)
                if useIPv4 && addr.sa_family == UInt8(AF_INET) {
                    if isIPv4PrivateAddress(addressStr) {
                        address = addressStr
                        break
                    }
                } else if !useIPv4 && addr.sa_family == UInt8(AF_INET6) {
                    let stripped: String
                    if addressStr.contains("%") {
                        stripped = addressStr.components(separatedBy: "%").first.map { String($0) } ?? addressStr
                    } else {
                        stripped = addressStr
                    }
                    if isIPv6UniqueLocalAddress(stripped) {
                        address = stripped.uppercased()
                        break
                    }
                }
            }
        }
        freeifaddrs(ifaddr)

        return address
    }

    private func isIPv4PrivateAddress(_ addr: String) -> Bool {
        // RFC 1918: 10.0.0.0/8, 172.16.0.0/12, 192.168.0.0/16.
        if addr.hasPrefix("10.") || addr.hasPrefix("192.168.") {
            return true
        }
        if addr.hasPrefix("172.") {
            let parts = addr.split(separator: ".")
            if parts.count >= 2, let second = Int(parts[1]), (16...31).contains(second) {
                return true
            }
        }
        return false
    }

    private func isIPv6UniqueLocalAddress(_ addr: String) -> Bool {
        // RFC 4193 ULA occupies fc00::/7 (first hextet starts with fc or fd).
        let lower = addr.lowercased()
        return lower.hasPrefix("fc") || lower.hasPrefix("fd")
    }

    func getLocale() -> String? {
        Locale.preferredLanguages.first
    }

    func getModel() -> String? {
        UIDevice().model
    }

    func getUserAgent() -> String {
        let appPackage = Bundle.main.bundleIdentifier ?? "unknown"
        let appVersion = Bundle.main.infoDictionary?["CFBundleShortVersionString"] as? String ?? "0.0"
        let iosVersion = UIDevice().systemVersion
        let deviceModel = RefOtt_Device.current

        if UIDevice.current.userInterfaceIdiom == .tv {
            return "\(appPackage)/\(appVersion) Smart-TV (iOS \(iosVersion)) CTV(Connected TV)"
        } else {
            return "\(appPackage)/\(appVersion) (iOS \(iosVersion);\(deviceModel))"
        }
    }

    func getPlatformAdId() -> String? {
        return appleAdId
    }

    func isTv() -> Bool {
        return UIDevice.current.userInterfaceIdiom == .tv
    }

    func isSamsungTv() -> Bool {
        return false
    }

    func isSupportHls() -> Bool {
        return true
    }

    func isSupportDash() -> Bool {
        return false
    }

    func isAdTrackingEnabled() -> Bool {
        if #available(iOS 14, tvOS 14, *) {
            switch ATTrackingManager.trackingAuthorizationStatus {
            case .denied, .restricted:
                return false
            case .authorized, .notDetermined:
                return true
            @unknown default:
                return true
            }
        }
        return true
    }

    func getAppName() -> String? {
        return appName
    }

    func setAppName(appName: String) {
        self.appName = appName
    }

    func getTimeZoneOffset() -> String {
        let timeZone = TimeZone.current
        let offsetSeconds = timeZone.secondsFromGMT()
        let offsetHours = Double(offsetSeconds) / 3600.0
        let formatted = String(format: "%.1f", offsetHours)
        return formatted.hasSuffix(".0") ? String(formatted.dropLast(2)) : formatted
    }

    private func uuidFromSeed(seed: String) -> String {
        let data = Data(seed.utf8)
        let md5 = Insecure.MD5.hash(data: data)

        var bytes = Array(md5)

        // RFC 4122 version 3
        bytes[6] = (bytes[6] & 0x0F) | 0x30
        bytes[8] = (bytes[8] & 0x3F) | 0x80

        let uuid = UUID(uuid: (
            bytes[0], bytes[1], bytes[2], bytes[3],
            bytes[4], bytes[5],
            bytes[6], bytes[7],
            bytes[8], bytes[9],
            bytes[10], bytes[11], bytes[12], bytes[13], bytes[14], bytes[15]
        ))

        return uuid.uuidString.lowercased()
    }
}
