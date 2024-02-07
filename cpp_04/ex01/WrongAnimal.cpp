
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal distructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	type = copy.type;
}
WrongAnimal	&WrongAnimal::operator= (const WrongAnimal &copy)
{
	if (this == &copy)
		return (*this);
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	type = copy.type;
	return (*this);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << std::endl;
	std::cout << "============================================= " << std::endl;
	std::cout << "WrongAnimal member funcion : makeSound called" << std::endl;
	std::cout << "type : " << type << std::endl;
	std::cout << "WrongAnimal Sound !" << std::endl;
	std::cout << "============================================= " << std::endl;
	std::cout << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (type);
}
