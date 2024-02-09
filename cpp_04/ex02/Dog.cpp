
#include "Dog.hpp"

Dog::Dog()
{
	brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
	type = "Dog";
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog distructor called" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << "Dog copy constructor called" << std::endl;
}
Dog	&Dog::operator= (const Dog &copy)
{
	if (this == &copy)
		return (*this);
	std::cout << "Dog copy assignment operator called" << std::endl;
	type = copy.type;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << std::endl;
	std::cout << "============================================= " << std::endl;
	std::cout << "Dog member funcion : makeSound called" << std::endl;
	std::cout << "type : " << type << std::endl;
	brain->say_ideas();
	std::cout << "============================================= " << std::endl;
	std::cout << std::endl;
}
