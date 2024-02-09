
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
	std::cout << "Cat copy constructor called" << std::endl;
}
Cat	&Cat::operator= (const Cat &copy)
{
	if (this == &copy)
		return (*this);
	std::cout << "Cat copy assignment operator called" << std::endl;
	type = copy.type;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << std::endl;
	std::cout << "============================================= " << std::endl;
	std::cout << "Cat member funcion : makeSound called" << std::endl;
	std::cout << "type : " << type << std::endl;
	brain->say_ideas();
	std::cout << "============================================= " << std::endl;
	std::cout << std::endl;
}
