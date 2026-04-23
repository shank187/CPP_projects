#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed {
private:
    int                 value;
    static const int    fractionalBits = 8;
public:
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed& other);
    Fixed();
    Fixed& operator=(const Fixed& other);
    ~Fixed();
    int getRawBits() const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;

};

std::ostream& operator<<(std::ostream& out, const Fixed& f);


#endif