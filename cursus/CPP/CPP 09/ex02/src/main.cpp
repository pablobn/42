#include "PmergeMe.hpp"

int	introduceDates(std::list<int> &list, std::vector<int> &vector, char**av)
{
	int i = 1;
	char* token;
	while (av[i])
	{
		token = std::strtok(av[i], " ");
		if (!std::isdigit(token[0]))
			return (-1);
		while (token != NULL)
		{
			if (!isdigit(token[0]))
				return (-1);
			vector.push_back(std::atoi(token));
			list.push_back(std::atoi(token));
			token = std::strtok(NULL, " ");
		}
		i++;
	}
	return (0);
}

int main(int argc, char** argv) {
	if(argc <= 1)
	{
		std::cerr<<"Error"<<std::endl;
		return(1);
	}
	std::list<int> list;
	std::vector<int> vector;

	if (introduceDates(list, vector, argv) == -1)
	{
		std::cerr<<"Error"<<std::endl;
		return(1);
	}
	PmergeMe pmerge(list, vector);
	pmerge.resolve();
	return(0);
}