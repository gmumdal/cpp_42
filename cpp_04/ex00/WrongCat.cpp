
#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat constructor called" << std::endl;
	type = "WrongCat";
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat distructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat	&WrongCat::operator= (const WrongCat &copy)
{
	if (this == &copy)
		return (*this);
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	type = copy.type;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << std::endl;
	std::cout << "============================================= " << std::endl;
	std::cout << "WrongCat member funcion : makeSound called" << std::endl;
	std::cout << "type : " << type << std::endl;
	std::cout << "Mawww...  !" << std::endl;
	std::cout << "============================================= " << std::endl;
	std::cout << std::endl;
}
