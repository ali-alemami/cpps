#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_raw = 0;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	_raw = other._raw;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	_raw = n * (1 << _fractionalBits);
}

Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called" << std::endl;
	_raw = roundf(n * (1 << _fractionalBits));
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_raw = other._raw;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_raw);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_raw = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(_raw) / (1 << _fractionalBits));
}

int	Fixed::toInt(void) const
{
	return (_raw / (1 << _fractionalBits));
}

std::ostream& operator<<(std::ostream& out, const Fixed& f)
{
	out << f.toFloat();
	return (out);
}

bool	Fixed::operator<(const Fixed& other) const
{
	return (this->_raw < other._raw);
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return (_raw <= other._raw);
}

bool	Fixed::operator>(const Fixed& other) const
{
	return (_raw > other._raw);
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return (_raw >= other._raw);
}

bool	Fixed::operator==(const Fixed& other) const
{
	return (_raw == other._raw);
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return (_raw != other._raw);
}

Fixed	Fixed::operator+(const Fixed& other) const
{
	Fixed	result;

	result.setRawBits(_raw + other._raw);
	return (result);
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	Fixed	result;

	result.setRawBits(_raw - other._raw);
	return (result);
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	Fixed	result;

	result.setRawBits(roundf(static_cast<float>(_raw) * other._raw / (1 << _fractionalBits)));
	return (result);
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	Fixed	result;

	result.setRawBits(roundf(static_cast<float>(_raw) * (1 << _fractionalBits) / other._raw));
	return (result);
}
//divide by 0 its gonna crash :)

Fixed&	Fixed::operator++()
{
	_raw += 1;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);
	_raw+= 1;
	return (temp);
}

Fixed&	Fixed::operator--()
{
	_raw -= 1;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);
	_raw -= 1;
	return (temp);
}

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b ? a : b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b ? a : b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b ? a : b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b ? a : b);
}
