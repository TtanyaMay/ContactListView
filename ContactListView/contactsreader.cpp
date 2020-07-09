#include "contactsreader.h"

namespace  {
const std::vector<Contact> mocData{
     {"Kevin", "Green", "098-0452233"},
     {"Adanm", "Patric", "098-0452233"},
     {"Glen", "Hughnes", "098-0452233"},
     {"Samantha", "Smith", "098-0452233"},
     {"Kevin", "Green", "098-0452233"},
     {"Samantha", "Smith", "098-0452233"},
    {"Adanm", "Patric", "098-0452233"}

};
}
std::pair<bool, std::vector<Contact> > Contactsreader::requestContacts()
{
    return std::make_pair(true, mocData);
}
