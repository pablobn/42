#include <iostream>
#include <string>
#include "contact.hpp"
#include "phonebook.hpp"

int	main(void)
{
	std::string str;
	PhoneBook phoneBook;
	Contact contact;

	while (str != "EXIT" && !std::cin.eof())
	{
		std::cout << "Choose one (ADD, SEARCH, EXIT)" <<std::endl;
		std::getline(std::cin, str);
		if (str == "ADD" && !std::cin.eof())
		{
			contact.initializeValues();
			phoneBook.addContact(contact);
		}
		else if(str == "SEARCH" && !std::cin.eof())
			phoneBook.printContacts();
		else if(str == "EXIT")
			std::cout << "Leaving the program" <<std::endl;
		else
		{
			if (std::cin.eof())
				return (1);
			std::cout << "You didn't choose any command" <<std::endl;
		}
	}
	if (std::cin.eof())
		return (1);
	return (0);
}