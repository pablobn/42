#ifndef INTERN_HPP
#define INTERN_HPP
#include <string.h>
#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		//Constructors
		Intern();
		//Destructor
		~Intern();
		AForm *makeForm(std::string name, std::string target);
		class NameNotFoundException : public std::exception
		{
			virtual const char *what() const throw();
		}NameNotFoundException;
};

#endif