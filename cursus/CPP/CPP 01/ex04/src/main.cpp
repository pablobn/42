#include <iostream>
#include <fstream>
#include <string>

void	ft_replace_word(std::string &line, std::string s1, std::string s2)
{
	int	i = 0;
	int	j = 0;

	while (line.find(s1, i) != std::string::npos)
	{
		i = line.find(s1, i);
		j = 0;
		while (s2[j] || s1[j])
		{
			if (s2[j])
			{
				if (s1[j])
					line[i] = s2[j];
				else
					line.insert(i,1,s2[j]);
			}
			else
			{
				line.erase(i, 1);
				i--;
			}
			i++;
			j++;
		}
	}
}

void	ft_replace_file(std::ifstream &f, char	**av)
{
	std::string	file = av[1];
	std::string line;
	bool		flag = false;
	std::string	str = av[3];
	std::ofstream replaceFile(file + ".replace");

	while (std::getline(f, line))
	{ 
		if (flag)
			replaceFile<<std::endl;
		ft_replace_word(line, av[2], av[3]);
		replaceFile << line;
		flag = true;
	}
	replaceFile.close();
}

int	main(int ac, char **av)
{
	std::string file;

	if (ac == 4)
	{
		file = av[1];
		std::ifstream f(file);
		if (!f.good())
		{
			std::cout<<"No existe el archivo";
			return (1);	
		}
		ft_replace_file(f, av);
		f.close();
		return (0);
	}
	std::cout<<"Error con parámetros"<<std::endl;
	return (1);
}