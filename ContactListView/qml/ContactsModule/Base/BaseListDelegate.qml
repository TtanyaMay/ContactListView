import QtQuick 2.0
import StyleModule 1.0
import QtQuick.Window 2.12

Rectangle {
    id: root
    color: Style.backgroundColor
    opacity: _delegateArea.pressed ? Style.secondaryOpacity : Style.emphasisOpacity

    MouseArea {
        id: _delegateArea
        anchors.fill: root
        onClicked: root.state == 'clicked' ? root.state = "" : root.state = 'clicked';
    }

    states: [
        State {
            name: "clicked"
            PropertyChanges { target: root; height: 250 }
            PropertyChanges {target: call_button; visible: true}
            PropertyChanges {target: call_button; clip: true}
        }]
//Button Call
    Rectangle {
        id: call_button
        width: 90
        height: 42
        radius: 50
        //color: marea.pressed ?  "orange" : "lightgreen"
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottomMargin: 25
        visible: false
        clip: true

//        MouseArea{
//            onClicked: {
//                firstWindow.show()  // Открываем первое окно
//                mainWindow.hide()   // Скрываем основное окно
//            }
        Text
        {
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            anchors.fill: parent
            text: "CALL"
            color: "red"
        }


    }
}

