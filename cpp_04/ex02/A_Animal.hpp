#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class A_Animal
{
protected:
    std::string type;
public:
    A_Animal();
    A_Animal(const std::string& type);
    virtual ~A_Animal();
    A_Animal(const A_Animal& other);
    A_Animal& operator=(const A_Animal& other);

    virtual void makeSound() const = 0;
    std::string getType() const;
};
#endif // ANIMAL_HPP