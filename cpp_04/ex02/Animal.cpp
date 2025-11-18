#include "Animal.hpp"
#include <iostream>


A_Animal::A_Animal() : type("Animal")
{
    std::cout << "Animal default constructor called" << std::endl;
}

A_Animal::A_Animal(const std::string& type) : type(type)
{
    std::cout << "Animal parameterized constructor called" << std::endl;
}

A_Animal::~A_Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}
A_Animal::A_Animal(const A_Animal& other) : type(other.type)
{
    std::cout << "Animal copy constructor called" << std::endl;
}

A_Animal& A_Animal::operator=(const A_Animal& other)
{
    std::cout << "Animal assignment operator called" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
        std::cout << "Animal assignment operator called" << std::endl;
    }
    return *this;
}

std::string A_Animal::getType() const
{
    return type;
}
