
#include "Weapon.hpp"

Weapon::Weapon()
{
	std::cout << "create Weapon : unarmed" << std::endl;
}

Weapon::Weapon(std::string _type) : type(_type)
{
	std::cout << "create Weapon : " << type << std::endl; 
}
Weapon::~Weapon()
{
	std::cout << "delete Weapon : " << type << std::endl; 
}

const std::string	&Weapon::getType()
{
	return (type);
}
void	Weapon::setType(std::string _type)
{
	type = _type;
}
