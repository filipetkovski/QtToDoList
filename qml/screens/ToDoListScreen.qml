import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

import ListModel 1.0

import "../customcomponents"

Rectangle {
    id: toDoListScreen
    property int idList: -1
    onIdListChanged: {
        var objList = toDoModelId.getListModel(idList)
        listFilterModelId.sourceModel = objList
        listDoneFilterModelId.sourceModel = objList
    }

    Header {
        id: headerTDListScreenId
        width: 250
        Text {
            id: headerBackTxtTDScreenId
            text: qsTr("My List")
            color: "blue"
            font { pixelSize: 20; bold: true; underline: true; }
            anchors { verticalCenter: parent.verticalCenter; left: parent.left; leftMargin: 90 }

            MouseArea {
                id: clickLogoTxtTDScreenId
                anchors.fill: headerBackTxtTDScreenId
                cursorShape: Qt.PointingHandCursor

                onClicked: {
                    windowStackView.pop()
                }
            }
        }

        Text {
            id: listEditId
            text: qsTr("Edit")
            color: "blue"
            font { pixelSize: 20; bold: true; underline: true; }
            anchors { verticalCenter: parent.verticalCenter; left: headerBackTxtTDScreenId.left; leftMargin: 90 }

            MouseArea {
                id: clickTxtEditId
                anchors.fill: listEditId
                cursorShape: Qt.PointingHandCursor

                onClicked: windowStackView.push("EditListScreen.qml", {"modelIndex": idList})
            }
        }
    }

    //ToDo List Name
    Text {
        id: listNameId
        text: listFilterModelId.sourceModel.name
        font { pixelSize: 25; bold: true; }
        anchors { top: headerTDListScreenId.bottom; topMargin: 20 }
        color: "black"
    }

    //Active Tasks
    ListView {
        id: tasksViewId
        width: rec.width
        height: contentHeight < 500 ? contentHeight : 500
        anchors { top: listNameId.bottom; topMargin: 5 }

        model: listFilterModelId

        spacing: 1

        delegate: RowLayout {
            height: 30

            //CheckBox------------------
            CheckBox {
                checked: RoleIsDone
                //Task Name
                Text {
                    text: RoleName
                    color: "black"
                    anchors { left: parent.right; leftMargin: 5; }
                    font.pixelSize: 16
                }

                onCheckedChanged: {
                    listDoneFilterModelId.sourceModel.changeStatus(listFilterModelId.sourceIndex(index), checked)
                }
            }
        }
    }

    //Add another task-------------------
    TextButton {
        id: addTaskTxtId
        anchors { top: tasksViewId.bottom; topMargin: 15; }
        text: qsTr("Add another task")
        onBtnClicked: toDoListScreen.state = "addInputVisible"
    }

    //OR

    //Add Input
    Rectangle {
        id: addTaskInputId
        height: 170
        anchors { top: tasksViewId.bottom; topMargin: 15; }
        InputField {
            id: inputTDListScreenId
            width: rec.width
            height: 100
            titleSize: 14
            inputTxtSize: 14
        }

        ConfirmButton {
            id: confirmTDListScreenId
            width: 140
            height: 35
            fontSize: 12
            pushUrlLocation: "../screens/ToDoListScreen.qml"
            anchors { top: inputTDListScreenId.bottom; topMargin: 20 }
            text: qsTr("+ Add this task")

            onBtnClicked: {
                if(inputTDListScreenId.text != "") {
                    listFilterModelId.sourceModel.addTask(inputTDListScreenId.text)
                    inputTDListScreenId.text = ""
                }
            }
        }

        TextButton {
            anchors { left: confirmTDListScreenId.right; leftMargin: 20; verticalCenter: confirmTDListScreenId.verticalCenter }
            onBtnClicked: toDoListScreen.state = "addTxtVisible"
        }
    }

    //Done Tasks
    ListView {
        id: tasksDoneViewId
        width: rec.width
        height: contentHeight < 500 ? contentHeight : 500
        anchors.topMargin: 15
        model: listDoneFilterModelId

        spacing: 1

        delegate: RowLayout {
            height: 30

            //CheckBox------------------
            CheckBox {
                checked: RoleIsDone

                //Task Name
                Text {
                    text: RoleName
                    anchors { left: parent.right; leftMargin: 5; }
                    color: "black"
                    font.pixelSize: 16
                }

                onCheckedChanged: {
                    listDoneFilterModelId.sourceModel.changeStatus(listDoneFilterModelId.sourceIndex(index), checked)
                }
            }
        }
    }

    states: [
        State {
            name: "addTxtVisible"
            PropertyChanges {
                target: addTaskTxtId
                visible: true
            }
            PropertyChanges {
                target: addTaskInputId
                visible: false
            }
            AnchorChanges {
                target: tasksDoneViewId
                anchors.top: addTaskTxtId.bottom
            }
        },
        State {
            name: "addInputVisible"
            PropertyChanges {
                target: addTaskTxtId
                visible: false
            }
            PropertyChanges {
                target: addTaskInputId
                visible: true
            }
            AnchorChanges {
                target: tasksDoneViewId
                anchors.top: addTaskInputId.bottom
            }
        }
    ]
    state: "addTxtVisible"
}
