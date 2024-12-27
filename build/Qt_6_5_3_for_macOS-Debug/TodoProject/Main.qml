import QtQuick
import QtQuick.VirtualKeyboard
import QtQuick.Layouts
import QtQuick.Controls

import ToDoModel 1.0

Window {
    id: applicationWindow
    width: Screen.width
    height: Screen.height
    visible: true
    title: qsTr("Flip's ToDo List")

    // property alias toDoFilterModelId: toDoFilterModelId

    ToDoFilterModel
    {
        id: toDoFilterModelId
        sourceModel: ToDoModel {
            id: toDoModelId
        }
        showActive: true
    }

    Rectangle {
        id: rec
        width: 800
        height: applicationWindow.height - 50
        color: "white"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        anchors.topMargin: 50

        StackView {
            id: windowStackView
            anchors.fill: rec

            pushEnter: Transition { XAnimator { duration: 0 } }
            pushExit: Transition { XAnimator { duration: 0 } }
            popEnter: Transition { XAnimator { duration: 0 } }
            popExit: Transition { XAnimator { duration: 0 } }

            initialItem: "HomeScreen.qml"
        }
    }
}
