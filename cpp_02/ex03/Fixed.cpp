
#include "Fixed.hpp"

Fixed::Fixed() : value(0) {}

Fixed::Fixed(const int _value) : value(_value << bits) {}

Fixed::Fixed(const float _value) : value(roundf(_value * (1 << bits))) {}

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed &copy)
{
	value = copy.value;
}

Fixed&	Fixed::operator=(const Fixed &copy)
{
	if (this == &copy)
		return (*this);
	value = copy.value;
	return (*this);
}

int		Fixed::getRawBits(void)	const
{
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

Fixed	&Fixed::min(Fixed &first, Fixed &second)
{
	if (first <= second)
		return (first);
	else
		return (second);
}

const Fixed	&Fixed::min(const Fixed &first, const Fixed &second)
{
	if (first <= second)
		return (first);
	else
		return (second);
}

Fixed	&Fixed::max(Fixed &first, Fixed &second)
{
	if (first >= second)
		return (first);
	else
		return (second);
}

const Fixed	&Fixed::max(const Fixed &first, const Fixed &second)
{
	if (first >= second)
		return (first);
	else
		return (second);
}

Fixed	Fixed::operator+ (const Fixed &other) const
{
	return (this->toFloat() + other.toFloat());
}

Fixed	Fixed::operator- (const Fixed &other) const
{
	return (this->toFloat() - other.toFloat());
}

Fixed	Fixed::operator* (const Fixed &other) const
{
	return (this->toFloat() * other.toFloat());
}

Fixed	Fixed::operator/ (const Fixed &other) const
{
	return (this->toFloat() / other.toFloat());
}

bool	Fixed::operator> (const Fixed &other) const
{
	return (value > other.value);
}

bool	Fixed::operator< (const Fixed &other) const
{
	return (value < other.value);
}

bool	Fixed::operator>= (const Fixed &other) const
{
	return (value >= other.value);
}

bool	Fixed::operator<= (const Fixed &other) const
{
	return (value <= other.value);
}

bool	Fixed::operator== (const Fixed &other) const
{
	return (value == other.value);
}

bool	Fixed::operator!= (const Fixed &other) const
{
	return (value != other.value);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp = *this;

	this->value += 1;
	return (tmp);
}

Fixed	&Fixed::operator++()
{
	value += 1;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp = *this;

	value -= 1;
	return (tmp);
}

Fixed	&Fixed::operator--()
{
	value -= 1;
	return (*this);
}
