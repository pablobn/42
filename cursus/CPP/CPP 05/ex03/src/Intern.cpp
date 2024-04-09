#include "Intern.hpp"

Intern::Intern()
{}

Intern::~Intern()
{}

char const	*Intern::NameNotFoundException::what(void) const throw()
{
	return ("Name not found");
}

AForm* Intern::makeForm(std::string name, std::string target)
{
	try
	{
		AForm *form = NULL;

		form = PresidentialPardonForm::makeForm(name, target, form);
		form = RobotomyRequestForm::makeForm(name, target, form);
		form = ShrubberyCreationForm::makeForm(name, target, form);
		if (!form)
			throw NameNotFoundException;
		return (form);
	}
	catch(std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		return (NULL);
	}
}