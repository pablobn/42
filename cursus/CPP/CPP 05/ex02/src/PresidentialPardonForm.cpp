#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : 
AForm("PresidentialPardonForm", target, 25, 5)
{}

PresidentialPardonForm::~PresidentialPardonForm(){}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	try
	{
		if (executor.getGrade() > this->getExecGrade())
            throw GradeTooLowException;
		else
		{
            std::cout<<this->getTarget();
			std::cout<<" has been pardoned by Zaphod Beeblebrox."<<std::endl;
		}
	} 
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}