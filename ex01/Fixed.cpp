#include "Fixed.hpp"

const int	Fixed::_bits = 8;

Fixed::Fixed(void) {
	_value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	_value = value << _bits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
{
	_value = roundf(value * (1 << _bits));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed(void)
{
	std::cout << "Destrutor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed &src)
{
	std::cout << "Assignation operation called" << std::endl;

	_value = src._value;
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	return (_value);
}

void	Fixed::setRawBits(int const raw)
{
	_value = raw;
}

int	Fixed::toInt(void) const
{
	return (_value >> _bits);
}

float	Fixed::toFloat(void) const
{
	return (float(_value) / (1 << _bits));
}

std::ostream&	operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat(); //고정 소수점 값을 toFloat 함수를 통해 부동 소수점으로 출력
	return out;
}