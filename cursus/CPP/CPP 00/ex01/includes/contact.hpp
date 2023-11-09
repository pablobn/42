#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>
#include <string>

class Contact
{
private:
    std::string name;
    std::string surname;
    std::string nick;
    std::string phone;
    std::string secret;
public:
    Contact();
    ~Contact();
    void    initializeValues();
    void    printContact();
    void    printAllContact();
    bool    isEmpty();
};

#endif