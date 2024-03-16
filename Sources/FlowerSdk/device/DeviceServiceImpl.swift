import Foundation
import sdk_core
import UIKit
import AdSupport

class DeviceServiceImpl: DeviceService {
    private let logger = sdk_core.LoggingKmLog()

    private var deviceUuid: String? = nil

    init () {
        loadDeviceUuid()
    }

    private func loadDeviceUuid() {
        let userDefaults = UserDefaults.standard
        let savedDeviceId = userDefaults.string(forKey: DeviceServiceCompanion().DEVICE_ID_KEY)
        if savedDeviceId == nil {
            setDeviceId(deviceId: UUID().uuidString)
        } else {
            logger.info { "exist deviceId: \(savedDeviceId!)" }
        }
    }

    func getDeviceId() -> String? {
        deviceUuid
    }

    func setDeviceId(deviceId: String) {
        logger.info { "reset deviceId: \(deviceId)" }
        deviceUuid = deviceId
        let userDefaults = UserDefaults.standard
        userDefaults.set(deviceUuid, forKey: DeviceServiceCompanion().DEVICE_ID_KEY)
        userDefaults.synchronize()
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
                    address = addressStr
                    break
                } else if !useIPv4 && addr.sa_family == UInt8(AF_INET6) {
                    if addressStr.contains("%") {
                        address = addressStr.components(separatedBy: "%").first?.uppercased()
                    } else {
                        address = addressStr.uppercased()
                    }

                    break
                }
            }
        }
        freeifaddrs(ifaddr)

        return address
    }

    func getLocale() -> String? {
        Locale.preferredLanguages.first
    }

    func getModel() -> String? {
        UIDevice().model
    }

    func getUserAgent() -> String? {
        nil
    }

    func getPlatformAdId() -> String? {
        let adId = ASIdentifierManager.shared().advertisingIdentifier.uuidString

        if adId == "00000000-0000-0000-0000-000000000000" {
            return nil
        }

        return adId
    }
}
