#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

void	ft_leaks()
{
	system("leaks -q animal");
}

int	main(void)
{
	const Animal *animals[10];

	// atexit(ft_leaks);

	for (int i = 0; i <= 4; i++)
	{
		animals[i] = new Cat();
	}
	for (int i = 5; i <= 9; i++)
	{
		animals[i] = new Dog();
	}

	Cat *gato = new Cat();
	Cat *copyGato(gato);
	std::cout<<copyGato->getBrain()->getIdeas()[0]<<std::endl;
	copyGato->getBrain()->getIdeas()[0] = "a";
	std::cout<<copyGato->getBrain()->getIdeas()[0]<<std::endl;
	for (int i = 0; i < 10; i++)
	{
		delete animals[i];
	}
	return (0);
}