#ifndef CONTACTSMODEL_H
#define CONTACTSMODEL_H
#include <QAbstractListModel>
#include <vector>
#include "contact.h"
#include "contactsreader.h"

class ContactsModel : public QAbstractListModel
{
    Q_OBJECT

public:

    ContactsModel();

    static void registerMe(const std::string& moduleName);

     QHash<int, QByteArray> roleNames() const override;
     int rowCount(const QModelIndex& parent = {}) const override;
     QVariant data(const QModelIndex& index = {}, int role = Qt::DisplayRole) const override;

    // explicit ContactsModel(QObject *parent = nullptr);
     //   ~ContactsModel();
     enum ContactRoles
        {
            NameRole = Qt::UserRole + 1,
            SurnameRole,
            PhoneNumberRole
        };
     void add(const Contact &cont);
public slots:
    // void addContact(Contact cont);

private:
     std::vector<Contact> m_contacts;
     QList<Contact> m_new_contact;
     Contactsreader m_reader;


    bool updateContacts();

};
#endif // CONTACTSMODEL_H
