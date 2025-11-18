#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public A_Animal
{
    private:
        Brain* dog_brain;
    public:
        Dog();
        Dog(const std::string& type);
        ~Dog();
        Dog(const Dog& other);
        Dog& operator=(const Dog& other);
        void makeSound() const;
};

#endif // DOG_HPP