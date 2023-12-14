#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

void	ft_leaks()
{
	system("leaks -q animal");
}

int	main(void)
{
	const Animal *animals[10];
	const Animal *deepCopy;

	// atexit(ft_leaks);

	for (int i = 0; i <= 4; i++)
	{
		animals[i] = new Cat();
	}
	for (int i = 5; i <= 9; i++)
	{
		animals[i] = new Dog();
	}

	deepCopy = animals[0];
	std::cout<<deepCopy->getType()<<std::endl;
	std::cout<<"------Destructors------"<<std::endl;
	for (int i = 0; i < 10; i++)
	{
		delete animals[i];
	}
	return (0);
}