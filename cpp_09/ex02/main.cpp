
#include "PMergeMe.hpp"

int	main(int ac, char **av)
{
	try
	{
		if (ac == 1)
			throw std::logic_error("Error: argument fail");
		PMergeMe	merge(ac, av);
		merge.print_arr(BEFORE);
		merge.merge_insert_vec();
		merge.print_arr(AFTER);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
