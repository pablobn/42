#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed() 
{
	this->_num = 0;
	std::cout<<"(Fixed) Default Constructor called"<<std::endl;
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

Fixed& Fixed::operator=(const Fixed &copy)
{
	std::cout<<"(Fixed) Copy assignment operator called"<<std::endl;
	if (this != &copy)
	{
		this->_num = copy.getRawBits();
	}
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout<<"(Fixed) getRawBits member function called"<<std::endl;
	return (this->_num);
}

void	Fixed::setRawBits(int const raw)
{
	_num = raw;
}