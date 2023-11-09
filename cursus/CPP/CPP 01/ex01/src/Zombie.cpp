#include "Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout<<name<<": BraiiiiiiinnnzzzZ...\n";
}

void	Zombie::setName(std::string name)
{
	this->name = name;
	std::cout<<"(Zombie)'"<<this->name<<"' has been setted"<<std::endl;
}

Zombie::Zombie(std::string name) 
{
	this->name = name;
	std::cout<<"(Zombie)"<<this->name<<" has been created"<<std::endl;
}
Zombie::Zombie() 
{
	name = "(null)";
	std::cout<<"(Zombie)"<<name<<" has been created"<<std::endl;
}

Zombie::~Zombie() {
	std::cout<<"(Zombie)"<<name<<" has been destroyed"<<std::endl;
}