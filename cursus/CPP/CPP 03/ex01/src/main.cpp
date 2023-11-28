#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap pablo("Pablo");
	ClapTrap julio("Julio");

	pablo.attack("Julio");
	julio.takeDamage(20);
	julio.beRepaired(22);
	julio.attack("Pablo");
	pablo.guardGate();
	return (0);
}