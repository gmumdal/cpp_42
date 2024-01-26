
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
	
	file.append(".replace");
	std::ofstream	output(file);

	if (!input.is_open() || !output.is_open())
	{
		input.close();
		output.close();
		std::cerr << "error" << std::endl;
		return (1);
	}
	std::stringstream	buffer;
	buffer << input.rdbuf();
	std::string	line = buffer.str();
	std::cout << line;
	size_t	found = 0;
	while (42)
	{
		found = line.find(av[2], found);
		if (found == std::string::npos)
			break ;
		line.erase(found, strlen(av[2]));
		for (size_t i = 0; i < strlen(av[3]); i++)
			line.insert(found + i, 1, av[3][i]);
		found += strlen(av[3]);
	}
	output << line << std::endl;
	input.close();
	output.close();
	return (0);
}
