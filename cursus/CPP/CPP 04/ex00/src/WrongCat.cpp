#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal::WrongAnimal("WrongCat")
{
	std::cout<<"(WrongCat) Default Constructor called"<<std::endl;
}

WrongCat::~WrongCat() 
{
	std::cout<<"(WrongCat) Destructor called"<<std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout<<"Miauuu!"<<std::endl;
}