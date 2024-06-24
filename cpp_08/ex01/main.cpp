
#include "Span.hpp"

int	main(void)
{
	{
		Span tmp(5);

		tmp.addNumber(3);
		tmp.addNumber(3);
		tmp.addNumber(34);
		tmp.addNumber(100);
		tmp.addNumber(33);

		std::cout << std::endl;
		tmp.addNumber(6);
		std::cout << std::endl;
		std::cout << "longest span : " << tmp.longestSpan() << std::endl;
		std::cout << "shortest span : " << tmp.shortestSpan() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << std::endl;
	{
		Span tmp(100000);
		std::vector<int> vec;
		std::srand(std::time(NULL));
		for (int i = 0; i < 100000; i++)
			vec.push_back(rand());
		tmp.addNumbers(vec);
		std::cout << std::endl;
		tmp.addNumber(6);
		std::cout << std::endl;
		std::cout << "longest span : " << tmp.longestSpan() << std::endl;
		std::cout << "shortest span : " << tmp.shortestSpan() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << std::endl;
	{
		Span tmp(1);
		tmp.addNumber(3);

		std::cout << std::endl;
		std::cout << "longest span : " << tmp.longestSpan() << std::endl;
		std::cout << "shortest span : " << tmp.shortestSpan() << std::endl;
	}
}
