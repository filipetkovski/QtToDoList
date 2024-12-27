import QtQuick

import "../customcomponents"

FocusScope {
    id: createNewListScreen
    property int modelIndex: -1

    Text {
        id: headerEditScreenId
        text: qsTr("Edit this list")
        font { pixelSize: 30; bold: true; }
    }

    TextButton {
        id: cancelBtnEditId
        anchors { top: headerEditScreenId.bottom; topMargin: 20; }
        onBtnClicked: windowStackView.pop()
    }

    TextButton {
        text: qsTr("Delete this list")
        anchors { left: cancelBtnEditId.right; leftMargin: 20; verticalCenter: cancelBtnEditId.verticalCenter }
        onBtnClicked: {
            toDoModelId.deleteList(modelIndex)
            windowStackView.pop()
            windowStackView.pop()
        }
    }
}
