import QtQuick 2.5

Rectangle {
    property alias text: buttonTxtId.text
    property alias fontSize: buttonTxtId.font.pixelSize
    property string pushUrlLocation: ""

    signal btnClicked

    radius: width / 2
    border { width: 1; color: "black" }

    Text {
        id: buttonTxtId
        font { pixelSize: 15; bold: true; }
        anchors.centerIn: parent
        color: "black"
    }

    MouseArea {
        anchors.fill: parent
        cursorShape: Qt.PointingHandCursor

        onClicked: btnClicked()
    }
}
