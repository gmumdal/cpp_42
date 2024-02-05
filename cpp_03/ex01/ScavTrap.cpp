
#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "Default Constructor called" << std::endl;
	name = "noname";
	hit_point = 100;
	energy_point = 50;
	attack_damage = 20;	
}

ScavTrap::ScavTrap(const std::string &_name)
{
	std::cout << _name << " Constructor called" << std::endl;
	name = _name;
	hit_point = 100;
	energy_point = 50;
	attack_damage = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Distructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy) {}

ScavTrap &ScavTrap::operator= (const ScavTrap &copy)
{
	if (this == &copy)
		return (*this);
	std::cout << "Copy assignment operator called" << std::endl;
	ClapTrap::operator= (copy);
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
