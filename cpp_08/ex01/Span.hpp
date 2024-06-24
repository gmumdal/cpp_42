
#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <set>
#include <vector>
#include <cstdlib>
#include <ctime>

class Span
{
	private:
		std::multiset<int>	mset;
		unsigned int	n;
		Span();

	public:
		Span(unsigned int N);
		~Span();
		Span(const Span &copy);
		Span &operator= (const Span &copy);
	
		void addNumber(int add);
		int	shortestSpan() const;
		int	longestSpan() const;

		template <typename T>
		void addNumbers(T &container)
		{
			std::cout << "Insert " << container.size() << " numbers" << std::endl;
			try
			{
				if (container.size() > n - mset.size()) {
					mset.insert(container.begin(), container.begin() + n - mset.size());
					throw std::logic_error("error : container is bigger than size!");
				}
				mset.insert(container.begin(), container.end());
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
			std::cout << "Span volume " << mset.size() << "/" << n << std::endl;
		}
};

#endif
