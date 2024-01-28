
#include "Zombie.hpp"

int	main(void)
{
	Zombie	zombie("Foo");
	Zombie	*newzombie = newZombie("newFoo");

	zombie.announce();
	newzombie->announce();
	randomChump("chump");
	delete newzombie;
}
