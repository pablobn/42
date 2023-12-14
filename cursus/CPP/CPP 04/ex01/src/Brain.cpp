#include "Brain.hpp"

Brain::Brain()
{
	this->ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = "i'm hungry";
	}
	std::cout<<"(Brain) Default Constructor called"<<std::endl;
}

Brain::Brain(Brain &brain)
{
	std::string *ref = brain.getIdeas();

	this->ideas = new std::string[100];
	for (int i = 0; i<100; i++)
	{
		this->ideas[i] = ref[i];
	}
}

Brain::~Brain() 
{
	delete [] this->ideas;
	std::cout<<"(Brain) Destructor called"<<std::endl;
}

std::string	*Brain::getIdeas()
{
	return (this->ideas);
}