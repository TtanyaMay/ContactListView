#ifndef CONTACTSREADER_H
#define CONTACTSREADER_H
#include <utility>
#include <vector>
#include "contact.h"

class Contactsreader
{
public:
    std::pair<bool,
    std::vector<Contact>> requestContacts();
};

#endif // CONTACTSREADER_H

