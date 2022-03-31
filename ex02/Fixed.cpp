/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 05:20:14 by yeju              #+#    #+#             */
/*   Updated: 2022/03/31 20:36:08 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed(void) {
	_value = 0;
}

Fixed::Fixed(const int value) {
	_value = value << _bits;
}

Fixed::Fixed(const float value){
	_value = roundf(value * (1 << _bits));
}

Fixed::Fixed(const Fixed &rhs) {
	*this = rhs;
}

Fixed::~Fixed(void) {
}

Fixed & Fixed::operator=(const Fixed &rhs) {
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
	out << fixed.toFloat();
	return out;
}

bool Fixed::operator>(Fixed const &rhs) const {
	return (rhs._value < this->_value);
}

bool Fixed::operator<(Fixed const &rhs) const {
	return (rhs._value > this->_value);
}

bool Fixed::operator>=(Fixed const &rhs) const {
	return (rhs._value <= this->_value);
}

bool Fixed::operator<=(Fixed const &rhs) const {
	return (rhs._value >= this->_value);
}

bool Fixed::operator==(Fixed const &rhs) const {
	return (rhs._value == this->_value);
}

bool Fixed::operator!=(Fixed const &rhs) const {
	return (rhs._value != this->_value);
}

Fixed Fixed::operator+(Fixed const &rhs) const {
	return (Fixed(this->toFloat() + rhs.toFloat()));
}
Fixed Fixed::operator-(Fixed const &rhs) const {
	return (Fixed(this->toFloat() - rhs.toFloat()));
}
Fixed Fixed::operator*(Fixed const &rhs) const {
	return (Fixed(this->toFloat() * rhs.toFloat()));
}
Fixed Fixed::operator/(Fixed const &rhs) const {
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed & Fixed::operator++(void) {
	this->_value++;
	return (*this);
}
Fixed Fixed::operator++(int) {
	Fixed f(*this);

	this->_value++;
	return (f);
}
Fixed & Fixed::operator--(void) {
	this->_value--;
	return (*this);
}
Fixed Fixed::operator--(int) {
	Fixed f(*this);

	this->_value--;
	return (f);
}

Fixed & Fixed::min(Fixed & f1, Fixed & f2) {
	if (f1 < f2)
		return (f1);
	return (f2);
}

Fixed const & Fixed::min(Fixed const & f1, Fixed const & f2) {
	if (f1 < f2)
		return (f1);
	return (f2);
}

Fixed & Fixed::max(Fixed & f1, Fixed & f2) {
	if (f1 > f2)
		return (f1);
	return (f2);
}

Fixed const & Fixed::max(Fixed const & f1, Fixed const & f2) {
	if (f1 > f2)
		return (f1);
	return (f2);
}