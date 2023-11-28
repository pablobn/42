#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <string>

class Fixed
{
    private:
        int              _num;
        static const int _bits;
    public:
        Fixed();
        Fixed(const Fixed &copy);
        ~Fixed();
        Fixed& operator=(const Fixed &copy);
        void    setRawBits(int const raw);
        int     getRawBits(void) const;
};

#endif