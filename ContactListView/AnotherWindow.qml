import QtQuick 2.0
import QtQuick.Window 2.12
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.1

Window {
    id: callWindow
    signal signalExit
    visible: false
    width: 640
    height: 480
    title: qsTr("Calling")

    Button{
        text: qsTr("Back to contacts")
                width: 180
                height: 50
                anchors.centerIn: parent
     onClicked: {
        callWindow.signalExit()
     }
//    MouseArea{
//                onClicked: root.state == 'back' ? root.state = "" : root.state = 'back';
//            }
//            states: [
//                State {
//                    name: "back"
//                    PropertyChanges { target: callWindow; visible: true }
//                    PropertyChanges {target: mainWindow; visible: false}

//                }]
}}

