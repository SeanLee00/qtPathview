import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 1.3

Window {
    id :root
    visible: true
    MouseArea {
        anchors.fill: parent
        onClicked: {
            Qt.quit();
        }
    }
    Text {
        id : sendnumber
        text: send.number
        anchors.centerIn: parent
    }
}
