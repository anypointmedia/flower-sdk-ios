import Foundation
import sdk_core

class KeyValueStoreImpl: KeyValueStore {
    private let defaults = UserDefaults.standard
    private let prefix: String

    public init(prefix: String) {
        self.prefix = prefix
    }

    func hasKey(key: String) -> Bool {
        defaults.object(forKey: prefix + key) != nil
    }

    func getBoolean(key: String) -> KotlinBoolean? {
        guard let value = defaults.object(forKey: prefix + key) as? Bool else {
            return nil
        }

        return KotlinBoolean(value: value)
    }

    func putBoolean(key: String, value: Bool) {
        defaults.set(value, forKey: prefix + key)
        defaults.synchronize()
    }

    func getInt(key: String) -> KotlinInt? {
        guard let value = defaults.object(forKey: prefix + key) as? Int32 else {
            return nil
        }

        return KotlinInt(value: Int32(value))
    }

    func putInt(key: String, value: Int32) {
        defaults.set(value, forKey: prefix + key)
        defaults.synchronize()
    }

    func getFloat(key: String) -> KotlinFloat? {
        guard let value = defaults.object(forKey: prefix + key) as? Float else {
            return nil
        }

        return KotlinFloat(value: value)
    }

    func putFloat(key: String, value: Float) {
        defaults.set(value, forKey: prefix + key)
        defaults.synchronize()
    }

    func getString(key: String) -> String? {
        defaults.string(forKey: prefix + key)
    }

    func putString(key: String, value: String) {
        defaults.set(value, forKey: prefix + key)
        defaults.synchronize()
    }

    func remove(key: String) {
        defaults.removeObject(forKey: prefix + key)
        defaults.synchronize()
    }
}
