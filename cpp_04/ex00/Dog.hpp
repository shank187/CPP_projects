#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
public:
    Dog();
    Dog(const std::string& type);
    ~Dog();
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);

    void makeSound() const;
};

#endif // DOG_HPP