#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
public:
	Fixed(void);
	Fixed(const int fixed); //상수 정수를 매개변수로 사용하고 이를 해당 fixed(8) 포인트 값으로 변환하는 생성자. 값은 0으로 초기화
	Fixed(const float fixed); //상수 부동 소수점을 매개변수로 사용하고 해당 고정(8) 소수점 값으로 변환하는 생성자. 값은 0으로 초기화
	Fixed(const Fixed &rhs);
	~Fixed(void);

	Fixed &	operator=(Fixed const &rhs);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	
	float	toFloat(void) const; //고정 소수점 값을 부동 소수점 값으로 변환합니다.
	int		toInt(void) const; //고정 소수점 값을 정수 값으로 변환합니다.
private:
	int					_value;
	const static int	_bits;
};

std::ostream &	operator<<(std::ostream & s, const Fixed & fixed); //고정 소수점 값의 부동 소수점 표현을 매개변수 출력 스트림에 삽입하는 « 연산자에 대한 오버로드.

#endif