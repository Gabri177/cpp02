#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point{

	private:
		const Fixed	x;
		const Fixed	y;
	public:

					Point(void);
					Point(float p1, float p2);
					~Point(void);
					Point(const Point &obj);
	Point&			operator=(const Point &obj);
	Fixed			getX(void) const;
	Fixed			getY(void) const;
	static float	crossProduct(Point const &p1, Point const &p2, Point const &base);
};

bool 			bsp( Point const a, Point const b, Point const c, Point const point);
#endif