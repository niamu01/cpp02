#include "Point.hpp"

Point::Point() {
    this->_x = 0;
    this->_y = 0;
}

Point::Point(Fixed const x, Fixed const y) {
    this->_x = x;
    this->_y = y;
}

Point::Point(Point const & rhs) {
    *this = rhs;
}

Point & Point::operator=(Point const &rhs) {
    (void)rhs;
	return (*this);
}

Point::~Point() {
}

Fixed   Point::getX(void) const {
    return (this->_x);
}

Fixed   Point::getY(void) const {
    return (this->_y);
}