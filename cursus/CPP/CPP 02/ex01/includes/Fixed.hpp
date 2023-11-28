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
        Fixed   &operator=(const Fixed &copy);
        float	toFloat(void) const;
        int	    toInt(void) const;
        void    setRawBits(int const raw);
        int     getRawBits(void) const;
};

    std::ostream    &operator<<(std::ostream& os, const Fixed &cp);

#endif