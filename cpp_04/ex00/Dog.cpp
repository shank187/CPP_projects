#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const std::string& type) : Animal(type)
{
    std::cout << "Dog parameterized constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        std::cout << "Dog assignment operator called" << std::endl;
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Dog barks" << std::endl;
}

