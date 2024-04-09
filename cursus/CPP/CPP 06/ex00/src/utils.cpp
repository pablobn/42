#include "utils.hpp"

int		isNumber(std::string str)
{
	int i = 0;
	
	if (str.empty())
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	for (size_t j = i; j <= str.length() - 1; j++)
	{
		if (isdigit(str[j])) return 1;
	}
	return (0);
}

int	isZero(std::string str)
{
	int i = 0;
	
	if (str.empty())
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	for (size_t j = i; j <= str.length() - 1; j++)
	{
		if (str[j] != '0') return 0;
	}
	return (1);
}