
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int	main(int ac, char **av)
{
	if (ac != 4)
		return (1);

	std::string	file = av[1];
	std::ifstream	input(file);
	if (!input.is_open())
	{
		std::cerr << "error" << std::endl;
		return (1);
	}
	file.append(".replace");
	std::ofstream	output(file);
	if (!output.is_open())
	{
		input.close();
		std::cerr << "error" << std::endl;
		return (1);
	}

	std::stringstream	buffer;
	buffer << input.rdbuf();
	std::string	str = buffer.str();
	size_t	found = 0;
	while (42)
	{
		if (!strlen(av[2]))
			break ;
		found = str.find(av[2], found);
		if (found == std::string::npos)
			break ;
		str.erase(found, strlen(av[2]));
		for (size_t i = 0; i < strlen(av[3]); i++)
			str.insert(found + i, 1, av[3][i]);
		found += strlen(av[3]);
	}
	output << str;
	input.close();
	output.close();
	return (0);
}
