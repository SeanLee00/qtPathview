import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 1.2

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    Label {
        id: lablel
        text: mw.number;
        anchors.centerIn: parent
    }
}
