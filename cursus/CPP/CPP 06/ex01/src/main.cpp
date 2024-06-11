#include "ScalarConverter.hpp"

void	ft_leaks(void)
{
	system("leaks -q bureaucrat");
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Error con los parametros";
		return (1);
	}

	ScalarConverter::convert(argv[1]);

	return (0);
}