
#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	if (N <= 0)
		return (NULL);
	Zombie	*zombies = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		std::string	tmp = name;
		std::ostringstream	oss;
		oss << i;

		zombies[i].set_name(tmp.append(oss.str()));
	}
	return (zombies);
}
