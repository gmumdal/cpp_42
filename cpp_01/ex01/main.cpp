
#include "Zombie.hpp"

int	main(void)
{
	Zombie	zombie("zombie");
	Zombie	*zombies = zombieHorde(5, "zombie");

	zombie.announce();
	for (int i = 0; i < 5; i++)
		zombies[i].announce();
	delete[] zombies;
}
