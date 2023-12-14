#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal *meta = new Animal();
	const Animal *j = new Cat();
	const Animal *i = new Dog();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	j->makeSound();
	i->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;

	std::cout<<"---------Wrong Animals--------"<<std::endl;

	const WrongAnimal *error = new WrongAnimal();
	const WrongAnimal *errorCat = new WrongCat();

	std::cout << errorCat->getType() << " " << std::endl;
	errorCat->makeSound();
	error->makeSound();
	delete error;
	delete errorCat;
	
	return (0);
}