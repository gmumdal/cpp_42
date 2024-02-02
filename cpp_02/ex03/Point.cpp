
#include "Point.hpp"

Point::Point() : x(0), y(0)
{
	std::cout << "Point Constructor called" << std::endl;
}

Point::Point(const float _x, const float _y) : x(_x), y(_y)
{
	std::cout << "Point float Constructor called" << std::endl;
}

Point::Point(const Point &copy) : x(copy.x), y(copy.y) {}

Point	&Point::operator= (const Point &copy)
{
	(void) copy;
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
	Fixed	abc((Fixed(0.5f) * ((a.x * b.y + b.x * y + x * a.y
			- b.x * a.y - x * b.y - a.x * y))));
	if (abc < 0)
		return (abc * Fixed(-1.0f));
	return (abc);
}
