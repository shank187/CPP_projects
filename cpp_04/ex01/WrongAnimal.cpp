#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
}
WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type) : type(type)
{
    std::cout << "WrongAnimal parameterized constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    if (this != &other)
    {
        this->type = other.type;
        std::cout << "WrongAnimal assignment operator called" << std::endl;
    }
    return *this;
}
void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal makes a sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return type;
}