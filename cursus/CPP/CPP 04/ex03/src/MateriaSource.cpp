#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout<<"(MateriaSource) Default Constructor called"<<std::endl;
}

MateriaSource::~MateriaSource() 
{
	for (int i = 0; i<=3; i++)
	{
		if (this->sources[i])
			delete this->sources[i];
	}
	std::cout<<"(AMateria) Default Destructor called"<<std::endl;
}

void	MateriaSource::learnMateria(AMateria *ref)
{
	for (int i = 0; i <= 3; i++)
	{
		if (!this->sources[i])
		{
			this->sources[i] = ref;
			break;
		}
	}
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i <= 3; i++)
	{
		if (this->sources[i] && type == this->sources[i]->getType())
			return (this->sources[i]->clone());
	}
	return (NULL);
}