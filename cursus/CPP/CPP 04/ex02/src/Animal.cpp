#include "Animal.hpp"

Animal::Animal(): type("Animal") 
{
	std::cout<<"(Animal) Default Constructor called"<<std::endl;
}

Animal::Animal(std::string type): type(type) 
{
	std::cout<<"(Animal) "<<type<<" Constructor called"<<std::endl;
}

Animal::~Animal() 
{
	std::cout<<"(Animal) Destructor called for "<<this->type<<std::endl;
}

void	Animal::setType(std::string type)
{
	this->type = type;
}

std::string Animal::getType(void) const
{
	return (this->type);
}