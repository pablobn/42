#include "Cat.hpp"

Cat::Cat(): Animal::Animal("Cat")
{
	std::cout<<"(Cat) Default Constructor called"<<std::endl;
	this->brain = new Brain();
}

Cat::~Cat() 
{
	std::cout<<"(Cat) Destructor called"<<std::endl;
	delete this->brain;
}

Cat::Cat(Cat &cat)
{
	this->type = cat.getType();
	this->brain = new Brain(*cat.brain);
}

Cat &Cat::operator=(const Cat &other)
{
	this->type = other.getType();
	if (this->brain)
		delete this->brain;
	this->brain = new Brain(*other.brain);
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout<<"Miauuu!"<<std::endl;
}

Brain*	Cat::getBrain(void) const
{
	return (this->brain);
}