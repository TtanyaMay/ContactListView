import QtQuick 2.12
import QtQuick.Window 2.12
import ContactsModule.Impl 1.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import Contacts 1.0
import StyleModule 1.0

//import Sailfish.Silica 1.0

Window {
    id: mainWindow
    width: 640
    height: 480
    title: qsTr("Hello World")

    ContactsView {
               anchors.fill: parent
          }

    RowLayout {
            id: rowLayout
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.margins: 5
            height: 30

            spacing: 5
            z:2
    Rectangle {
                Layout.fillWidth: true
                Layout.fillHeight: true
                color: "grey"

                TextInput {
                    id: textInput
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    Keys.onPressed: {
                        if(event.key === 16777220){
                            ListModel.append({ Text: textInput.text })
                        }
                    }
                }
            }

            Button {
                id: button
                text: qsTr("Add Contact")
                Layout.fillHeight: true

                onClicked: {
                    ContactsModel.append({ firstname: textInput.text, surname:textInput2.text, phonNumber:textInput.text })
                }
            }
        }
    Rectangle {
           id: _background
           z: -100
           anchors.fill: parent
           color: Style.backgroundColor
           opacity: Style.emphasisOpacity
       }
    Rectangle {
           id: background
           z: -100
           anchors.fill: parent
           color: Style.backgroundColor
           opacity: Style.emphasisOpacity
       }
    //    Window {
    //        id: firstWindow
    //        title: qsTr("Первое окно")

    //onSignalExit: {
    //   firstWindow.close()     // Закрываем первое окно
    //   mainWindow.show()       // Показываем основное окно
    // }
    //   }


}
