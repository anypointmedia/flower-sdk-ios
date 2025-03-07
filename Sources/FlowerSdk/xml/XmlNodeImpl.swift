import Foundation
import sdk_core

class XmlNodeImpl: XmlNode {

    init(node: RefOtt_XMLNode, rootNode: Any) {
        super.init(node: node, rootNode: rootNode)
    }

    override func childNodes() -> PlatformList<XmlNode> {
        PlatformList(array: (node as! RefOtt_XMLElement).children.map({ XmlNodeImpl(node: $0, rootNode: rootNode) }))
    }

    override func getAttribute(name: String) -> String? {
        (node as! RefOtt_XMLElement).attributes[name]
    }

    override func getNode(xpathExp: String) -> XmlNode? {
        var nodeSet: RefOtt_NodeSet

        if node is RefOtt_XMLDocument {
            nodeSet = (node as! RefOtt_XMLDocument).xpath(xpathExp)
        } else {
            nodeSet = (node as! RefOtt_XMLElement).xpath(xpathExp)
        }

        return nodeSet.first.map { XmlNodeImpl(node: $0, rootNode: rootNode) }
    }

    override func getNodeList(xpathExp: String) -> PlatformList<XmlNode> {
        var nodeSet: RefOtt_NodeSet

        if node is RefOtt_XMLDocument {
            nodeSet = (node as! RefOtt_XMLDocument).xpath(xpathExp)
        } else {
            nodeSet = (node as! RefOtt_XMLElement).xpath(xpathExp)
        }

        return PlatformList(array: nodeSet.map { XmlNodeImpl(node: $0, rootNode: rootNode) })
    }

    override func nodeName() -> String {
        (node as! RefOtt_XMLElement).tag!
    }

    override func parentNode() -> XmlNode {
        XmlNodeImpl(node: (node as! RefOtt_XMLNode).parent!, rootNode: rootNode)
    }

    override func textContent() -> String {
        (node as! RefOtt_XMLNode).stringValue
    }

    override func clone() -> XmlNode {
        XmlNodeImpl(node: (node as! RefOtt_XMLNode), rootNode: rootNode)
    }
}
