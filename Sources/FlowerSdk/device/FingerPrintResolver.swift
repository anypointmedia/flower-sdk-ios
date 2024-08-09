import SwiftUI
import WebKit
import Combine

class FingerPrintResolverViewModel: ObservableObject {
    @Published public var isVisibie = true
    public var fingerPrintId = PassthroughSubject<String?, Never>()
}

struct FingerPrintResolver: View {
    @ObservedObject var viewModel = FingerPrintResolverViewModel()

    var body: some View {
        if (viewModel.isVisibie) {
            FingerPrintResolverRepresentable(viewModel: viewModel)
            .frame(maxWidth: 0, maxHeight: 0)
            .edgesIgnoringSafeArea(.all)
        }
    }

    struct FingerPrintResolverRepresentable: UIViewRepresentable {
        let FINGERPRINT_HTML = """
<!DOCTYPE html>
<html lang="en">
<head>
  <script type="application/javascript" src="https://cdn.jsdelivr.net/npm/@fingerprintjs/fingerprintjs@3.4.2/dist/fp.min.js"></script>
  <script>
    FingerprintJS.load()
      .then(function (fp) { return fp.get(); })
      .then(function (result) { return document.body.innerHTML = result.visitorId.replace(/^(.{8})(.{4})(.{4})(.{4})(.{12})$/, '$1-$2-$3-$4-$5'); });
  </script>
</head>
<body style="color: transparent"></body>
</html>
"""

        @ObservedObject var viewModel: FingerPrintResolverViewModel

        func makeUIView(context: Context) -> WKWebView {
            var webView = WKWebView(frame: .zero)

            webView.scrollView.contentInset = .zero
            webView.scrollView.contentInsetAdjustmentBehavior = .never
            webView.isOpaque = false
            webView.scrollView.backgroundColor = UIColor.black

            webView.navigationDelegate = context.coordinator
            webView.loadHTMLString(FINGERPRINT_HTML, baseURL: nil)

            return webView
        }

        func updateUIView(_ webView: WKWebView, context: Context) {
            webView.scrollView.contentInset = .zero
            print("updateUIView")
        }

        func makeCoordinator() -> Coordinator {
            Coordinator(parent: self)
        }

        class Coordinator: NSObject, WKNavigationDelegate {
            let FINGERPRINT_WAIT_DELAY = 100
            let FINGERPRINT_WAIT_TIMEOUT = 3_000

            var parent: FingerPrintResolverRepresentable

            init(parent: FingerPrintResolverRepresentable) {
                self.parent = parent
            }

            func webView(_ webView: WKWebView, didFinish: WKNavigation!) {
                DispatchQueue.global(qos: .default).async {
                    var fingerPrintId: String? = nil
                    let startTime = Int64(NSDate().timeIntervalSince1970 * 1000)

                    while (true) {
                        if (fingerPrintId != nil) {
                            break
                        }

                        let now = Int64(NSDate().timeIntervalSince1970 * 1000)

                        if (now - startTime > self.FINGERPRINT_WAIT_TIMEOUT) {
                            print("Timeout while resolving fingerprint")
                            break
                        }

                        DispatchQueue.main.async {
                            webView.evaluateJavaScript("document.body.innerText") { (result, error) in
                                if let content = result as? String {
                                    if (!content.isEmpty) {
                                        fingerPrintId = content
                                    }
                                }
                            }
                        }

                        usleep(useconds_t(self.FINGERPRINT_WAIT_DELAY * 1000))
                    }

                    self.onFinish(webView: webView, fingerPrintId: fingerPrintId)
                }
            }

            func webView(_ webView: WKWebView, didFailProvisionalNavigation: WKNavigation!, withError: Error) {
                print("Failed while ProvisionalNavigation of fingerprint html")
                onFinish(webView: webView, fingerPrintId: nil)
            }

            func webView(_ webView: WKWebView, didFail navigation: WKNavigation!, withError error: Error) {
                print("Failed while Navigation of fingerprint html")
                onFinish(webView: webView, fingerPrintId: nil)
            }

            func onFinish(webView: WKWebView, fingerPrintId: String?) -> Void {
                DispatchQueue.main.async {
                    webView.stopLoading()
                    webView.navigationDelegate = nil
                    webView.removeFromSuperview()
                    self.parent.viewModel.fingerPrintId.send(fingerPrintId)
                    self.parent.viewModel.isVisibie = false
                }
            }
        }
    }
}
