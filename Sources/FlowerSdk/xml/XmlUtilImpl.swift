import Foundation
import core
import Fuzi

class XmlUtilImpl: XmlUtil {
    func parseXml(text: String) throws -> XmlNode {
        let xmlDocument = try XMLDocument(string: text, encoding: .utf8)

        return XmlNodeImpl(node: xmlDocument.root as! XMLNode, rootNode: xmlDocument)
    }
}
