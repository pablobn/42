#include "Zombie.hpp"

void	Zombie::announce(void)
{
	cout<<name<<": BraiiiiiiinnnzzzZ...\n";
}

void	Zombie::setName(string name)
{
	this->name = name;
	cout<<"(Zombie)'"<<this->name<<"' has been setted"<<endl;
}

Zombie::Zombie(string name) 
{
	this->name = name;
	cout<<"(Zombie)"<<this->name<<" has been created"<<endl;
}
Zombie::Zombie() 
{
	name = "(null)";
	cout<<"(Zombie)"<<name<<" has been created"<<endl;
}

Zombie::~Zombie() {
	cout<<"(Zombie)"<<name<<" has been destroyed"<<endl;
}