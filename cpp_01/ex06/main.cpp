
#include "Harl.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
		return (1);

	std::string	level = av[1];
	Harl	harl;

	harl.complain(level);
	return (0);
}
