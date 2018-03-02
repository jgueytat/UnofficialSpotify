import QtQuick 2.0
import Sailfish.Silica 1.0


Page {
    id: page

    Button {
        text: "Spotify Connect"
        anchors.centerIn: parent
        onClicked: pageStack.push(Qt.resolvedUrl("ConnectPage.qml"))
    }
}
