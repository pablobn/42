#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		//Constructors
		PresidentialPardonForm(std::string target);
		//Destructor
		~PresidentialPardonForm();
		//methods
		void execute(Bureaucrat const & executor) const;
};

#endif