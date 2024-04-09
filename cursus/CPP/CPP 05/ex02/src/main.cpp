#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	ft_leaks(void)
{
	system("leaks -q bureaucrat");
}

int	main(void)
{
	Bureaucrat paco("Paco", 1);
	ShrubberyCreationForm house("House");
	RobotomyRequestForm robot("Bender");
	PresidentialPardonForm president("Sanchez");
	paco.signForm(house);
	house.beSigned(paco);
	paco.signForm(house);
	house.execute(paco);
	robot.execute(paco);
	paco.executeForm(president);
	return (0);
}