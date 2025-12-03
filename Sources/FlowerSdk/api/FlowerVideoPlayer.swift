import SwiftUI
import AVKit

public struct FlowerVideoPlayer: View {
    private var player: FlowerAVPlayer

    public init(player: FlowerAVPlayer) {
        self.player = player
    }

    public var body: some View {
        ZStack {
            VideoPlayer(player: player)
            player.flowerAdView.body
        }
    }
}
