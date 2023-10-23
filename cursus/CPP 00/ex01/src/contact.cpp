#include "contact.hpp"

void	Contact::initializeValues()
{
	std::cout << "Nombre: ";
	std::cin >> name;
	std::cout << "Apellido: ";
	std::cin >> surname;
	std::cout << "Alias: ";
	std::cin >> nick;
	std::cout << "Número de teléfono: ";
	std::cin >> phone;
	std::cout << "Secreto: ";
	std::cin >> secret;
}

bool	Contact::isEmpty()
{
	return name.empty();
}

void	Contact::printContact()
{
	std::cout << name;
	std::cout << "|";
	std::cout << surname;
	std::cout << "|";
	std::cout << nick;
	std::cout << "|"<<std::endl;
}

Contact::Contact() {
    // Implementa la inicialización de la clase aquí
}

Contact::~Contact() {
    // Implementa la limpieza y liberación de recursos aquí, si es necesario
}