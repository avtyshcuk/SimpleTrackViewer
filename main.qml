import QtQuick 2.5
import QtQuick.Window 2.2

import com.company.media 1.0

Window {
    id: root
    visible: true
    width: 340
    height: 480
    title: qsTr("Simple Track Viewer")

    ListView {
        id: trackList
        anchors.fill: parent
        anchors.margins: 2
        spacing: 2
        model: TrackModel { id: trackModel }

        delegate: Rectangle {
            id: trackEntry
            color: "teal"
            radius: 5
            width: parent.width
            height: internal.entryHeight

            Text {
                anchors.centerIn: parent
                text: title
            }

            Image {
                id: trackCover
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
                width: internal.imageSize
                height: internal.imageSize
                anchors.margins: internal.entryMargin
                source: picture
            }

            AnimatedImage {
                id: nowPlayingIndicator
                visible: isPlaying
                anchors.right: parent.right
                anchors.verticalCenter: parent.verticalCenter
                width: internal.imageSize
                height: internal.imageSize
                anchors.margins: internal.entryMargin
                source: internal.nowPlayingIcon
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    trackModel.play(index);
                }
            }
        }
    }

    QtObject {
        id: internal
        property int entryHeight: 48
        property int imageSize: entryHeight - 10
        property int entryMargin: 5
        property string nowPlayingIcon: "qrc:/equalizer.gif"
    }
}
