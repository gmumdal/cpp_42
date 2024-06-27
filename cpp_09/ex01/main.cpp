
#include "RPN.hpp"

int	main(int ac, char **av)
{
	try
	{
		if (ac != 2)
			throw std::logic_error("Error: incorrect argument");
		RPN	rpn(av[1]);
		std::cout << rpn.getResult() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
}

