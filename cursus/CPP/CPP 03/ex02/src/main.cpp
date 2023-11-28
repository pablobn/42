#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"


int	main(void)
{
	FragTrap pablo("Pablo");
	ScavTrap julio("Julio");

	pablo.attack("Julio");
	julio.takeDamage(30);
	julio.beRepaired(22);
	julio.attack("Pablo");
	pablo.takeDamage(20);
	pablo.beRepaired(6);
	pablo.highFivesGuys();
	julio.guardGate();
	return (0);
}