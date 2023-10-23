#include <iostream>
#include <string>
#include "contact.hpp"
#include "phonebook.hpp"

int	main(void)
{
	std::string str;
	PhoneBook phoneBook;
	Contact contact;

	while (str != "EXIT")
	{
		std::cout << "Choose one (ADD, SEARCH, EXIT)" <<std::endl;
		std::getline(std::cin, str);
		if (str == "ADD")
		{
			contact.initializeValues();
			phoneBook.addContact(contact);
		}
		else if(str == "SEARCH")
			phoneBook.printContacts();
		else if(str == "EXIT")
			std::cout << "Saliendo del programa" <<std::endl;
		else
			std::cout << "No has elegido ningún comando" <<std::endl;
	}
	return (0);
}