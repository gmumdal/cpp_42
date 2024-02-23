
#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array
{
	private:
		T				*all;
		unsigned int	length;

	public:
		Array()
		{
			all = new T();
			length = 0;
			std::cout << "Array zero constructor called" << std::endl;
		}
		Array(unsigned int n)
		{
			all = new T[n];
			length = n;
			std::cout << "Array n constructor called" << std::endl;
		}
		~Array()
		{
			delete [] all;
			std::cout << "Array destructor called" << std::endl;
		}
		Array(const Array &copy)
		{
			length = copy.length;
			all = new T[length];
			for (unsigned int i = 0; i < length; i++)
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
			for (unsigned int i = 0; i < length; i++)
				all[i] = copy.all[i];
			std::cout << "Array copy operator called" << std::endl;
			return (*this);
		}
		unsigned int	size(void) const
		{
			return (length);
		}
		T &operator[] (int index)
		{
			if (index < 0 || index >= (int)length)
				throw std::out_of_range("index: out of bound");
			return (all[index]);
		}
};

#endif
