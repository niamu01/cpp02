#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include "Fixed.hpp"

class Point {
public:
	Point();
	Point(Fixed const x, Fixed const y);
	Point(Point const & rhs);
	Point & operator=(Point const &rhs);
	~Point();

	Fixed	getX(void) const;
	Fixed	getY(void) const;

private:
	Fixed const _x;
	Fixed const _y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif