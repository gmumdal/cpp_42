
#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap Default Constructor called" << std::endl;
	name = "noname";
	hit_point = 100;
	energy_point = 100;
	attack_damage = 30;	
}

FragTrap::FragTrap(const std::string &_name)
{
	std::cout << "FragTrap " << _name << " Constructor called" << std::endl;
	name = _name;
	hit_point = 100;
	energy_point = 100;
	attack_damage = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Distructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy)
{
	std::cout << "FragTrap Copy Constructor called" << std::endl;
	name = copy.name;
	hit_point = copy.hit_point;
	energy_point = copy.energy_point;
	attack_damage = copy.attack_damage;
}

FragTrap &FragTrap::operator= (const FragTrap &copy)
{
	if (this == &copy)
		return (*this);
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
	name = copy.name;
	hit_point = copy.hit_point;
	energy_point = copy.energy_point;
	attack_damage = copy.attack_damage;
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	if (hit_point == 0)
	{
		std::cout << "FragTrap " << name << " is dead" << std::endl;
		return ;
	}
	if (energy_point == 0)
	{
		std::cout << "FragTrap " << name << " hasn't enough energy" << std::endl;
		return ;
	}
	energy_point--;
	std::cout << "FragTrap " << name << " make a request for high five!" << std::endl;
}
