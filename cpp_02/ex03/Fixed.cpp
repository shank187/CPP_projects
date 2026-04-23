# include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : value(0){
}

Fixed::Fixed(const Fixed& other)
{
    this->value = other.value;
}

Fixed::Fixed(const int value)
{
    this->value = value << fractionalBits;
}

Fixed::Fixed(const float value)
{
    this->value = static_cast<int>(roundf(value * (1 << fractionalBits)));
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits() const
{
    return this->value;
}
void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(this->value) / (1 << fractionalBits);
}
int Fixed::toInt(void) const
{
    return this->value >> fractionalBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other)
        this->value = other.value;
    return *this;
}
Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed result;
    result.value = this->value + other.value;
    return result;
}
Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed result;
    result.value = this->value - other.value;
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const
{
    long temp = static_cast<long>(this->value) * static_cast<long>(other.value);
    Fixed result;
    result.value = static_cast<int>(temp >> fractionalBits);
    return result;
}


Fixed Fixed::operator/(const Fixed& other) const
{
    Fixed result;

    if (other.value == 0)
    {
        std::cerr << "Error: division by zero" << std::endl;
        return Fixed();
    }
    long temp = (static_cast<long>(this->value) << fractionalBits) / static_cast<long>(other.value);
    result.value = static_cast<int>(temp);
    return result;
}

Fixed& Fixed::operator++()        // Prefix increment
{
    this->value++;
    return *this;
}

Fixed Fixed::operator++(int)    // Postfix increment
{
    Fixed temp = *this;
    this->value++;
    return temp;
}

Fixed& Fixed::operator--()       // Prefix decrement
{
    this->value--;
    return *this;
}

Fixed Fixed::operator--(int)    // Postfix decrement
{
    Fixed temp = *this;
    this->value--;
    return temp;
}

bool Fixed::operator>(const Fixed& other) const
{
    return this->value > other.value;
}

bool Fixed::operator<(const Fixed& other) const
{
    return this->value < other.value;
}

bool Fixed::operator>=(const Fixed& other) const
{
    return this->value >= other.value;
}

bool Fixed::operator<=(const Fixed& other) const
{
    return this->value <= other.value;
}
bool Fixed::operator==(const Fixed& other) const
{
    return this->value == other.value;
}
bool Fixed::operator!=(const Fixed& other) const
{
    return this->value != other.value;
}
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b) ? a : b;
}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a < b) ? a : b;
}
Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a > b) ? a : b;
}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a > b) ? a : b;
}

