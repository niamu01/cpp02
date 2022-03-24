/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 03:06:09 by yeju              #+#    #+#             */
/*   Updated: 2022/03/24 03:06:11 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
private:
	int value; //고정 소점 값을 저장할 정수
	const static int bits; //소수비트수를 지정하기 위한 정적상수정수 이 상수는 항상 8자리
public:
	Fixed(void); //고정소수점값을 0으로 초기화하는 기본생성자
	Fixed(const Fixed &src); //복사생성자
	~Fixed(void); //소멸자

	Fixed & operator=(Fixed const &src); //할당연산자과부하
	
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif