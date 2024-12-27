import QtQuick
import QtQuick.Layouts

Rectangle {
    id: rowLayout
    height: 52
    color: Qt.color("#f1f1f1")
    radius: 25

    Image {
        id: logoImg
        width: 80
        height: 62
        source: "https://123.tadalist.com/images/tada-mark-bg.gif?1732271164"
        anchors.bottom: rowLayout.bottom
    }
}
