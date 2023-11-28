#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	this->health = 100;
	this->energy = 100;
	this->damage = 30;
	std::cout<<"(FragTrap) Default Constructor called"<<std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->health = 100;
	this->energy = 100;
	this->damage = 30;
	std::cout<<"(FragTrap) "<<this->name<<" is created"<<std::endl;
}

FragTrap::~FragTrap() 
{
	std::cout<<"(FragTrap) "<<this->name<<" destructor called"<<std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout<<"(FragTrap) "<<this->name<<" wants a high five!"<<std::endl;
}

void	FragTrap::attack(const std::string &target)
{	if (this->energy > 0)
	{	
		std::cout<<"(FragTrap) "<<this->name<<" attacks "<<target<<", causing ";
		std::cout<<this->damage<<" points of damage!"<<std::endl;
		this->energy -= 1;
	}
	else
		std::cout<<"(FragTrap) "<<this->name<<" No energy left"<<std::endl;
}
