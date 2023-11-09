#include "Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout<<name<<": BraiiiiiiinnnzzzZ...\n";
}

Zombie::Zombie(std::string name) 
{
	this->name = name;
}

Zombie::~Zombie() {
	std::cout<<"(Zombie)"<<name<<" has been destroyed"<<std::endl;
}