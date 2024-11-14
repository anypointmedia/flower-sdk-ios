import Foundation
import sdk_core
import Fuzi

class XmlNodeImpl: XmlNode {

    init(node: XMLNode, rootNode: Any) {
        super.init(node: node, rootNode: rootNode)
    }

    override func childNodes() -> PlatformList<XmlNode> {
        PlatformList(array: (node as! XMLElement).children.map({ XmlNodeImpl(node: $0, rootNode: rootNode) }))
    }

    override func getAttribute(name: String) -> String? {
        (node as! XMLElement).attributes[name]
    }

    override func getNode(xpathExp: String) -> XmlNode? {
        var nodeSet: NodeSet

        if node is XMLDocument {
            nodeSet = (node as! XMLDocument).xpath(xpathExp)
        } else {
            nodeSet = (node as! XMLElement).xpath(xpathExp)
        }

        return nodeSet.first.map { XmlNodeImpl(node: $0, rootNode: rootNode) }
    }

    override func getNodeList(xpathExp: String) -> PlatformList<XmlNode> {
        var nodeSet: NodeSet

        if node is XMLDocument {
            nodeSet = (node as! XMLDocument).xpath(xpathExp)
        } else {
            nodeSet = (node as! XMLElement).xpath(xpathExp)
        }

        return PlatformList(array: nodeSet.map { XmlNodeImpl(node: $0, rootNode: rootNode) })
    }

    override func nodeName() -> String {
        (node as! XMLElement).tag!
    }

    override func parentNode() -> XmlNode {
        XmlNodeImpl(node: (node as! XMLNode).parent!, rootNode: rootNode)
    }

    override func textContent() -> String {
        (node as! XMLNode).stringValue
    }

    override func clone() -> XmlNode {
        XmlNodeImpl(node: (node as! XMLNode), rootNode: rootNode)
    }
}
