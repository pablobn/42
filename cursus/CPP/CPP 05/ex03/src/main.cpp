#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	ft_leaks(void)
{
	system("leaks -q bureaucrat");
}

int	main(void)
{
	Intern someRandomIntern;
	Bureaucrat paco("Paco", 1);
	AForm *rrf;

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	rrf->execute(paco);
	return (0);
}