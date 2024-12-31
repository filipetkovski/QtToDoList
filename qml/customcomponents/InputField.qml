import QtQuick 2.5
import QtQuick.Controls

Rectangle {
        property alias text: inputFieldTxtId.text
        property alias textTitle: titleInputFieldId.text
        property alias titleSize: titleInputFieldId.font.pixelSize
        property alias inputTxtSize: inputFieldTxtId.font.pixelSize
        property alias inputFieldId: inputFieldId

        Text {
            id: titleInputFieldId
            text: "Name your new list:"
            font { bold: true; }
            anchors { top: parent.top; left: parent.left; topMargin: 2; }
        }

        Rectangle {
            id: inputFieldId
            width: parent.width / 2
            height: 30
            anchors { top: titleInputFieldId.bottom; topMargin: 2; left: parent.left; }
            border { width: 1; color: "black"; }

            // Text field for user input
            TextInput {
                id: inputFieldTxtId
                anchors { fill: inputFieldId; margins: 5; }
                font.family: "Sans"
                focus: true

                MouseArea {
                    anchors.fill: parent
                    cursorShape: Qt.IBeamCursor

                    onClicked: inputFieldTxtId.forceActiveFocus()
                }
            }
        }
    }
