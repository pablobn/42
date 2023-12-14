#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

void	ft_leaks()
{
	system("leaks -q materia");
}

int	main(void)
{
	IMateriaSource* src = new MateriaSource();
	ICharacter* bob = new Character("bob");
	ICharacter* me = new Character("me");
	AMateria* tmp;
	std::cout<<"---------------"<<std::endl;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->unequip(1);
	std::cout<<"---------------"<<std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout<<"---------------"<<std::endl;
	//DELETE MEMORY
	delete bob;
	delete me;
	delete src;
	return 0;
}