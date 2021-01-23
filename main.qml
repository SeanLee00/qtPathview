import QtQuick 2.15
import QtQuick.Window 2.15
//import MyPathView

Window {
    id: idSSMainView
    width: 640
    height: 640
    visible: true
    title: qsTr("Hello World")
/*
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
            // foront
            startX: 150; startY: 100
            PathAttribute { name: "opacity"; value: 1.0}
            PathAttribute { name: "scale"; value: 1.0}
            PathAttribute { name: "z"; value: 0}

            // left
            PathCubic { x:50; y:50
                control1X: 100; control1Y: 100
//                control2X: 50;  control2Y: 75
            }
            PathAttribute { name: "opacity"; value: 1.0}
            PathAttribute { name: "scale"; value: 1.0}
            PathAttribute { name: "z"; value: 0}

            // top
            PathCubic { x:50; y:50
                control1X: 100; control1Y: 100
                control2X: 50;  control2Y: 75 }
            PathAttribute { name: "opacity"; value: 1.0}
            PathAttribute { name: "scale"; value: 1.0}
            PathAttribute { name: "z"; value: 0}

            // right
            PathCubic { x:50; y:50
                control1X: 100; control1Y: 100
                control2X: 50;  control2Y: 75 }
            PathAttribute { name: "opacity"; value: 1.0}
            PathAttribute { name: "scale"; value: 1.0}
            PathAttribute { name: "z"; value: 0}

        Keys.onLeftPressed: decrementCurrentIndex()
        Keys.onRightPressed: incrementCurrentIndex()
    }
    */
    property int nWidth : 640
    property int nHeight : idSSMainView.height

    // for test
    property int scensIndex : 0

    Rectangle{
        id: listRect
    }

    ListModel {
        id: nameModel
//        ListElement { name: "1"}
//        ListElement { name: "2"}
//        ListElement { name: "3"}
//        ListElement { name: "4"}
//        ListElement { name: "5"}
//        ListElement { name: "6" ; color:"red"}
        ListElement { name: "1"; width: 640; height: 640; color: "red"}
        ListElement { name: "2"; width: 640; height: 640; color: "blue"}
        ListElement { name: "3"; width: 640; height: 640; color: "grey"}
        ListElement { name: "4"; width: 640; height: 640; color: "yellow"}
        ListElement { name: "5"; width: 640; height: 640; color: "pink"}
        ListElement { name: "6"; width: 640; height: 640; color: "violet"}
    }

    Component {
        id: nameDelegate
        Column {
            Rectangle {
                id: delegateRect
                width: model.width
                height: model.width
                color: model.color

                Text {
                    id: delegateText
                    text: model.name
                    font.pixelSize: 24
                }

                MouseArea{
                    x:0
                    y:0
                    width:600
                    height: 600
                    onMouseXChanged: {
                        console.log("mouse move");
                    }
                }
            }
        }
    }

    PathView {
        id: view

        z: 0
        x: 10
        y: 0//nYoffset
        width: idSSMainView.nWidth
        height: idSSMainView.nHeight
        preferredHighlightBegin: 0.5
        preferredHighlightEnd: 0.5
        highlightRangeMode: PathView.StrictlyEnforceRange
//        cacheItemCount: nameModel.count * 2
        model: nameModel
//        pathItemCount: 3
        clip: true
        delegate: nameDelegate

        snapMode: PathView.SnapOneItem
        maximumFlickVelocity:8000

        visible: true

        path: Path {
            startX: 0//idSSMainView.nWidth/2
            startY: 0//-idSSMainView.nHeight
            PathLine {x: idSSMainView.nWidth; y: idSSMainView.nHeight}
        }

        onCountChanged: {
            console.log("[SPLITSCREEN_Main.qml] onCountChanged:" + view.currentIndex + " count:" + count)
        }

        onCurrentIndexChanged: {
            scensIndex = currentIndex;
            console.log("scensIndex:" + scensIndex)
        }

    }

    MouseArea{
        x:540
        y:620
        z: 110
        width:100
        height: 100
        onPressAndHold: {
            WindowControl.Api.setStatusBarStatus(false);

            console.log("mouse move");
        }
    }

}
