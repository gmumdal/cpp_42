
#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <iostream>
#include <string>

class	ClapTrap
{
	private:
		std::string	name;
		int			hit_point;
		int			energy_point;
		int 		attack_damage;

	public:
		ClapTrap();
		ClapTrap(const std::string &_name);
		~ClapTrap();
		ClapTrap(const ClapTrap &copy);
		ClapTrap &operator= (const ClapTrap &copy);

		void	attack(const std::string &target);
		void	takeDamage(unsigned int	amount);
		void	beRepaired(unsigned int amount);
		
		std::string	get_name(void)	const;
		int			get_attack_damage(void)	const;
};

#endif
