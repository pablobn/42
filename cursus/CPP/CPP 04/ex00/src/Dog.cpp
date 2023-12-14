#include "Dog.hpp"

Dog::Dog(): Animal::Animal("Dog")
{
	std::cout<<"(Dog) Default Constructor called"<<std::endl;
}

Dog::~Dog() 
{
	std::cout<<"(Dog) Destructor called"<<std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout<<"Dog!"<<std::endl;
}