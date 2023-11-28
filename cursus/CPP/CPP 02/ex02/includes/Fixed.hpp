#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
    private:
        int              _num;
        static const int _bits;
    public:
        Fixed();
        Fixed(const Fixed &copy);
        ~Fixed();
        Fixed(const int n);
        Fixed(const float n);
        
        //OPERATORS
        Fixed   &operator=(const Fixed &copy);
        //Comparision operators
        bool   operator>(const Fixed &copy) const;
        bool   operator<(const Fixed &copy) const;
        bool   operator>=(const Fixed &copy) const;
        bool   operator<=(const Fixed &copy) const;
        bool   operator==(const Fixed &copy) const;
        bool   operator!=(const Fixed &copy) const;

        //Arithmetic operators
        Fixed   operator+(const Fixed &copy) const;
        Fixed   operator-(const Fixed &copy) const;
        Fixed   operator*(const Fixed &copy) const;
        Fixed   operator/(const Fixed &copy) const;

        //Other operators
        Fixed   &operator++(void);
        Fixed   &operator--(void);
        Fixed   operator++(int);
        Fixed   operator--(int);

        //overloaded member functions
        static const Fixed   &min(const Fixed &cp1, const Fixed &cp2);
        static const Fixed   &max(const Fixed &cp1, const Fixed &cp2);
        Fixed   &min(Fixed &cp1, Fixed &cp2);
        Fixed   &max(Fixed &cp1, Fixed &cp2);

        //Functions
        float	toFloat(void) const;
        int	    toInt(void) const;
        void    setRawBits(int const raw);
        int     getRawBits(void) const;
};

    std::ostream    &operator<<(std::ostream& os, const Fixed &cp);

#endif