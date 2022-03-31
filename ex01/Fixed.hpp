/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:35:59 by yeju              #+#    #+#             */
/*   Updated: 2022/03/31 20:36:00 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
	int					_value;
	const static int	_bits;
public:
	Fixed(void);
	Fixed(const int fixed);
	Fixed(const float fixed);
	Fixed(const Fixed &rhs);
	Fixed &	operator=(Fixed const &rhs);
	~Fixed(void);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	
	float	toFloat( void ) const;
	int		toInt( void ) const;
};

std::ostream &	operator<<(std::ostream & out, const Fixed & fixed);

#endif