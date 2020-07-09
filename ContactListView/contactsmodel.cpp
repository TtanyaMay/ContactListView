#include <QQmlEngine>
#include <QDebug>
#include "contactsmodel.h"

ContactsModel::ContactsModel()

{
    const bool updateResult {updateContacts()};
    if (!updateResult) {
        qWarning() << "Update contacts failed!";
    }

}


QHash<int, QByteArray> ContactsModel::roleNames() const
{
    QHash<int, QByteArray> roles;
       roles[ContactRoles::NameRole] = "name"; //from ContactDelegate
       roles[ContactRoles::SurnameRole] = "surname";
       roles[ContactRoles::PhoneNumberRole] = "phoneNumber";

       return roles;
}

int ContactsModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
        return static_cast<int>(m_contacts.size());
}

QVariant ContactsModel::data(const QModelIndex &index, int role) const
{
        if (!index.isValid() || index.row() > rowCount(index)) {
            return {};
        }

        const Contact& contact = m_contacts.at(index.row());

        switch (role) {
            case ContactRoles::NameRole: {
                return QVariant::fromValue(contact.firstName());
            }
            case ContactRoles::SurnameRole: {
                return QVariant::fromValue(contact.surname());
            }
            case ContactRoles::PhoneNumberRole: {
                return QVariant::fromValue(contact.phoneNumber());
            }
            default: {
            return {}; //{}
            }
        }
}

void ContactsModel::add(const Contact &cont)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
       m_new_contact << cont;
       endInsertRows();
       emit dataChanged(createIndex(0, 0), createIndex(m_contacts.size(), 0));
}

//void ContactsModel::addContact(Contact cont)
//{
//    m_new_contact << cont;
//}

//ContactsModel::~ContactsModel()
//{

//}


bool ContactsModel::updateContacts()
{
    bool requestResult {false};
    std::vector<Contact> contactsResult;
    std::tie(requestResult, contactsResult) = m_reader.requestContacts();

   if (requestResult) {
        m_contacts.swap(contactsResult);
        emit dataChanged(createIndex(0, 0), createIndex(m_contacts.size(), 0));
    }

    return requestResult;
}
void ContactsModel::registerMe(const std::string &moduleName)
{
    qmlRegisterType<ContactsModel>(moduleName.c_str(), 1, 0, "ContactsModel");
}
