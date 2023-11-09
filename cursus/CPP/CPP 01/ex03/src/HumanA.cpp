#include "HumanA.hpp"

void	HumanA::attack()
{
	std::cout<<name<<" attacks with their "<<this->weapon.getType()<<std::endl;
}

HumanA::HumanA(std::string name, Weapon &weapon) : weapon(weapon), name(name)
{
	std::cout<<"(HumanA)"<<name<<" has been created, ";
	std::cout<<weapon.getType()<<" has been asigned"<<std::endl;
}

HumanA::~HumanA() {
	std::cout<<"(HumanA)"<<name<<" has been destroyed"<<std::endl;
}