#include "Fixed.hpp"

float	ft_pow(float base, int exp)
{
	float result = 1;

	if (exp == 0)
		return (result);
	
	if (exp > 0)
	{
		for (int i = 0; i < exp; i++)
			result *= base;
	}
	else
	{
		for (int i = 0; i < -exp; i++)
			result /= base;
	}
	return (result);
}

const int Fixed::_bits = 8;

Fixed::Fixed() 
{
	this->_num = 0;
}

Fixed::Fixed(const int n) 
{
	this->_num = n * ft_pow(2, this->_bits);
}

Fixed::Fixed(const float n) 
{
	this->_num = roundf(n * ft_pow(2, this->_bits));
}

Fixed::Fixed(const Fixed &copy) 
{
	*this = copy;
}

Fixed::~Fixed() 
{
}

Fixed	&Fixed::operator=(const Fixed &copy)
{
	if (this != &copy)
	{
		this->_num = copy.getRawBits();
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, const Fixed &cp)
{
	return (os << cp.toFloat());
}

bool	Fixed::operator<(const Fixed &copy) const
{
	return (this->toFloat() < copy.toFloat());
}

bool	Fixed::operator>(const Fixed &copy) const
{
	return (this->toFloat() > copy.toFloat());
}

bool	Fixed::operator<=(const Fixed &copy) const
{
	return (this->toFloat() <= copy.toFloat());
}

bool	Fixed::operator>=(const Fixed &copy) const
{
	return (this->toFloat() >= copy.toFloat());
}

bool	Fixed::operator==(const Fixed &copy) const
{
	return (this->toFloat() == copy.toFloat());
}

bool	Fixed::operator!=(const Fixed &copy) const
{
	return (this->toFloat() >= copy.toFloat());
}

Fixed	Fixed::operator+(const Fixed &copy) const
{ 
	Fixed res = this->toFloat() + copy.toFloat();
	return (res);
}

Fixed	Fixed::operator-(const Fixed &copy) const
{
	Fixed res = this->toFloat() - copy.toFloat();
	return (res);
}

Fixed	Fixed::operator/(const Fixed &copy) const
{
	Fixed res = this->toFloat() / copy.toFloat();
	return (res);
}

Fixed	Fixed::operator*(const Fixed &copy) const
{
	Fixed res = this->toFloat() * copy.toFloat();
	return (res);
}

Fixed	&Fixed::operator++(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed	&Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed a;

	a = *this;
	++(*this);
	return (a);
}

Fixed	Fixed::operator--(int)
{
	Fixed res;

	res = *this;
	--(*this);
	return (res);
}

const Fixed   &Fixed::min(const Fixed &cp1, const Fixed &cp2)
{
	if (cp1 <= cp2)
		return (cp1);
	return (cp2);
}

const Fixed   &Fixed::max(const Fixed &cp1, const Fixed &cp2)
{
	if (cp1 >= cp2)
		return (cp1);
	return (cp2);
}

Fixed   &Fixed::min(Fixed &cp1, Fixed &cp2)
{
	if (cp1 <= cp2)
		return (cp1);
	return (cp2);
}

Fixed  &Fixed::max(Fixed &cp1, Fixed &cp2)
{
	if (cp1 >= cp2)
		return (cp1);
	return (cp2);
}

float	Fixed::toFloat(void) const
{
	return (this->_num * ft_pow(2, -this->_bits));
}

int	Fixed::toInt(void) const
{
	return (this->_num * ft_pow(2, -this->_bits));
}

int	Fixed::getRawBits(void) const
{
	return (this->_num);
}

void	Fixed::setRawBits(int const raw)
{
	_num = raw;
}