
#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <set>
#include <vector>

class Span
{
	private:
		std::set<int>	mset;
		unsigned int	n;
		Span();

	public:
		Span(unsigned int N);
		~Span();
		Span(const Span &copy);
		Span &operator= (const Span &copy);
	
		void	addNumber(int add);
		int		shortestSpan() const;
		int		longestSpan() const;

		template <typename T>
		void	addNumbers(T &container)
		{
			try
			{
				typename T::iterator	iter = container.begin();
				while (42)
				{
					if (mset.size() == n)
						throw std::logic_error("error : Span already full!");
					if (iter == container.end())
						break ;
					mset.insert(*iter++);
					if (mset.size() % 1000 == 0)
						std::cout << "Span size " << mset.size() << std::endl;
				}
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}
};

#endif
