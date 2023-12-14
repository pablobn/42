#include "AMateria.hpp"

AMateria::AMateria(): type("_null_")
{
	std::cout<<"(AMateria) Default Constructor called"<<std::endl;
}

AMateria::AMateria(const std::string &type): type(type)
{
	std::cout<<"(AMateria) Constructor of type "<< type << " called."<<std::endl;
}

AMateria::~AMateria() 
{
	std::cout<<"(AMateria) Destructor called for "<<this->type<<std::endl;
}

std::string const &AMateria::getType() const
{
	return (this->type);
}

void AMateria::use (ICharacter &target)
{
	std::cout<<this->type<<" is used in "<<target.getName()<<std::endl;
}