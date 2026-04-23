#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include <string>

class WrongAnimal
{
protected:
    std::string type;
public:
    WrongAnimal();
    WrongAnimal(const std::string& type);
    ~WrongAnimal();
    WrongAnimal(const WrongAnimal& other);
    WrongAnimal& operator=(const WrongAnimal& other);

    void makeSound() const;
    std::string getType() const;
};
#endif // WRONGANIMAL_HPP