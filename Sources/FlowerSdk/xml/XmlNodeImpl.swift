import Foundation
import sdk_core
import libxml2

final class LibxmlDocumentHolder {
    let doc: xmlDocPtr
    init(doc: xmlDocPtr) { self.doc = doc }
    deinit { xmlFreeDoc(doc) }
}

class XmlNodeImpl: XmlNode {

    init(node: xmlNodePtr, rootNode: Any) {
        super.init(node: node, rootNode: rootNode)
    }

    private func nodePtr() -> xmlNodePtr { node as! xmlNodePtr }
    private func docHolder() -> LibxmlDocumentHolder { rootNode as! LibxmlDocumentHolder }

    override func childNodes() -> PlatformList<XmlNode> {
        var result: [XmlNode] = []
        var cur = nodePtr().pointee.children
        while let n = cur {
            if n.pointee.type == XML_ELEMENT_NODE {
                result.append(XmlNodeImpl(node: n, rootNode: rootNode))
            }
            cur = n.pointee.next
        }
        return PlatformList(array: result)
    }

    override func getAttribute(name: String) -> String? {
        return name.withCString { cStr -> String? in
            let xmlName = cStr.withMemoryRebound(to: xmlChar.self, capacity: name.utf8.count) { $0 }
            if let val = xmlGetProp(nodePtr(), xmlName) {
                defer { xmlFree(val) }
                let cchar = UnsafeRawPointer(val).assumingMemoryBound(to: CChar.self)
                return String(cString: cchar)
            }
            return nil
        }
    }

    override func getNode(xpathExp: String) -> XmlNode? {
        guard let ctx = xmlXPathNewContext(docHolder().doc) else { return nil }
        defer { xmlXPathFreeContext(ctx) }
        if nodePtr().pointee.type != XML_DOCUMENT_NODE {
            ctx.pointee.node = nodePtr()
        }
        registerNamespaces(ctx, from: nodePtr())
        let xpathObj: xmlXPathObjectPtr? = xpathExp.withCString { cStr in
            cStr.withMemoryRebound(to: xmlChar.self, capacity: xpathExp.utf8.count) { xmlStr in
                xmlXPathEvalExpression(xmlStr, ctx)
            }
        }
        guard let obj = xpathObj, let set = obj.pointee.nodesetval, set.pointee.nodeNr > 0, let first = set.pointee.nodeTab?[0] else {
            if let obj = xpathObj { xmlXPathFreeObject(obj) }
            return nil
        }
        xmlXPathFreeObject(obj)
        return XmlNodeImpl(node: first, rootNode: rootNode)
    }

    override func getNodeList(xpathExp: String) -> PlatformList<XmlNode> {
        guard let ctx = xmlXPathNewContext(docHolder().doc) else { return PlatformList(array: []) }
        defer { xmlXPathFreeContext(ctx) }
        if nodePtr().pointee.type != XML_DOCUMENT_NODE {
            ctx.pointee.node = nodePtr()
        }
        registerNamespaces(ctx, from: nodePtr())
        let xpathObj: xmlXPathObjectPtr? = xpathExp.withCString { cStr in
            cStr.withMemoryRebound(to: xmlChar.self, capacity: xpathExp.utf8.count) { xmlStr in
                xmlXPathEvalExpression(xmlStr, ctx)
            }
        }
        guard let obj = xpathObj, let set = obj.pointee.nodesetval, let tab = set.pointee.nodeTab else {
            if let obj = xpathObj { xmlXPathFreeObject(obj) }
            return PlatformList(array: [])
        }
        var arr: [XmlNode] = []
        let count = Int(set.pointee.nodeNr)
        for i in 0..<count {
            if let n = tab[i] {
                arr.append(XmlNodeImpl(node: n, rootNode: rootNode))
            }
        }
        xmlXPathFreeObject(obj)
        return PlatformList(array: arr)
    }

    override func nodeName() -> String {
        guard let name = nodePtr().pointee.name else { return "" }
        let cchar = UnsafeRawPointer(name).assumingMemoryBound(to: CChar.self)
        return String(cString: cchar)
    }

    override func parentNode() -> XmlNode {
        return XmlNodeImpl(node: nodePtr().pointee.parent!, rootNode: rootNode)
    }

    override func textContent() -> String {
        guard let content = xmlNodeGetContent(nodePtr()) else { return "" }
        defer { xmlFree(content) }
        let cchar = UnsafeRawPointer(content).assumingMemoryBound(to: CChar.self)
        return String(cString: cchar)
    }

    override func clone() -> XmlNode {
        return XmlNodeImpl(node: nodePtr(), rootNode: rootNode)
    }

    private func registerNamespaces(_ ctx: xmlXPathContextPtr, from start: xmlNodePtr) {
        var cur: xmlNodePtr? = start
        while let node = cur {
            var ns = node.pointee.nsDef
            while let nsp = ns {
                if let href = nsp.pointee.href, let prefix = nsp.pointee.prefix {
                    _ = xmlXPathRegisterNs(ctx, prefix, href)
                }
                ns = nsp.pointee.next
            }
            cur = node.pointee.parent
        }
        if let root = xmlDocGetRootElement(docHolder().doc) {
            var ns = root.pointee.nsDef
            while let nsp = ns {
                if let href = nsp.pointee.href, let prefix = nsp.pointee.prefix {
                    _ = xmlXPathRegisterNs(ctx, prefix, href)
                }
                ns = nsp.pointee.next
            }
        }
    }
}
