#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>
#include <string>

class Brain
{
	private:
		std::string *ideas;
	public:
		Brain();
		Brain(Brain &brain);
		std::string	*getIdeas();
		~Brain();
};

#endif