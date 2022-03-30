//2D 점을 나타내기 위해 정통 클래스 Point를 작성하는 것으로 시작하겠습니다.

#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include "Fixed.hpp"

class Point {
public:
	Point(); //생성자
	Point(Point const & rhs);
	Point(Fixed const x, Fixed const y);
	~Point(); //소멸자

	Fixed	get_x(void) const;
	Fixed	get_y(void) const;

private:
	Fixed const _x;
	Fixed const _y;
	
	Point & operator=(Point const & rhs);

};

#endif