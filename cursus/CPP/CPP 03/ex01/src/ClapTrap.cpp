#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name("null"), health(10), energy(10), damage(0)
{
	std::cout<<"(ClapTrap) Default Constructor called"<<std::endl;
}

ClapTrap::ClapTrap(std::string name): name("null"), health(10), energy(10), damage(0)
{
	this->name = name;
	std::cout<<"(ClapTrap) "<<this->name<<" is created"<<std::endl;
}

ClapTrap::~ClapTrap() 
{
	std::cout<<"(ClapTrap) "<<this->name<<" destructor called"<<std::endl;
}

void	ClapTrap::attack(const std::string &target)
{	if (this->energy > 0)
	{	
		std::cout<<"(ClapTrap) "<<this->name<<" attacks "<<target<<", causing ";
		std::cout<<this->damage<<" points of damage!"<<std::endl;
		this->energy -= 1;
	}
	else
		std::cout<<"(ClapTrap) "<<this->name<<" No energy left"<<std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > 0)
	{
		this->health -= amount;
		std::cout<<this->name<<" received "<<amount<<" points of damage, now he have ";
		std::cout<<this->health<<" points of health!"<<std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energy > 0 && amount > 0)
	{
		this->health += amount;
		std::cout<<this->name<<" received "<<amount<<" points of health, now he have ";
		std::cout<<this->health<<" points of health!"<<std::endl;
		this->energy -= 1;
	}
	else
		std::cout<<"(ClapTrap) "<<this->name<<" No energy left"<<std::endl;
}
