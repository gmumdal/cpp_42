
#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include "ClapTrap.hpp"

class	ScavTrap : public   ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(const std::string &_name);
		~ScavTrap();
		ScavTrap(const ScavTrap &copy);
		ScavTrap &operator= (const ScavTrap &copy);

		void	attack(const std::string &target);
		void	guardGate(void);
};

#endif
