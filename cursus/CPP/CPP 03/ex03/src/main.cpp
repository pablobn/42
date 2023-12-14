#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"


int	main(void)
{
	DiamondTrap pablo("Pablo");
	ScavTrap julio("Julio");

	julio.takeDamage(30);
	julio.beRepaired(22);
	julio.attack("Pablo");
	pablo.whoAmI();
	julio.guardGate();
	pablo.attack("Julio");
	pablo.takeDamage(100);
	return (0);
}