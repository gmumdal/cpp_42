
#include "Harl.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
		return (1);

	std::string	level = av[1];
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	Harl	harl;
	int		switch_level = 4;

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
			switch_level = i;
	}
	switch (switch_level)
	{
		case 0:
			harl.complain(levels[0]);
			std::cout << std::endl;
		case 1:
			harl.complain(levels[1]);
			std::cout << std::endl;
		case 2:
			harl.complain(levels[2]);
			std::cout << std::endl;
		case 3:
			harl.complain(levels[3]);
			break ;
		default:
			harl.complain("not level");
	}
	return (0);
}
