
#include "Cat.hpp"

Cat::Cat()
{
	brain = new Brain();
	std::cout << "Cat constructor called" << std::endl;
	type = "Cat";
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat distructor called" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	brain = new Brain();
	brain->dup_ideas(*copy.brain);
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat	&Cat::operator= (const Cat &copy)
{
	if (this == &copy)
		return (*this);
	std::cout << "Cat copy assignment operator called" << std::endl;
	brain->dup_ideas(*copy.brain);
	type = copy.type;
	return (*this);
}

void	Cat::makeSound(void) const
{
	brain->make_ideas("new thinking..");
	std::cout << "============================================= " << std::endl;
	std::cout << "Cat member funcion : makeSound called" << std::endl;
	std::cout << "type : " << type << std::endl;
	brain->say_ideas();
	std::cout << "============================================= " << std::endl;
}
