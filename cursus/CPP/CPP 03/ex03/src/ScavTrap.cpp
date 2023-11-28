#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	this->health = 100;
	this->energy = 50;
	this->damage = 20;
	std::cout<<"(ScavTrap) Default Constructor called"<<std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->health = 100;
	this->energy = 50;
	this->damage = 20;
	std::cout<<"(ScavTrap) "<<this->name<<" is created"<<std::endl;
}

ScavTrap::~ScavTrap() 
{
	std::cout<<"(ScavTrap) "<<this->name<<" destructor called"<<std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout<<"(ScavTrap) "<<this->name<<" is now in Gate keeper mode"<<std::endl;
}

void	ScavTrap::attack(const std::string &target)
{	if (this->energy > 0)
	{	
		std::cout<<"(ScavTrap) "<<this->name<<" attacks "<<target<<", causing ";
		std::cout<<this->damage<<" points of damage!"<<std::endl;
		this->energy -= 1;
	}
	else
		std::cout<<"(ScavTrap) "<<this->name<<" No energy left"<<std::endl;
}
