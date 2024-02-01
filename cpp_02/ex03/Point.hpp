
#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class	Point
{
	private:
		Fixed const	x;
		Fixed const	y;
	
		Point	&operator= (const Point &copy);
		
	public:
		Point();
		Point(const float _x, const float _y);
		Point(const Point &copy);
		~Point();

		bool	point_inline(const Point &a, const Point &b) const;
		Fixed	tri_area(const Point &a, const Point &b) const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
