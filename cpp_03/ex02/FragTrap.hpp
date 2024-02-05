
#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP

#include "ClapTrap.hpp"

class	FragTrap : public   ClapTrap
{
	public:
		FragTrap();
		FragTrap(const std::string &_name);
		~FragTrap();
		FragTrap(const FragTrap &copy);
		FragTrap &operator= (const FragTrap &copy);

		void	highFivesGuys(void);
};

#endif
