
#include "HumanA.hpp"

HumanA::HumanA(std::string _name, Weapon &_weapon) : weapon(_weapon), name(_name)
{
	std::cout << "create HumanA : " << name << " with " << weapon.getType() << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "delete HumanA : " << name << std::endl;
}

void	HumanA::attack()
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
