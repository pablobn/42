#include "Dog.hpp"

Dog::Dog(): Animal::Animal("Dog")
{
	std::cout<<"(Dog) Default Constructor called"<<std::endl;
	this->brain = new Brain();
}

Dog::Dog(Dog &dog)
{
	this->type = dog.getType();
	this->brain = new Brain(*dog.brain);
}

Dog::~Dog() 
{
	std::cout<<"(Dog) Destructor called"<<std::endl;
	delete this->brain;
}

Dog &Dog::operator=(const Dog &other)
{
	this->type = other.getType();
	if (this->brain)
		delete this->brain;
	this->brain = new Brain(*other.brain);
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout<<"Dog!"<<std::endl;
}

Brain*	Dog::getBrain(void) const
{
	return (this->brain);
}