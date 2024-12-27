import QtQuick
import QtQuick.VirtualKeyboard
import QtQuick.Layouts
import QtQuick.Controls

import ToDoModel 1.0

Rectangle {
    id: homeScreen
    Header {
        id: header
        //FIX THE TASK WITH THE WIDTH OF THE HEADER
        width: 350
        Text {
            id: listTxt
            text: qsTr("My List")
            color: "black"
            font { pixelSize: 25; bold: true }
            anchors { verticalCenter: parent.verticalCenter; left: parent.left; leftMargin: 90 }
        }

        Text {
            id: createNewListTxt
            text: qsTr("Create a new list")
            color: "red"
            font { pixelSize: 15; underline: true; bold: true }
            anchors { baseline: listTxt.baseline; left: listTxt.right; leftMargin: 10 }

            MouseArea {
                id: mouseNewList
                anchors.fill: createNewListTxt
                cursorShape: Qt.PointingHandCursor

                onClicked: windowStackView.push("CreateListScreen.qml")
            }
        }
    }

    ListView {
        id: listView
        width: rec.width
        height: contentHeight < 500 ? contentHeight : 500
        anchors { top: header.bottom; topMargin: 20 }

        model: toDoFilterModelId
        spacing: 1

        delegate: RowLayout {
            id: delRec

            height: 30
            //Task Dot
            Rectangle {
                id: dotRec
                width: 30

                Rectangle {
                    property int tasks_left: RoleTasksLeft < 10 ? RoleTasksLeft : 10

                    width:  (tasks_left + 3) * 1.2
                    height: (tasks_left + 3) * 1.2
                    color: "gray"
                    radius: ((tasks_left + 3) * 1.2) / 2
                    anchors.centerIn: dotRec
                    Layout.leftMargin: 3
                }
            }

            //Task Name
            Text {
                id: listName
                text: RoleActiveListName
                color: "blue"
                font { underline: true; bold:true; pixelSize: 20 }

                MouseArea {
                    id: mouseListName
                    anchors.fill: listName
                    cursorShape: Qt.PointingHandCursor

                    onClicked: windowStackView.push("ToDoListScreen.qml", {"subProp": index})
                }
            }

            //Tasks Left
            Text {
                text: "- " + RoleTasksLeft + " left"
                color: "gray"
                font.pixelSize: 15;
            }
        }
    }

    Flow {
        id: completedListView
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
            model: ToDoFilterModel
            {
                id: completedFilterModel
                sourceModel: ToDoModel { }
                showActive: false
            }

            delegate: Text
            {
                text: RoleInactiveListName
                color: "blue"
                font { underline: true; pixelSize: 15 }
            }
        }
    }
}