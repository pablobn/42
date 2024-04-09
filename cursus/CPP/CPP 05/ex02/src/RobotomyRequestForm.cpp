#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : 
AForm("RobotomyRequestForm", target, 72, 45)
{}
RobotomyRequestForm::~RobotomyRequestForm(){}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	try
	{
		if (executor.getGrade() > this->getExecGrade())
        {
            std::cout<<"robotomy failed"<<std::endl;
            throw GradeTooLowException;
        }
		else
		{
			std::cout<<"*...z..z..Bip Bop....z..z.*"<<std::endl;
            std::cout<<this->getTarget();
            std::cout<<" has been robotomized succesfully 50% of the time."<<std::endl;
		}
	} 
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}