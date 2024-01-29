
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class	Fixed
{
	private:
		int					value;
		static const int	bits = 8;

	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &copy); // 복사의 대상이 변경되지 않게 const
		Fixed	&operator=(const Fixed &copy);

		int		getRawBits(void)	const;
		void	setRawBits(int const raw);
};

#endif
