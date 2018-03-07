import QtQuick 2.0
import Sailfish.Silica 1.0
import QtWebKit.experimental 1.0

Page {
    id: page

    SilicaWebView {
        id: webView
        anchors.fill: parent
        url: spotifyWrapper.spotifyPlayer
        experimental.preferences.developerExtrasEnabled: true

        Connections {
            target: spotifyWrapper
            onTokenChanged: webView.reload()
        }
    }
}
