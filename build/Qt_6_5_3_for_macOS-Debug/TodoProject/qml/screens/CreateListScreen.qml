import QtQuick

import "../CustomComponents"

FocusScope {
    id: createNewListScreen
    Header {
        id: headerCreateScreenId
        width: 300
        Text {
            id: headerTxtBackLogoId
            text: qsTr("My List")
            color: "blue"
            font { pixelSize: 20; bold: true; underline: true; }
            anchors { verticalCenter: parent.verticalCenter; left: parent.left; leftMargin: 90 }

            MouseArea {
                id: clickTxtBackLogoId
                anchors.fill: headerTxtBackLogoId
                cursorShape: Qt.PointingHandCursor

                onClicked: windowStackView.pop()
            }
        }
    }

    InputField {
        id: inputCreateScreenId
        width: rec.width
        height: 100
        titleSize: 25
        inputTxtSize: 17
        anchors { top: headerCreateScreenId.bottom; topMargin: 20 }
    }

    Rectangle {
        anchors { top: inputCreateScreenId.bottom; topMargin: 20 }
        ConfirmButton {
            id: confirmCreateScreenId
            width: 120
            height: 35
            fontSize: 12
            pushUrlLocation: "../Screens/ToDoListScreen.qml"
            text: qsTr("Create this list")

            onBtnClicked: {
                toDoModelId.addList(inputCreateScreenId.text)
                windowStackView.pop()
                windowStackView.push(pushUrlLocation, {"idList": toDoModelId.getListSize()-1})
                inputCreateScreenId.text = ""
            }
        }

        TextButton {
            anchors { left: confirmCreateScreenId.right; leftMargin: 20; verticalCenter: confirmCreateScreenId.verticalCenter }
            onBtnClicked: windowStackView.pop()
        }
    }
}
