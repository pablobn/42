#include "Bureaucrat.hpp"

void	ft_leaks(void)
{
	system("leaks -q bureaucrat");
}

int	main(void)
{
	Bureaucrat paco("Paco", 150);
	paco.incrementGrade();
	std::cout << paco << std::endl;
	paco.decrementGrade();
	std::cout << paco << std::endl;
	paco.decrementGrade();
	std::cout << paco << std::endl;
	return (0);
}