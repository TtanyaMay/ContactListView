#pragma once
#include <QString>
#include <QVariant>

class Contact
{
public:
    Contact() = default;
    Contact(QString firstName, QString surname, QString phoneNumber);
    QString firstName() const;
    QString surname() const;
    QString phoneNumber() const;
    void SetFirstName(QString firstName);
    void SetSurName(QString surname);
    void SetPhoneNumber(QString phoneNumber);

private:

    QString m_firstName;
    QString m_surname;
    QString m_phone;

};
