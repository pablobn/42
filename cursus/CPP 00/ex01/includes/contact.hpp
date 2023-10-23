#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>
#include <string>
using namespace std;

class Contact
{
private:
    string name;
    string surname;
    string nick;
    string phone;
    string secret;
public:
    Contact();
    ~Contact();
    void    initializeValues();
    void    printContact();
    bool    isEmpty();
};

#endif