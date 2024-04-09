#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"
#include <fstream>

class RobotomyRequestForm : public AForm
{
	public:
		//Constructors
		RobotomyRequestForm(std::string target);
		//Destructor
		~RobotomyRequestForm();
		//methods
		void execute(Bureaucrat const & executor) const;
};

#endif