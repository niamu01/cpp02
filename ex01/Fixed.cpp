#include "Fixed.hpp"

const int	Fixed::_bits = 8;

Fixed::Fixed(void) {
	std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	_value = value << _bits;
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(value * (1 << _bits));
}

Fixed::Fixed(const Fixed &rhs) {
	*this = rhs;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed(void) {
	std::cout << "Destrutor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed &rhs) {
	std::cout << "Assignation operation called" << std::endl;
	_value = rhs._value;
	return (*this);
}

int	Fixed::getRawBits(void) const {
	return (_value);
}

void	Fixed::setRawBits(int const raw) {
	_value = raw;
}

int	Fixed::toInt(void) const {
	return (_value >> _bits);
}

float	Fixed::toFloat(void) const {
	return (float(_value) / (1 << _bits));
}

std::ostream&	operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat(); //고정 소수점 값을 toFloat 함수를 통해 부동 소수점으로 출력
	return out;
}