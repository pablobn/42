#include "contact.hpp"

void	Contact::initializeValues()
{
	std::cout << "Name: ";
	std::getline(std::cin, name);
	if (name.empty())
		return ;
	std::cout << "Last name: ";
	std::getline(std::cin, surname);
	if (surname.empty())
		return ;
	std::cout << "Nick name: ";
	std::getline(std::cin, nick);
	if (nick.empty())
		return ;
	std::cout << "Phone Number: ";
	std::getline(std::cin, phone);
	if (phone.empty())
		return ;
	std::cout << "Darkest Secret: ";
	std::getline(std::cin, secret);
	if (secret.empty())
		return ;
}

bool	Contact::isEmpty()
{
	return name.empty();
}

void	ft_print_table(std::string str)
{
	int	i = 0;
	int	j = 0;
	int start = 0;

	start = 10 - str.length();
	while (i < 10)
	{
		if (i < start)
			std::cout << " ";
		else if(start < 0 && i == 9)
			std::cout << ".";
		else
		{
			std::cout << str[j];
			j++;
		}
		i++;
	}
}

void	Contact::printContact()
{
	ft_print_table(name);
	std::cout << "|";
	ft_print_table(surname);
	std::cout << "|";
	ft_print_table(nick);
	std::cout << "|"<< std::endl;
}

void	Contact::printAllContact()
{
	ft_print_table(name);
	std::cout << "|";
	ft_print_table(surname);
	std::cout << "|";
	ft_print_table(nick);
	std::cout << "|";
	ft_print_table(phone);
	std::cout << "|";
	ft_print_table(secret);
	std::cout << "|"<< std::endl;
}

Contact::Contact() {
    // Implementa la inicialización de la clase aquí
}

Contact::~Contact() {
    // Implementa la limpieza y liberación de recursos aquí, si es necesario
}