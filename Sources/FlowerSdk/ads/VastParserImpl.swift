import Foundation
import core
import Fuzi

class VastParserImplFactory: SdkContainerBeanFactory {
    func create(args: KotlinArray<AnyObject>) -> Any {
        return VastParserImpl()
    }
}

class VastParserImpl: VastParser {
    /**
     Not used by anywhere but need to keep it to prevent garbage collection
     https://github.com/cezheng/Fuzi/issues/1
     */
    private var xmlDocument: XMLDocument?

    override func parseAdNodes(text: String) throws -> PlatformList<XmlNodeWrapper> {
        xmlDocument = try XMLDocument(string: text, encoding: .utf8)

        return PlatformList(storage: xmlDocument!.xpath("//VAST/Ad").map { XmlNodeWrapperImpl(node: $0) })
    }

    override func applyMediaLoadJob(creative: Creative, adId: String) {
        switch mediaType {
        case "application/x-mpegURL":
            creative.mediaLoadJob = CommonJobImpl(
                    originalJob: Task {
                        creative.m3u8s = try await VastParserKt.parseM3u8(mediaUrl: creative.mediaUrl, cacheManager: cacheManager, creativeId: creative.id)
                    }
            )
        case "application/dash+xml":
            creative.mediaLoadJob = CommonJobImpl(
                    originalJob: Task {
                        creative.mpd = try await VastParserKt.parseMpd(mediaUrl: creative.mediaUrl, cacheManager: cacheManager, adId: adId, creativeId: creative.id)
                    }
            )
        default:
            break
        }
    }

    override func evaluateXPath(node: XmlNodeWrapper, expression: String) -> PlatformList<XmlNodeWrapper> {
        do {
            let element = (node.node as! XMLElement)
            let xPathResult = try element.xpath(expression)

            return PlatformList(storage: xPathResult.map { XmlNodeWrapperImpl(node: $0) })
        } catch {
            return PlatformList(storage: [])
        }
    }
}

internal class XmlNodeWrapperImpl: XmlNodeWrapper {
    init (node: XMLElement) {
        self.node = node
    }

    var node: Any

    func getAttribute(name: String) -> String? {
        (node as! XMLElement).attributes[name]
    }

    var childNodes: PlatformList<XmlNodeWrapper> {
        PlatformList(storage: (node as! XMLElement).children.map { XmlNodeWrapperImpl(node: $0) })
    }


    var nodeName: String {
        (node as! XMLElement).tag!
    }

    var parentNode: XmlNodeWrapper {
        XmlNodeWrapperImpl(node: (node as! XMLNode).parent!)
    }

    var textContent: String {
        (node as! XMLNode).stringValue
    }
}
