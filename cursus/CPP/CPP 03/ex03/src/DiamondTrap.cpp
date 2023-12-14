#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name")
{
	this->name = name;
	this->health = FragTrap::health;
	this->energy = ScavTrap::energy;
	this->damage = FragTrap::damage;
	std::cout<<"(DiamondTrap) "<<this->name<<" is created"<<std::endl;
}

DiamondTrap::DiamondTrap(): ClapTrap("No_name_clap_name")
{
	this->name = "No_name";
	this->health = FragTrap::health;
	this->energy = ScavTrap::energy;
	this->damage = FragTrap::damage;
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

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}
