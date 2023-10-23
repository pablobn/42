#include "contact.hpp"

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

class PhoneBook
{
private:
    Contact contacts[8];

public:
    PhoneBook();
    ~PhoneBook();
    void addContact(Contact contact);
    void printContacts();
};

#endif