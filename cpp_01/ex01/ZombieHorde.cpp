
#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*zombies = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		std::string	tmp = name;
		zombies[i].set_name(tmp.append(std::to_string(i)));
	}
	return (zombies);
}
