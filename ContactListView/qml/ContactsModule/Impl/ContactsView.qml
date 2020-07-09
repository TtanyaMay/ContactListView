import QtQuick 2.0
import Contacts 1.0
import ContactsModule.Base 1.0

BaseListView {
    id: root
    model: ContactsModel {

    }
//           ListModel {
//               id:_listModel
//               ListElement{
//                   name:"Test1"
//                   surname: "Test_sur"
//                   phoneNumber: "1122334455"
//               }
//               ListElement{
//                   name:"Test1"
//                   surname: "Test_sur"
//                   phoneNumber: "1122334455"
//               }
//               }
    delegate: ContactDelegate {
        id:contactsView
        width: root.width
        height: 70
    }
}
