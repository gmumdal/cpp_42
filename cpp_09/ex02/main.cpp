
#include "PmergeMe.hpp"

#include <sys/time.h>

int	main(int ac, char **av)
{
	clock_t start;
	double result_vec, result_lst;
	try
	{
		if (ac == 1)
			throw std::logic_error("Error: argument fail");
		PmergeMe merge(ac, av);
		merge.printArr(BEFORE);
		start = clock();
		merge.mergeInsertVec();
		result_vec = clock() - start;
		start = clock();
		merge.mergeInsertLst();
		result_lst = clock() - start;
		merge.printArr(AFTER);
		std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : " << static_cast<float>(result_vec) * 1000000 / CLOCKS_PER_SEC << " us" << std::endl;
		std::cout << "Time to process a range of " << ac - 1 << " elements with std::list   : " << static_cast<float>(result_lst) * 1000000 / CLOCKS_PER_SEC << " us" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
