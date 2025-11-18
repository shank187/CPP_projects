#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>

Dog::Dog() : A_Animal("Dog")
{
    std::cout << "Dog default constructor called" << std::endl;
    dog_brain = new(Brain);
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete dog_brain;
}

Dog::Dog(const std::string& type) : A_Animal(type)
{
    std::cout << "Dog parameterized constructor called" << std::endl;
    dog_brain = new(Brain);
}

Dog::Dog(const Dog& other) : A_Animal(other)
{
    dog_brain = new Brain(*(other.dog_brain));
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        delete dog_brain;
        dog_brain = new Brain(*(other.dog_brain));
        A_Animal::operator=(other);
        std::cout << "Dog assignment operator called" << std::endl;
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Dog barks" << std::endl;
}

