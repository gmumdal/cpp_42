
#ifndef DIAMOND_TRAP_HPP
#define DIAMOND_TRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string	name;
	
	public:
		DiamondTrap();
		DiamondTrap(const std::string &_name);
		~DiamondTrap();
		DiamondTrap(const DiamondTrap &copy);
		DiamondTrap &operator= (const DiamondTrap &copy);

		void	whoAmI(void);
};

#endif
