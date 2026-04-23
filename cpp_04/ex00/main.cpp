#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
    std::cout << "--- 1. POLYMORPHISM & VIRTUAL (Subject Test) ---" << std::endl;
    {
        // Test base pointers with derived objects
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();

        std::cout << "\n--- Checking Types ---" << std::endl;
        std::cout << "j is type: " << j->getType() << " " << std::endl;
        std::cout << "i is type: " << i->getType() << " " << std::endl;
        std::cout << "meta is type: " << meta->getType() << " " << std::endl;

        std::cout << "\n--- Checking Sounds (Dynamic Binding) ---" << std::endl;
        meta->makeSound(); // Animal sound
        j->makeSound();    // Should be Dog sound
        i->makeSound();    // Should be Cat sound

        std::cout << "\n--- Deleting (Virtual Destructors) ---" << std::endl;
        delete meta; // Should call Animal dtor
        delete j;    // Should call Dog dtor THEN Animal dtor
        delete i;    // Should call Cat dtor THEN Animal dtor
    }

    std::cout << "\n--- 2. STATIC BINDING (Wrong* Test) ---" << std::endl;
    {
        // Test non-virtual functions
        const WrongAnimal* wrongMeta = new WrongAnimal();
        const WrongAnimal* wrongI = new WrongCat();

        std::cout << "\n--- Checking Types ---" << std::endl;
        std::cout << "wrongI is type: " << wrongI->getType() << " " << std::endl;
        
        std::cout << "\n--- Checking Sounds (Static Binding) ---" << std::endl;
        wrongMeta->makeSound();
        wrongI->makeSound(); // Should be WrongAnimal sound

        std::cout << "\n--- Deleting (Non-Virtual Destructors) ---" << std::endl;
        delete wrongMeta;
        delete wrongI; // Will *only* call WrongAnimal dtor (potential leak)
    }

    std::cout << "\n--- 3. OCF & INHERITANCE TEST ---" << std::endl;
    {
        std::cout << "\n--- Testing Dog Copy ---" << std::endl;
        Dog dog1;           // Default Ctor
        Dog dog2(dog1);     // Copy Ctor
        Dog dog3;
        dog3 = dog1;        // Copy Assignment
        std::cout << "--- Dog sounds from copies ---" << std::endl;
        dog1.makeSound();
        dog2.makeSound();
        dog3.makeSound();
        std::cout << "--- Dog destructors ---" << std::endl;
    } // dog1, dog2, dog3 go out of scope

    {
        std::cout << "\n--- Testing Cat Copy ---" << std::endl;
        Cat cat1;           // Default Ctor
        Cat cat2(cat1);     // Copy Ctor
        Cat cat3;
        cat3 = cat1;        // Copy Assignment
        std::cout << "--- Cat sounds from copies ---" << std::endl;
        cat1.makeSound();
        cat2.makeSound();
        cat3.makeSound();
        std::cout << "--- Cat destructors ---" << std::endl;
    } // cat1, cat2, cat3 go out of scope

    std::cout << "\n--- 4. STACK-BASED TEST (No 'new') ---" << std::endl;
    Dog stackDog;
    Cat stackCat;
    
    std::cout << stackDog.getType() << " says: ";
    stackDog.makeSound();
    std::cout << stackCat.getType() << " says: ";
    stackCat.makeSound();
    
    std::cout << "--- Stack objects going out of scope ---" << std::endl;
    return 0;
}