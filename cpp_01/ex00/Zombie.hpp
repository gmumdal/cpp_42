
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class	Zombie
{
	private:
		std::string	name;
		Zombie();
	
	public:
		Zombie(std::string _name);
		~Zombie();

		void	announce(void);
		void	set_name(std::string name);
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif