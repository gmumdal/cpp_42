
#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	if (point.point_inline(a, b))
		return (false);
	if (point.point_inline(b, c))
		return (false);
	if (point.point_inline(a, c))
		return (false);
	if (a.tri_area(b, c) == Fixed(point.tri_area(a, b) + point.tri_area(b, c) + point.tri_area(a, c)))
		return (true);	
	return (false);
}
