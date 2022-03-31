/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 05:20:18 by yeju              #+#    #+#             */
/*   Updated: 2022/03/31 20:06:37 by yeju             ###   ########.fr       */
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

	bool operator>(Fixed const &rhs) const;
	bool operator<(Fixed const &rhs) const;
	bool operator>=(Fixed const &rhs) const;
	bool operator<=(Fixed const &rhs) const;
	bool operator==(Fixed const &rhs) const;
	bool operator!=(Fixed const &rhs) const;

	Fixed operator+(Fixed const &rhs) const;
	Fixed operator-(Fixed const &rhs) const;
	Fixed operator*(Fixed const &rhs) const;
	Fixed operator/(Fixed const &rhs) const;

	Fixed & operator++(void);
	Fixed operator++(int);
	Fixed & operator--(void);
	Fixed operator--(int);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	
	float	toFloat(void) const;
	int		toInt(void) const;

	static Fixed & min(Fixed & f1, Fixed & f2);
	static Fixed const & min(Fixed const & f1, Fixed const & f2);
	static Fixed & max(Fixed & f1, Fixed & f2);
	static Fixed const & max(Fixed const & f1, Fixed const & f2);

private:
	int _value;
	const static int _bits;
};

std::ostream &	operator<<(std::ostream & s, const Fixed & fixed);

#endif