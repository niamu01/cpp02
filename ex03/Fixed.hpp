/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 05:20:18 by yeju              #+#    #+#             */
/*   Updated: 2022/03/30 21:38:59 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
public:
	Fixed(void);
	Fixed(const int fixed);
	Fixed(const float fixed);
	Fixed(const Fixed &rhs);
	~Fixed(void);

	Fixed & operator=(const Fixed &rhs);

//비교연산자 6가지
	bool operator>(Fixed const &rhs) const;
	bool operator<(Fixed const &rhs) const;
	bool operator>=(Fixed const &rhs) const;
	bool operator<=(Fixed const &rhs) const;
	bool operator==(Fixed const &rhs) const;
	bool operator!=(Fixed const &rhs) const;

//산술연산자 4가지
	Fixed operator+(Fixed const &rhs) const;
	Fixed operator-(Fixed const &rhs) const;
	Fixed operator*(Fixed const &rhs) const;
	Fixed operator/(Fixed const &rhs) const;

//사전증가 후증가 사전증가 사전감소: 고정소수점 값을 증가/감소 시킨다
	Fixed & operator++(void);
	Fixed operator++(int);
	Fixed & operator--(void);
	Fixed operator--(int);

//이전 문제
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	
	float	toFloat(void) const;
	int		toInt(void) const;

//소수점 값에 대한 '참조'를 가져와 가장 작은 값에 대한 참조를 반환하는 정적 멤버 함수 
	static Fixed & min(Fixed & f1, Fixed & f2);
//두 개의 '고정' 소수점 값에 대한 참조를 가져오고 가장 작은 값에 대한 참조를 반환하는 오버로드
	static Fixed const & min(Fixed const & f1, Fixed const & f2);
//소수점 값에 대한 '참조'를 가져와 가장 큰 값에 대한 참조를 반환하는 정적 멤버 함수 
	static Fixed & max(Fixed & f1, Fixed & f2);
//두 개의 '고정' 소수점 값에 대한 참조를 가져오고 가장 큰 값에 대한 참조를 반환하는 오버로드
	static Fixed const & max(Fixed const & f1, Fixed const & f2);

private:
	int _value;
	const static int _bits;
};

std::ostream &	operator<<(std::ostream & s, const Fixed & fixed);

#endif