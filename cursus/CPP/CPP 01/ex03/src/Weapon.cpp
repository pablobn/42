#include "Weapon.hpp"

void	Weapon::setType(std::string type) 
{
	this->type = type;
	std::cout<<"(Weapon)"<<type<<" has been setted"<<std::endl;
}

std::string	Weapon::getType(void) 
{
	return (this->type);
}

Weapon::Weapon(std::string type) 
{
	this-> type = type;
	std::cout<<"(Weapon)"<<type<<" has been created"<<std::endl;
}

Weapon::Weapon() 
{
	type = "(null)";
	std::cout<<"(Weapon)"<<type<<" has been created"<<std::endl;
}

Weapon::~Weapon() {
	std::cout<<"(Weapon)"<<type<<" has been destroyed"<<std::endl;
}