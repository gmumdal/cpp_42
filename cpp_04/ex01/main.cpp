
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main()
{
	{
		const Animal	*animal[10];
		const Animal	*tmp = new Animal();
		for (int i = 0; i < 5; i++)
			animal[i] = new Dog();
		for (int i = 5; i < 10; i++)
			animal[i] = new Cat();
		for (int i = 0; i < 10; i++)
			animal[i]->makeSound();
		tmp->makeSound();
		for (int i = 0; i < 10; i++)
			delete animal[i];
		delete tmp;
	}
	return 0;
}