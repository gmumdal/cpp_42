
#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstdlib>
#include <ctime>

template <typename T>
class Array
{
	private:
		T		*all;
		size_t	length;

	public:
		Array() : length(0)
		{
			all = new T[0];
			std::cout << "Array zero constructor called" << std::endl;
		}
		Array(size_t n) : length(n)
		{
			all = new T[n];
			std::cout << "Array n constructor called" << std::endl;
		}
		~Array()
		{
			delete [] all;
			std::cout << "Array destructor called" << std::endl;
		}
		Array(const Array &copy) : length(copy.length)
		{
			all = new T[length];
			for (size_t i = 0; i < length; i++)
				all[i] = copy.all[i];
			std::cout << "Array copy constructor called" << std::endl;
		}
		Array operator= (const Array &copy)
		{
			if (this == &copy)
				return (*this);
			length = copy.length;
			delete [] all;
			all = new T[length];
			for (size_t i = 0; i < length; i++)
				all[i] = copy.all[i];
			std::cout << "Array copy operator called" << std::endl;
			return (*this);
		}
		size_t	size(void) const
		{
			return (length);
		}
		T &operator[] (size_t index)
		{
			if (index < 0 || index >= length)
				throw std::out_of_range("index: out of bound");
			return (all[index]);
		}
		const T &operator[] (size_t index) const
		{
			if (index < 0 || index >= length)
				throw std::out_of_range("index: out of bound");
			return (all[index]);
		}
};

#endif
