#include "HumanB.hpp"

void	HumanB::attack()
{
	if (!this->weapon)
		std::cout<<name<<" attacks with their "<<weapon->getType()<<std::endl;
	else
		std::cout<<name<<" attacks with their hands"<<std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

HumanB::HumanB(std::string name) : weapon(NULL)
{
	this->name = name;
	std::cout<<"(HumanB)"<<name<<" has been created"<<std::endl;
}

HumanB::~HumanB() {
	std::cout<<"(HumanB)"<<name<<" has been destroyed"<<std::endl;
}