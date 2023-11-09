#include "Zombie.hpp"

void	randomChump(std::string name);
Zombie	*newZombie(std::string name);

int	main(void)
{
	Zombie *z = newZombie("Damian");
	z->announce();
	randomChump("Julio");
	delete z;
	return (0);
}