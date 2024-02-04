
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : name("noname"), hit_point(100), energy_point(50), attack_damage(20)
{
	std::cout << "Default Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &_name) : name(_name), hit_point(100), energy_point(50), attack_damage(20)
{
	std::cout << _name << " Constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Distructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : name(copy.name), hit_point(copy.hit_point), energy_point(copy.energy_point), attack_damage(copy.attack_damage)
{
	std::cout << "Copy Constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator= (const ScavTrap &copy)
{
	if (this == &copy)
		return (*this);
	std::cout << "Copy assignment operator called" << std::endl;
	name = copy.name;
	hit_point = copy.hit_point;
	energy_point = copy.energy_point;
	attack_damage = copy.attack_damage;
	return (*this);
}

std::string	ScavTrap::get_name(void) const
{
	return (name);
}

int	ScavTrap::get_hit_point(void) const
{
	return (hit_point);
}

int	ScavTrap::get_energy_point(void) const
{
	return (energy_point);
}
	
int	ScavTrap::get_attack_damage(void) const
{
	return (attack_damage);
}

void	ScavTrap::attack(const std::string &target)
{
	if (hit_point == 0)
	{
		std::cout << "ScavTrap " << name << " is dead" << std::endl;
		return ;
	}
	if (energy_point == 0)
	{
		std::cout << "ScavTrap " << name << " hasn't enough energy" << std::endl;
		return ;
	}
	energy_point--;
	std::cout << "ScavTrap " << name
		<< " attacks " << target
			<< ", causing " << attack_damage
				<< " points of damage!" << std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	if (hit_point == 0)
	{
		std::cout << "ScavTrap " << name << " is dead" << std::endl;
		return ;
	}
	hit_point -= amount;
	std::cout << "ScavTrap " << name
		<< " attacked " << amount
				<< " points of damage!" << std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (hit_point == 0)
	{
		std::cout << "ScavTrap " << name << " is dead" << std::endl;
		return ;
	}
	if (energy_point == 0)
	{
		std::cout << "ScavTrap " << name << " hasn't enough energy" << std::endl;
		return ;
	}
	hit_point += amount;
	std::cout << "ScavTrap " << name
		<< " repair " << amount
				<< " points of health!" << std::endl;
}
