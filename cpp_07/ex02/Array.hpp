
#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array
{
	private:
		T				*all;
		unsigned int	size;

	public:
		Array()
		{
			all = new T();
			size = 0;
			std::cout << "Array zero constructor called" << std::endl;
		}
		Array(unsigned int n)
		{
			all = new T[n];
			size = n;
			std::cout << "Array n constructor called" << std::endl;
		}
		~Array()
		{
			delete all;
			std::cout << "Array destructor called" << std::endl;
		}
		Array(const Array &copy)
		{
			size = copy.size;
			all = new T[size];
			for (unsigned int i = 0; i < size; i++)
				all[i] = copy.all[i];
			std::cout << "Array copy constructor called" << std::endl;
		}
		Array operator= (const Array &copy)
		{
			if (this == &copy)
				return (*this);
			size = copy.size;
			delete all;
			all = new T[size];
			for (unsigned int i = 0; i < size; i++)
				all[i] = copy.all[i];
			std::cout << "Array copy operator called" << std::endl;
			return (*this);
		}
		unsigned int	size(void) const
		{
			return (size);
		}
		T &operator[] (int index)
		{
			if (index < 0 || index >= (int)size)
				throw std::out_of_range("index: out of bound");
			return (all[index]);
		}
};

#endif
