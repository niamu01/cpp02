/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 05:20:14 by yeju              #+#    #+#             */
/*   Updated: 2022/03/25 05:20:15 by yeju             ###   ########.fr       */
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

Fixed::Fixed(const Fixed &src) {
	*this = src;
}

Fixed::~Fixed(void) {

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

Fixed & Fixed::operator=(const Fixed &src) {
	_value = src._value;
	return (*this);
}

//비교연산자 6가지
/*
** 단순히 들어온 src의 value와 자기자신(this)를 연산자에 맞게 비교해준다
*/

bool Fixed::operator>(Fixed const &src) const {
	return (src._value < this->_value);
}

bool Fixed::operator<(Fixed const &src) const {
	return (src._value > this->_value);
}

bool Fixed::operator>=(Fixed const &src) const {
	return (src._value <= this->_value); //왜 반대?
}

bool Fixed::operator<=(Fixed const &src) const {
	return (src._value >= this->_value);
}

bool Fixed::operator==(Fixed const &src) const {
	return (src._value == this->_value);
}

bool Fixed::operator!=(Fixed const &src) const {
	return (src._value != this->_value);
}

//산술연산자 4가지
/*
** 자기자신(this->toFloat)와 들어온 더해야할 인자(src->toFloat)을 더한 값을 
** float를 인자로 받는 생성자를 불러 받아서 : Fixed(~~)
** 그 생성자를 거친 Fixed객체를 반환한다.
*/

Fixed Fixed::operator+(Fixed const &src) const {
	return (Fixed(this->toFloat() + src.toFloat()));
}
Fixed Fixed::operator-(Fixed const &src) const {
	return (Fixed(this->toFloat() - src.toFloat()));
}
Fixed Fixed::operator*(Fixed const &src) const {
	return (Fixed(this->toFloat() * src.toFloat()));
}
Fixed Fixed::operator/(Fixed const &src) const {
	return (Fixed(this->toFloat() / src.toFloat()));
}

//증감연산자 4가지
/*
** (*this)를 반환하는건 전위증감연산자, (f)를 반환하는건 후위증감연산자이다.
** ++i라면 아직 i가 없어 void를 받고, 코드 실행 전 연산자가 실행되어
** 값을 더한 뒤 자기자신의 포인터를 반환

** 후위증감연산자는 코드가 실행된 이후에 연산자가 실행되어야한다
** value에는 더하지만 f를 반환함으로서 더하기 전 상태의 fixed를 반환한다.
** 하지만 value는 증가한 상태라 이후 연산에서는 1 증가된 값으로 계산된다.
*/

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

//min, max
/*
** 오버로딩이 적용된 함수의 경우 들어오는 변수가 모두 const가 붙어있다
** 반환값또한 const가 붙어있어 함수 내에서 값이 변경되지 않기 때문에 안전하다
*/
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