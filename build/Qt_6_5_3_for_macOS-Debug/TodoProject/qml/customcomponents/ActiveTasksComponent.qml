import QtQuick 2.5
import QtQuick.Controls
import QtQuick.Layouts

MouseArea {
    id: dragArea
    property bool held: false
    property int startIndex: index
    property bool orderOn: tasksViewId.count > 1 && dragTxtVisible

    width: rec.width
    height: 30
    drag.target: held ? content : undefined
    drag.axis: Drag.YAxis
    enabled: orderOn

    onPressed: held = true
    onReleased: {
        var toIndex = DelegateModel.itemsIndex

        if(startIndex !== toIndex) {
            if(startIndex < toIndex)
                reorder(startIndex, toIndex)
            else
                reorder(toIndex,startIndex)
        }

        held = false
    }

    RowLayout {
        id: content
        Drag.active: dragArea.held
        Drag.source: dragArea
        Drag.hotSpot.x: width / 2
        Drag.hotSpot.y: height / 2

        Rectangle {
            width: 50
            height: 15
            color: "black"
            radius: width / 2
            visible: orderOn
            Text {
                text: qsTr("Drag")
                color: "white"
                font.pixelSize: 13
                anchors.centerIn: parent
            }
        }

        //CheckBox------------------
        CheckBox {
            height: 30
            checked: RoleIsDone

            //Task Name
            Text {
                text: RoleTaskName
                color: "black"
                anchors { left: parent.right; leftMargin: 5; }
                font.pixelSize: 16
            }

            onCheckedChanged: {
                listDoneFilterModelId.sourceModel.changeTaskStatus(listFilterModelId.sourceIndex(index), checked)
                if(tasksViewId.count <= 1)
                    toDoListScreen.resetDragTxtVisible()
            }
        }
    }

    DropArea {
        anchors { fill: parent; margins: 10 }

        onEntered: (drag) => {
            let fromIndex = drag.source.DelegateModel.itemsIndex
            let toIndex = dragArea.DelegateModel.itemsIndex

            if(fromIndex !== toIndex) {
                if (fromIndex < toIndex)
                    visualModel.items.move(fromIndex, toIndex)
                else
                    visualModel.items.move(toIndex, fromIndex)
            }

        }
    }

    function reorder(index1, index2) {
        listFilterModelId.sourceModel.reorderTasks(
            listFilterModelId.sourceIndex(index1),
            listFilterModelId.sourceIndex(index2)
        );
    }
}

