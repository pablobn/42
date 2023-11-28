#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap pablo("Pablo");
	ClapTrap julio("Julio");

	pablo.attack("Julio");
	julio.takeDamage(6);
	julio.beRepaired(2);
	return (0);
}