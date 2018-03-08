import QtQuick 2.0
import Sailfish.Silica 1.0


Page {
    id: page

    SilicaListView {
        id: listView
        model: spotifyConnectModel
        anchors.fill: parent
        header: PageHeader {
            title: qsTr("Connect Page")
        }
        delegate: BackgroundItem {
            id: delegate

            Label {
                x: Theme.horizontalPageMargin
                text: qsTr("Name") + " " + name
                anchors.verticalCenter: parent.verticalCenter
                color: delegate.highlighted ? Theme.highlightColor : Theme.primaryColor
            }
        }
        VerticalScrollDecorator {}
        Connections {
            target: spotifyConnectModel
            onError: console.log(error)
        }
    }
}
