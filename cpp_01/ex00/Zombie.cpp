
#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::Zombie(std::string _name) : name(_name)
{
	std::cout << name << " : create" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << name << " : remove" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}
