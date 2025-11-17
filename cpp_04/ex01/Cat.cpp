#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat")
{
    cat_brain = new(Brain);
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::~Cat()
{
    delete cat_brain;
    std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const std::string& type) : Animal(type)
{
    cat_brain = new(Brain);
    std::cout << "Cat parameterized constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
    this->cat_brain = new Brain(*(other.cat_brain));
    std::cout << "Cat copy constructor called" << std::endl;
}
Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
    {
        delete this->cat_brain; 
        this->cat_brain = new Brain(*(other.cat_brain));
        Animal::operator=(other);
        std::cout << "Cat assignment operator called" << std::endl;
    }
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Cat meows" << std::endl;
}

