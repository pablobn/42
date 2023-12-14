#include "Cat.hpp"

Cat::Cat(): Animal::Animal("Cat")
{
	std::cout<<"(Cat) Default Constructor called"<<std::endl;
}

Cat::~Cat() 
{
	std::cout<<"(Cat) Destructor called"<<std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout<<"Miauuu!"<<std::endl;
}