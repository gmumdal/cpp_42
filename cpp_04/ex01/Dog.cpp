
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
	brain = new Brain();
	brain->dup_ideas(*copy.brain);
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog	&Dog::operator= (const Dog &copy)
{
	if (this == &copy)
		return (*this);
	std::cout << "Dog copy assignment operator called" << std::endl;
	brain->dup_ideas(*copy.brain);
	type = copy.type;
	return (*this);
}

void	Dog::makeSound(void) const
{
	brain->make_ideas("new thinking..");
	std::cout << "============================================= " << std::endl;
	std::cout << "Dog member funcion : makeSound called" << std::endl;
	std::cout << "type : " << type << std::endl;
	brain->say_ideas();
	std::cout << "============================================= " << std::endl;
}
