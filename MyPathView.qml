import QtQuick 2.0

Rectangle {
    width: 300; height: 250; color: "white"

    ListModel {
        id: nameModel
        ListElement { name: "1" }
        ListElement { name: "2" }
        ListElement { name: "3" }
        ListElement { name: "4" }
        ListElement { name: "5" }
        ListElement { name: "6" }
    }

    Component {
        id: nameDelegate
        Column {
            Text {
                id: delegateText
                text: model.name
                font.pixelSize: 24
            }
        }
    }

    PathView{
        anchors.fill:parent
        model : nameModel
        delegate: nameDelegate
        focus: treu

        path: Path {
            startX: 0; startY: 0
//            PathAnimation { 0x
        }

        Keys.onLeftPressed: decrementCurrentIndex()
        Keys.onRightPressed: incrementCurrentIndex()
    }
}
