
#include "easyfind.hpp"
#include <vector>

int	main(void)
{
	try
	{
		std::vector< int >	vec;
		std::vector< int >::iterator it;

		vec.push_back(10);
		vec.push_back(20);
		vec.push_back(30);
		vec.push_back(40);
		vec.push_back(50);
		it = easyfind(vec, 60);
		std::cout << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
