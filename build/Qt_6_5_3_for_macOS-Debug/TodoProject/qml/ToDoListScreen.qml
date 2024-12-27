import QtQuick
import QtQuick.VirtualKeyboard
import QtQuick.Layouts
import QtQuick.Controls

Rectangle {
    id: toDoListScreen
    property int subProp: -1
    onSubPropChanged: tasksView.model = toDoModelId.getListModel(subProp)

    Header {
        id: headerToDoListScreen
        width: 200
        Text {
            id: listClickableTxt2
            text: qsTr("My List")
            color: "blue"
            font { pixelSize: 20; bold: true; underline: true; }
            anchors { verticalCenter: parent.verticalCenter; left: parent.left; leftMargin: 90 }

            MouseArea {
                id: mouseClicableLogoTxt2
                anchors.fill: listClickableTxt2
                cursorShape: Qt.PointingHandCursor

                onClicked: windowStackView.pop()
            }
        }
    }

    ListView {
        id: tasksView
        width: rec.width
        height: contentHeight < 500 ? contentHeight : 500
        anchors { top: headerToDoListScreen.bottom; topMargin: 20 }

        spacing: 1

        delegate: RowLayout {
            id: delRecTasks
            height: 30

            //Task Name
            Text {
                id: taskName
                text: RoleName
                color: "blue"
                font { underline: true; bold:true; pixelSize: 20 }
            }

            Text {
                id: taskIsDOne
                text: RoleIsDone ? qsTr("Yes") : qsTr("No")
                color: "red"
                font { underline: true; bold:true; pixelSize: 20 }
            }
        }
    }


}
