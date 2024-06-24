
#include "easyfind.hpp"
#include <vector>

int	main(void)
{
	std::vector< int > vec;

	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(50);
	try
	{
		std::cout << *easyfind(vec, 50) << std::endl;
		std::cout << *easyfind(vec, 70) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
