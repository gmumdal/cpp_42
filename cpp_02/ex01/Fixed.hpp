
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class	Fixed
{
	private:
		int					value;
		static const int	bits = 8;

	public:
		Fixed();
		Fixed(const int _value);
		Fixed(const float _value);
		~Fixed();
		Fixed(const Fixed &copy); // 복사의 대상이 변경되지 않게 const
		Fixed	&operator= (const Fixed &copy);

		int		getRawBits(void)	const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream	&operator<< (std::ostream& os, const Fixed& fixed);

#endif
