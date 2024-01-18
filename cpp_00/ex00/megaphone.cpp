
#include <iostream>

static void	to_upper(char *av);

int	main(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
		to_upper(av[i]);
	for (int i = 1; i < ac; i++)
		std::cout << av[i];
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
}

static void	to_upper(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] >= 'a' && av[i] <= 'z')
			av[i] -= 32;
		i++;
	}
}
