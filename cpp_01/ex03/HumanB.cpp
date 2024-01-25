
#include "HumanB.hpp"

HumanB::HumanB(std::string _name) : name(_name)
{
	weapon = NULL;
	std::cout << "create HumanB : " << name << " without weapon" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "delete HumanB : " << name << std::endl;
}

void	HumanB::attack()
{
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &_weapon)
{
	weapon = &_weapon;
}
