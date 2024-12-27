import QtQuick

Rectangle {
    id: createNewListScreen
    Header {
        id: header2
        width: 200
        Text {
            id: listClickableTxt
            text: qsTr("My List")
            color: "blue"
            font { pixelSize: 20; bold: true; underline: true; }
            anchors { verticalCenter: parent.verticalCenter; left: parent.left; leftMargin: 90 }

            MouseArea {
                id: mouseClicableLogoTxt
                anchors.fill: listClickableTxt
                cursorShape: Qt.PointingHandCursor

                onClicked: windowStackView.pop()
            }
        }
    }
}
