#include "contact.hpp"

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

class PhoneBook
{
private:
    Contact contacts[8];
    int     old;

public:
    PhoneBook();
    ~PhoneBook();
    void addContact(Contact contact);
    void printContacts();
    int getLengthList();
};

#endif