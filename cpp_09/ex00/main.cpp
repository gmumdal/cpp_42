
#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	try
	{
		if (ac != 2)
			throw std::logic_error("Error : could not open file.");
		BitcoinExchange	btc;
		btc.init("data.csv");
		btc.exchange(av[1]);

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
	return (0);
}
