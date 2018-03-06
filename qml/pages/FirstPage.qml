import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    id: page

    SilicaWebView {
        id: webView
        anchors.fill: parent

        Connections {
            target: spotifyWrapper
            onTokenChanged: {
                webView.url = spotifyWrapper.spotifyPlayer;
                webView.reload();
            }
        }
    }
}
