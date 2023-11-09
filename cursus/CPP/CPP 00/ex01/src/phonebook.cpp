#include "phonebook.hpp"

void	ft_print_index(std::string str)
{
	int	i = 0;
	int	j = 0;
	int start = 0;


	start = 10 - str.length();
	while (i < 10)
	{
		if (i < start)
			std::cout << " ";
		else
		{
			std::cout << str[j];
			j++;
		}
		i++;
	}
}

void	print_index()
{
	ft_print_index("Index");
	std::cout << "|";
	ft_print_index("First Name");
	std::cout << "|";
	ft_print_index("Last Name");
	std::cout << "|";
	ft_print_index("Nick Name");
	std::cout << "|"<<std::endl;
}

void	print_all_index()
{
	ft_print_index("First Name");
	std::cout << "|";
	ft_print_index("Last Name");
	std::cout << "|";
	ft_print_index("Nick Name");
	std::cout << "|";
	ft_print_index("Ph. Number");
	std::cout << "|";
	ft_print_index("Secret");
	std::cout << "|"<< std::endl;
}

void	PhoneBook::addContact(Contact contact)
{
	int	flag = 1;
	for (int i = 0; i < 8; i++)
	{
		if (this->contacts[i].isEmpty())
		{
			this->contacts[i] = contact;
			flag = 0;
			break;
		}
	}
	if (flag)
	{
		this->contacts[this->old] = contact;
		if (this->old == 7)
			this->old = 0;
		else
			this->old++;
	}
}

int	PhoneBook::getLengthList()
{
	int	i;
	for (i = 0; i < 8; i++)
	{
		if (this->contacts[i].isEmpty())
			return (i);
	}
	return (i);
}

void	PhoneBook::printContacts()
{
	std::string	ind;
	int		num;

	print_index();
	for (int i = 0; i < 8; i++)
	{
		if (!contacts[i].isEmpty())
		{
			ft_print_index(std::to_string(1 + i));
			std::cout << "|";
			contacts[i].printContact();
		}
	}
	if (getLengthList() == 0)
		return ;
	std::cout<<"Introduce index of contact: ";
	std::cin>>ind;
	if (std::cin.eof())
		return ;
	while (ind.length() != 1 || !isdigit(ind[0]) ||stoi(ind) < 1 || stoi(ind) > getLengthList())
	{
		std::cout<<"Introduce a valid index: ";
		std::cin>>ind;
		if (std::cin.eof())
			return ;
	}
	num = stoi(ind);
	num--;
	print_all_index();
	contacts[num].printAllContact();
}

PhoneBook::PhoneBook() {
    // Implementa la inicialización de la clase aquí
}

PhoneBook::~PhoneBook() {
    // Implementa la limpieza y liberación de recursos aquí, si es necesario
}