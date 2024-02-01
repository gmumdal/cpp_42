
#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int _value) : value(_value << bits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float _value) : value(roundf(_value * (1 << bits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	if (this == &copy)
		return ;	
	std::cout << "Copy constructor called" << std::endl;
	value = copy.value;
}

Fixed&	Fixed::operator=(const Fixed &copy)
{
	if (this == &copy)
		return ;
	std::cout << "Copy assignment operator called" << std::endl;
	value = copy.value;
	return (*this);
}

int		Fixed::getRawBits(void)	const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (value);
}

void	Fixed::setRawBits(int const raw)
{
	value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)value / (1 << bits));
}

int		Fixed::toInt(void) const
{
	return (value >> bits);
}

std::ostream	&operator<< (std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}
