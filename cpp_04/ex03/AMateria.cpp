
#include "AMateria.hpp"

AMateria::AMateria() : type("no_type")
{
	std::cout << "AMateria create" << std::endl;
}

AMateria::AMateria(std::string const &_type) : type(_type)
{
	std::cout << "AMateria create" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "AMateria delete" << std::endl;
}

AMateria::AMateria(const AMateria &copy)
{
	std::cout << "AMateria copy" << std::endl;
	type = copy.type;
}

AMateria &AMateria::operator= (const AMateria &copy)
{
	if (this == &copy)
		return (*this);
	std::cout << "AMateria copy operator" << std::endl;
	type = copy.type;
	return (*this);
}

std::string const &AMateria::getType() const
{
	return (type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << " * use AMateria at " << target.getName() << "* " << std::endl;
}
