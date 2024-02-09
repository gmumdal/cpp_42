
#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure constructor called" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure type distructor called" << std::endl;
}

Cure::Cure(const Cure &copy) : AMateria(copy)
{
	std::cout << "Cure type copy constructor called" << std::endl;
}

Cure &Cure::operator= (const Cure &copy)
{
	if (this == &copy)
		return (*this);
	std::cout << "Cure type copy operator called" << std::endl;
	type = copy.type;
	return (*this);
}

AMateria* Cure::clone() const
{
	AMateria	*cure = new Cure();

	return (cure);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "\'s wounds *" << std::endl;
}
