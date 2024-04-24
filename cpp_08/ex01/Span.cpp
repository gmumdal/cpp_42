
#include "Span.hpp"

Span::Span() : n(0)
{
	std::cout << "Span constructor called" << std::endl;
}

Span::Span(unsigned int N) : n(N)
{
	std::cout << "Span " << N << " constructor called" << std::endl;
}

Span::~Span()
{	
	std::cout << "Span destructor called" << std::endl;
}

Span::Span(const Span &copy) : mset(copy.mset), n(copy.n)
{
	std::cout << "Span copy constructor called" << std::endl;
}

Span &Span::operator= (const Span &copy)
{
	mset = copy.mset;
	n = copy.n;
	std::cout << "Span copy operator called" << std::endl;
	return (*this);
}
// add 할때 중복이 있으면 예외
void	Span::addNumber(int add)
{
	try
	{
		if (mset.size() == n)
			throw std::logic_error("error : Span already full!");
		mset.insert(add);
		std::cout << "Span insert number " << add << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int	Span::shortestSpan() const
{
	try
	{
		if (mset.size() < 2)
			throw std::logic_error("error : Span is too small");
		int	min = 2147483647;
		std::multiset<int>::iterator	st = mset.begin();
		std::multiset<int>::iterator	en = mset.begin();
		en++;
		while (42)
		{
			if (en == mset.end())
				break ;
			if (min > *en - *st)
				min = *en - *st;
			st++;
			en++;
		}
		return (min);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (-1);
	}
}

int	Span::longestSpan() const
{
	try
	{
		if (mset.size() < 2)
			throw std::logic_error("error : Span is too small");
		std::multiset<int>::iterator	st = mset.begin();
		std::multiset<int>::iterator	en = mset.end();
		en--;
		return (*en - *st);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (-1);
	}
}
