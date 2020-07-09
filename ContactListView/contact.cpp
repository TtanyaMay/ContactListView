#include "contact.h"

Contact::Contact(QString firstName, QString surname, QString phoneNumber)
    : m_firstName {std::move(firstName)},
      m_surname {std::move(surname)},
      m_phone {std::move(phoneNumber)}
{
}

QString Contact::firstName() const
{
    return m_firstName;
}

QString Contact::surname() const
{
    return m_surname;
}

QString Contact::phoneNumber() const
{
    return m_phone;
}

void Contact::SetFirstName(QString firstName)
{
    m_firstName = firstName;
}

void Contact::SetSurName(QString surname)
{
    m_surname = surname;
}

void Contact::SetPhoneNumber(QString phoneNumber)
{
    m_phone = phoneNumber;
}
