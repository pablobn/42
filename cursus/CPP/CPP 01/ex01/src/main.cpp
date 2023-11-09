#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name);

int	main(void)
{
	int N = 6;
	Zombie *z = zombieHorde(N, "Damian");
	for (int i = 0; i< N; i++)
	{
		z[i].announce();
	}
	delete[] z;
	return (0);
}