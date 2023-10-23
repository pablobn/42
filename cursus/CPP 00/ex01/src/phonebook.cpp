#include "phonebook.hpp"

void	PhoneBook::addContact(Contact contact)
{
	for (int i = 0; i < 8; i++)
	{
		if (this->contacts[i].isEmpty())
		{
			this->contacts[i] = contact;
			break;
		}
	}
}

void	PhoneBook::printContacts()
{
	std::cout<<"|Index|First Name|Last Name|Nick Name|"<<std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (!contacts[i].isEmpty())
		{
			contacts[i].printContact();
		}
	}
}

PhoneBook::PhoneBook() {
    // Implementa la inicialización de la clase aquí
}

PhoneBook::~PhoneBook() {
    // Implementa la limpieza y liberación de recursos aquí, si es necesario
}