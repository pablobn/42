#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name")
{
	this->name = name;
	std::cout<<"(DiamondTrap) "<<this->name<<" is created"<<std::endl;
}

DiamondTrap::DiamondTrap(): FragTrap()
{
	std::cout<<"(DiamondTrap) Default Constructor called"<<std::endl;
}

DiamondTrap::~DiamondTrap() 
{
	std::cout<<"(DiamondTrap) "<<this->name<<" destructor called"<<std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout<<"My name is "<<this->name<<std::endl;
	std::cout<<"My ClapTrap name is "<<ClapTrap::name<<std::endl;
}
