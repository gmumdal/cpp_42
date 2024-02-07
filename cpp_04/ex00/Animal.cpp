
#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal distructor called" << std::endl;
}

Animal::Animal(const Animal &copy)
{
	std::cout << "Animal copy constructor called" << std::endl;
	type = copy.type;
}
Animal	&Animal::operator= (const Animal &copy)
{
	if (this == &copy)
		return (*this);
	std::cout << "Animal copy assignment operator called" << std::endl;
	type = copy.type;
	return (*this);
}

void	Animal::makeSound(void) const
{
	std::cout << std::endl;
	std::cout << "============================================= " << std::endl;
	std::cout << "Animal member funcion : makeSound called" << std::endl;
	std::cout << "type : " << type << std::endl;
	std::cout << "Animal Sound !" << std::endl;
	std::cout << "============================================= " << std::endl;
	std::cout << std::endl;
}

std::string	Animal::getType(void) const
{
	return (type);
}
