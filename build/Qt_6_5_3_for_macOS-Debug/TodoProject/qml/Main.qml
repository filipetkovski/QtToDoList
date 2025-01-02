import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

import ToDoModel 1.0
import ListModel 1.0

import "CustomComponents"
import "Screens"

Window {
    id: applicationWindow
    width: Screen.width
    height: Screen.height
    visible: true
    title: qsTr("Filip's ToDo List")

    ToDoModel {
        id: toDoModelId
    }

    ToDoFilterModel
    {
        id: toDoFilterModelId
        sourceModel: toDoModelId
        mShowActive: true
    }

    ToDoFilterModel
    {
        id: completedToDoFilterModel
        sourceModel: toDoModelId
        mShowActive: false
    }

    ListFilterModel
    {
        id: listFilterModelId
        mShowActive: true
    }

    ListFilterModel
    {
        id: listDoneFilterModelId
        mShowActive: false
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
            replaceEnter: Transition { XAnimator { duration: 0 } }
            replaceExit: Transition { XAnimator { duration: 0 } }

            initialItem: "Screens/HomeScreen.qml"
        }
    }
}
