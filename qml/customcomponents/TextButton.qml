import QtQuick 2.5

Text {
    signal btnClicked

    text: qsTr("Cancel")
    font { pixelSize: 12; underline: true }
    color: "red"

    MouseArea {
        anchors.fill: parent
        cursorShape: Qt.PointingHandCursor

        onClicked: btnClicked()
    }
}
