
#include "Harl.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
		return (1);

	Harl		harl;
	std::string	level  = av[1];
	harl.complain(level);
}
