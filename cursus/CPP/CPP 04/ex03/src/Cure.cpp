#include "Cure.hpp"

Cure::Cure(): AMateria("cure")
{
	std::cout<<"(Cure) Default Constructor called"<<std::endl;
}

Cure::~Cure() 
{
	std::cout<<"(Cure) Default Destructor called"<<std::endl;
}

Cure::Cure(Cure const &ref): AMateria(ref.getType())
{
	std::cout<<this->type<<" constructed from a copy"<<std::endl;
}

Cure &Cure::operator=(const Cure &other)
{
	std::cout<<"copy from "<<other.getType()<<std::endl;
	return (*this);
}

AMateria *Cure::clone() const
{
	return (new Cure());
}

void Cure::use (ICharacter &target)
{
	std::cout<<"* heals "<<target.getName()<<"'s wounds *"<<std::endl;
}