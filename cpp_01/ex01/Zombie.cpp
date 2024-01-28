
#include "Zombie.hpp"

Zombie::Zombie() : name("")
{
	std::cout << "create : no name" << std::endl;
}

Zombie::Zombie(std::string _name) : name(_name)
{
	std::cout << "create : " << name << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "remove : " << name << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::set_name(std::string _name)
{
	name = _name;
	std::cout << "set name : " << name << std::endl;
}
