#include <iostream>
#include <cctype>

void	ft_capital_letter(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		str[i] = std::toupper(str[i]);
		i++;
	}
}

int main(int argc, char **argv) 
{
	int i = 0;
	
	if (argc <= 1)
		return 1;
	i = 1;
	while (i < argc)
	{	
		ft_capital_letter(argv[i]);
		std::cout << argv[i];
		if (i + 1 != argc)
			std::cout << " ";
		i++;
	}
    return 0;
}