#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	public:
		//Constructors
		ShrubberyCreationForm(std::string target);
		//Destructor
		~ShrubberyCreationForm();
		//methods
		void execute(Bureaucrat const & executor) const;
		static AForm *makeForm(std::string name, std::string target, AForm *form);
};

#endif