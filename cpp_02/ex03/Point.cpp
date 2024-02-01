
#include "Point.hpp"

Point::Point() : x(0), y(0)
{
	std::cout << "Point Default constructor called" << std::endl;
}

Point::Point(const float _x, const float _y) : x(_x), y(_y)
{
	std::cout << "Point Float constructor called" << std::endl;
}

Point::Point(const Point &copy)
{
	if (this == &copy)
		return ;
	std::cout << "Point Copy constructor called" << std::endl;
	x = copy.x;
	y = copy.y;
}

Point	&Point::operator= (const Point &copy)
{
	if (this == &copy)
		return (*this);
	std::cout << "Point Copy assignment operator called" << std::endl;
	x = copy.x;
	y = copy.y;
	return (*this);
}

Point::~Point()
{
	std::cout << "Point Destructor called" << std::endl;
}

bool	Point::point_inline(const Point &a, const Point &b) const
{
	if (a.x == x && a.y == y)
		return (true);
	else if (b.x == x && b.y == y)
		return (true);
	else if ((a.y - b.y) / (a.x - b.x) == (a.y - y) / (a.x - x))
		return (true);
	else
		return (false);
}

Fixed	Point::tri_area(const Point &a, const Point &b) const
{
	Fixed	abc((float)fabs(0.5 * ((a.x * b.y + b.x * y + x * a.y
			- b.x * a.y - x * b.y - a.x * y))));
	return (abc);
}
