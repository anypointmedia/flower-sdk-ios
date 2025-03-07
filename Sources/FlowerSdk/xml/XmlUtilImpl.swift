import Foundation
import sdk_core

class XmlUtilImpl: XmlUtil {
    func parseXml(text: String) throws -> XmlNode {
        let xmlDocument = try RefOtt_XMLDocument(string: text, encoding: .utf8)

        return XmlNodeImpl(node: xmlDocument.root as! RefOtt_XMLNode, rootNode: xmlDocument)
    }
}
