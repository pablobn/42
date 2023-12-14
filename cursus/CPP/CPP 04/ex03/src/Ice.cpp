#include "Ice.hpp"

Ice::Ice(): AMateria("ice")
{
	std::cout<<"(Ice) Default Constructor called"<<std::endl;
}

Ice::~Ice() 
{
	std::cout<<"(Ice) Default Destructor called"<<std::endl;
}

Ice::Ice(Ice const &ref) : AMateria(ref.getType())
{
	std::cout<<this->type<<" constructed from a copy"<<std::endl;
}

Ice &Ice::operator=(const Ice &other)
{
	std::cout<<"copy from "<<other.getType()<<std::endl;
	return (*this);
}

AMateria *Ice::clone() const
{
	return (new Ice());
}

void Ice::use (ICharacter &target)
{
	std::cout<<"* shoots an ice bolt at "<<target.getName()<<" *"<<std::endl;
}