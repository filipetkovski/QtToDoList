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

    ToDoFilterModel {
        id: toDoFilterModelId
        sourceModel: toDoModelId
        mShowActive: true
    }

    ToDoFilterModel {
        id: completedToDoFilterModel
        sourceModel: toDoModelId
        mShowActive: false
    }

    ListFilterModel {
        id: listFilterModelId
        mShowActive: true
    }

    ListFilterModel {
        id: listDoneFilterModelId
        mShowActive: false
    }

    Rectangle {
        id: rec
        width: 800
        height: applicationWindow.height - 50
        anchors { horizontalCenter: parent.horizontalCenter; verticalCenter: parent.verticalCenter; topMargin: 50; }
        color: "white"

        StackView {
            id: windowStackView
            anchors.fill: rec
            initialItem: "Screens/HomeScreen.qml"

            pushEnter: stackTransitionId; pushExit: stackTransitionId
            popEnter: stackTransitionId; popExit: stackTransitionId

            Transition {
                id: stackTransitionId
                XAnimator { duration: 0 }
            }
        }
    }
}
