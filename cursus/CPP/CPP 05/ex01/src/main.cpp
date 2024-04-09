#include "Bureaucrat.hpp"
#include "Form.hpp"

void	ft_leaks(void)
{
	system("leaks -q bureaucrat");
}

int	main(void)
{
	Bureaucrat paco("Paco", 15);
	Form rent("Divorce", 85);
	paco.signForm(rent);
	rent.beSigned(paco);
	paco.signForm(rent);
	return (0);
}