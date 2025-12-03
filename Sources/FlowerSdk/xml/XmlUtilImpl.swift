import Foundation
import sdk_core
import libxml2

class XmlUtilImpl: XmlUtil {
    func parseXml(text: String) throws -> XmlNode {
        let options = Int32(XML_PARSE_NOWARNING.rawValue | XML_PARSE_NOERROR.rawValue | XML_PARSE_RECOVER.rawValue)
        guard let cChars = text.cString(using: .utf8) else {
            throw NSError(domain: "XmlUtilImpl", code: -1)
        }
        guard let doc = xmlReadMemory(cChars, Int32(cChars.count), "", nil, options) else {
            throw NSError(domain: "XmlUtilImpl", code: -2)
        }
        guard let root = xmlDocGetRootElement(doc) else {
            xmlFreeDoc(doc)
            throw NSError(domain: "XmlUtilImpl", code: -3)
        }
        let holder = LibxmlDocumentHolder(doc: doc)
        return XmlNodeImpl(node: root, rootNode: holder)
    }
}
