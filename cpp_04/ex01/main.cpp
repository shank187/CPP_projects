#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    const int n = 20;

    Animal *animal[n];

    for(int i = 0;i < n/2; i++)
        animal[i] = new Cat();
    for(int i = n /2 ; i < n; i++)
        animal[i] = new Dog();

    for(int i = 0; i < n; i++)
        delete animal[i];
//------------------------------------------------------------------
    std::cout << "\n--- TEST0: EX01 - Dog DEEP COPY (Brain) ---" << std::endl;
    Dog originalDog;
    {
        std::cout << "\n--- Creating a copy... ---" << std::endl;
        Dog copyDog = originalDog; // Calls copy constructor
        std::cout << "--- Copy is going out of scope... ---" << std::endl;
        // copyDog is destroyed here.
    }
    std::cout << "--- Original dog is still here ---" << std::endl;
    originalDog.makeSound(); // This will crash if the copy was shallow
    std::cout << "--- Deep copy test PASSED ---" << std::endl;
//------------------------------------------------------------------
    std::cout << "\n--- TEST1: EX01 - Cat DEEP COPY (Brain) ---" << std::endl;
    Cat originalCat;
    {
        std::cout << "\n--- Creating a copy... ---" << std::endl;
        Cat copyCat = originalCat; // Calls copy constructor
        std::cout << "--- Copy is going out of scope... ---" << std::endl;
        // copyCat is destroyed here.
    }
    std::cout << "--- Original cat is still here ---" << std::endl;
    originalCat.makeSound(); // This will crash if the copy was shallow
    std::cout << "--- Deep copy test PASSED ---" << std::endl;
    std::cout << "\n--- Testing Assignment Operator Deep Copy for Dog ---" << std::endl;
    Dog dogA;
    {
        Dog dogB;
        dogA = dogB; // Calls assignment operator (potential leak here!)
    } // dogB is destroyed
    dogA.makeSound(); // Should still work
    std::cout << "--- Assignment operator test PASSED ---" << std::endl;
    std::cout << "\n--- Testing Assignment Operator Deep Copy for Dog ---" << std::endl;
    Cat catA;
    {
        Cat catB;
        catA = catB; // Calls assignment operator (potential leak here!)
    } // dogB is destroyed
    catA.makeSound(); // Should still work
    std::cout << "--- Assignment operator test PASSED ---" << std::endl;
}