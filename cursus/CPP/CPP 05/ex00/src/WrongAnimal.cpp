#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("WrongAnimal") 
{
	std::cout<<"(WrongAnimal) Default Constructor called"<<std::endl;
}

WrongAnimal::WrongAnimal(std::string type): type(type) 
{
	std::cout<<"(WrongAnimal) "<<type<<" Constructor called"<<std::endl;
}

WrongAnimal::~WrongAnimal() 
{
	std::cout<<"(WrongAnimal) Destructor called for "<<this->type<<std::endl;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout<<"ASHO!"<<std::endl;
}

void	WrongAnimal::setType(std::string type)
{
	this->type = type;
}

std::string WrongAnimal::getType(void) const
{
	return (this->type);
}