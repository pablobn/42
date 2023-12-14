#include "Character.hpp"

Character::Character(): name("_no_name_")
{
	std::cout<<"(Character) Default constructor called"<<std::endl;
}

Character::Character(const std::string name): name(name)
{
	std::cout<<"(Character) "<<name<<" is created."<<std::endl;
}

Character::~Character() 
{
	for (int i = 0; i<=3; i++)
	{
		if (this->belt[i])
			delete this->belt[i];
	}
	for (int i = 0; i<=9; i++)
	{
		if (this->unused[i])
			delete this->unused[i];
	}
	std::cout<<name<<" is deleted."<<std::endl;
}

std::string const &Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria *m)
{
	for(int i = 0; i <= 3; i++)
	{
		if (this->belt[i] == NULL)
		{
			this->belt[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx)
{
	if (this->belt[idx])
	{
		AMateria *ptr = this->belt[idx];
		this->belt[idx] = NULL;
		for (int i = 0; i <= 9; i++)
		{
			if (!this->unused[i])
			{
				this->unused[i] = ptr;
				break;
			}
		}
	}
	else
		std::cout<<"The slot you are trying to unequip is empty"<<std::endl;
}

void Character::use(int idx, ICharacter &target)
{
	if (this->belt[idx])
	{
		this->belt[idx]->use(target);
	}
	else
		std::cout<<"The slot you are trying to use is empty"<<std::endl;
}