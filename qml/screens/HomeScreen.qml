import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

import ToDoModel 1.0

import "../CustomComponents"

Rectangle {

    Header {
        id: headerHomeScreenId
        width: 350

        Text {
            id: listTxt
            text: qsTr("My List")
            color: "black"
            font { pixelSize: 25; bold: true }
            anchors { verticalCenter: parent.verticalCenter; left: parent.left; leftMargin: 90 }
        }

        Text {
            text: qsTr("Create a new list")
            color: "red"
            font { pixelSize: 15; underline: true; bold: true }
            anchors { baseline: listTxt.baseline; left: listTxt.right; leftMargin: 10 }

            MouseArea {
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor

                onClicked: windowStackView.push("CreateListScreen.qml")
            }
        }
    }

    // Render Active Tasks
    ListView {
        id: listView
        width: rec.width
        height: contentHeight < 500 ? contentHeight : 500
        anchors { top: headerHomeScreenId.bottom; topMargin: 20 }

        model: toDoFilterModelId
        spacing: 1
        delegate: RowLayout {
            height: 30

            // Task Dot
            Rectangle {
                width: 30

                Rectangle {
                    property int tasks_left: RoleTasksLeft < 10 ? RoleTasksLeft : 10

                    width:  (tasks_left + 3) * 1.2
                    height: (tasks_left + 3) * 1.2
                    color: "gray"
                    radius: ((tasks_left + 3) * 1.2) / 2
                    anchors.centerIn: parent
                    Layout.leftMargin: 3
                }
            }

            // Task Name
            Text {
                id: listActiveNameId
                text: RoleActiveListName
                color: "blue"
                font { underline: true; bold:true; pixelSize: 20 }

                MouseArea {
                    anchors.fill: listActiveNameId
                    cursorShape: Qt.PointingHandCursor

                    onClicked: windowStackView.push("ToDoListScreen.qml", {"idList": toDoFilterModelId.sourceIndex(index)})
                }
            }

            // Tasks Left
            Text {
                visible: RoleTasksLeft > 0
                text: "- " + RoleTasksLeft + " left"
                color: "gray"
                font.pixelSize: 15;
            }
        }
    }

    // Render Inactive Tasks
    Flow {
        width: rec.width
        height: 100
        anchors { top: listView.bottom; topMargin: 20 }
        spacing: 5
        visible: inActiveRepeater.count > 0

        Text {
            text: qsTr("Completed lists: ")
            color: "black"
            font.pixelSize: 15
        }

        Repeater {
            id: inActiveRepeater
            model: completedToDoFilterModel

            delegate: Text {
                id: listInActiveNameId
                text: RoleInactiveListName
                color: "blue"
                font { underline: true; pixelSize: 15 }

                MouseArea {
                    anchors.fill: listInActiveNameId
                    cursorShape: Qt.PointingHandCursor

                    onClicked: windowStackView.push("ToDoListScreen.qml", {"idList": completedToDoFilterModel.sourceIndex(index)})
                }
            }
        }
    }
}
