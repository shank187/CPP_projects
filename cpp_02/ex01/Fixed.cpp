# include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : value(0){
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
    this->value = other.value;
    std::cout << "Copy constructor called" <<  std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->value = other.value;
    return *this;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    this->value = value << fractionalBits;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    this->value = static_cast<int>(roundf(value * (1 << fractionalBits)));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}
int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->value;
}
void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
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