
#include "Zombie.hpp"

int	main(void)
{
	Zombie	zombie("zombie");
	Zombie	*newzombie = newZombie("newzombie");

	zombie.announce();
	newzombie->announce();
	randomChump("chump");
	delete newzombie;
}
