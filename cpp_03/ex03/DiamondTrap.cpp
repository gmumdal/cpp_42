
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "DiamondTrap Default Constructor called" << std::endl;
	name = "noname";
	ClapTrap::name = "noname_clap_name";
	hit_point = FragTrap::hit_point;
	energy_point = 50; // ScavTrap::energy_point
	attack_damage = FragTrap::attack_damage;
}

DiamondTrap::DiamondTrap(const std::string &_name)
{
	std::cout << "DiamondTrap " << _name << " Constructor called" << std::endl;
	name = _name;
	ClapTrap::name = _name + "_clap_name";
	hit_point = FragTrap::hit_point;
	energy_point = 50; // ScavTrap::energy_point
	attack_damage = FragTrap::attack_damage;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Distructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap Copy Constructor called" << std::endl;
	name = copy.name;
	hit_point = copy.hit_point;
	energy_point = copy.energy_point;
	attack_damage = copy.attack_damage;
}

DiamondTrap &DiamondTrap::operator= (const DiamondTrap &copy)
{
	if (this == &copy)
		return (*this);
	std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
	name = copy.name;
	hit_point = copy.hit_point;
	energy_point = copy.energy_point;
	attack_damage = copy.attack_damage;
	return (*this);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << name << " member function call : whoAmI" << std::endl;
	std::cout << "claptrap : " << ClapTrap::name << std::endl;
	std::cout << "diamondtrap : " << name << std::endl;
}
