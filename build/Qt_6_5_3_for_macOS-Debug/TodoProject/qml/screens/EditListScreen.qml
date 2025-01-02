import QtQuick
import QtQuick.Layouts

import "../CustomComponents"

FocusScope {
    id: createNewListScreen
    property int modelIndex: -1

    onModelIndexChanged: {
        listFilterModelId.sourceModel = toDoModelId.getListModel(modelIndex)
    }

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

    Rectangle {
        id: editInputsId
        anchors { top: cancelBtnEditId.bottom; topMargin: 10; }
        height: 200 + editTasksViewId.height

        InputField {
            id: editTitleId
            textTitle: qsTr("Title")
            titleSize: 18
            width: rec.width
            height: 50
            text: listFilterModelId.sourceModel.mTitle
            anchors.top: editInputsId.top
            inputTxtSize: 15
        }

        ListView {
            id: editTasksViewId
            property list<int> tasksToBeDeleted: []

            width: rec.width
            height: contentHeight < 500 ? contentHeight : 500
            anchors { top: editTitleId.bottom; topMargin: 10 }
            reuseItems: false

            model: listFilterModelId

            spacing: 1

            delegate: InputField {
                id: editTaskId
                textTitle: qsTr("")
                titleSize: 0
                width: rec.width
                height: 50
                text: RoleTaskName
                inputTxtSize: 15

                ConfirmButton {
                    id: deleteTaskId
                    anchors { left: inputFieldId.right; leftMargin: 5; verticalCenter: inputFieldId.verticalCenter; }
                    text: qsTr("X")
                    fontSize: 10
                    width: 15
                    height: 15

                    onBtnClicked: {
                        editTasksViewId.tasksToBeDeleted.push(index)
                        editTasksViewId.tasksToBeDeleted.sort()
                        editTaskId.visible = false
                        editTaskId.height = 0
                    }
                }
            }
        }

        InputField {
            id: editDescId
            textTitle: qsTr("Description")
            anchors { top: editTasksViewId.bottom; topMargin: 20; }
            titleSize: 18
            width: rec.width
            height: 50
            text: listFilterModelId.sourceModel.mDescription
            inputTxtSize: 15
        }
    }

    ConfirmButton {
        id: confirmEditId
        anchors { top: editInputsId.bottom; margins: 5; }
        text: qsTr("Save the list")
        fontSize: 15
        width: 140
        height: 35

        onBtnClicked: {
            //Edit task inputs
            if(listFilterModelId.sourceModel !== null) {
                for (var i = 0; i < editTasksViewId.contentItem.children.length-1; i++) {
                    var taskDelegate = editTasksViewId.contentItem.children[i];
                    var indX = listFilterModelId.sourceIndex(i);

                    if (taskDelegate && taskDelegate.text !== taskDelegate.RoleTaskName && taskDelegate.text !== "")
                        listFilterModelId.sourceModel.updateEditTasks(indX, taskDelegate.text)
                }
            }

            listFilterModelId.sourceModel.editTitleAndDescription(editTitleId.text, editDescId.text, modelIndex)

            //Delete the tasks
            for(var j=editTasksViewId.tasksToBeDeleted.length-1;j>=0;j--)
                listFilterModelId.sourceModel.deleteTask(listFilterModelId.sourceIndex(editTasksViewId.tasksToBeDeleted[j]))

            windowStackView.pop()
        }
    }

    TextButton {
        id: cancelBt2nEditId
        anchors { left: confirmEditId.right; leftMargin: 15; verticalCenter: confirmEditId.verticalCenter; }
        onBtnClicked: windowStackView.pop()
    }
}
