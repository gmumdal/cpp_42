
#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice constructor called" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice type distructor called" << std::endl;
}

Ice::Ice(const Ice &copy) : AMateria(copy)
{
	std::cout << "Ice type copy constructor called" << std::endl;
}

Ice &Ice::operator= (const Ice &copy)
{
	if (this == &copy)
		return (*this);
	std::cout << "Ice type copy operator called" << std::endl;
	type = copy.type;
	return (*this);
}

AMateria* Ice::clone() const
{
	AMateria	*ice = new Ice();

	return (ice);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
