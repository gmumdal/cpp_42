
#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <set>

class Span
{
	private:
		std::multiset<int>	vec;
		unsigned int		n;
		Span();

	public:
		Span(unsigned int N);
		~Span();
		Span(const Span &copy);
		Span &operator= (const Span &copy);
	
		void	addNumber(int add);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
};

#endif