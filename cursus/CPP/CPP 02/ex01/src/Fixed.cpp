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
	std::cout<<"(Fixed) Default Constructor called"<<std::endl;
}

Fixed::Fixed(const int n) 
{
	this->_num = n * ft_pow(2, this->_bits);
	std::cout<<"(Fixed) Int Constructor called"<<std::endl;
}

Fixed::Fixed(const float n) 
{
	this->_num = roundf(n * ft_pow(2, this->_bits));
	std::cout<<"(Fixed) Float Constructor called"<<std::endl;
}

Fixed::Fixed(const Fixed &copy) 
{
	std::cout<<"(Fixed) Copy constructor called"<<std::endl;
	*this = copy;
}

Fixed::~Fixed() 
{
	std::cout<<"(Fixed) Destructor called"<<std::endl;
}

Fixed	&Fixed::operator=(const Fixed &copy)
{
	std::cout<<"(Fixed) Copy assignment operator called"<<std::endl;
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