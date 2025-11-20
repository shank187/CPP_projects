#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int main()
{
    std::cout << "--- 1. SUBJECT MAIN ---" << std::endl;
    
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;

    std::cout << "\n--- 2. DEEP COPY CHECK ---" << std::endl;
    
    Character* original = new Character("Original");
    original->equip(new Ice());
    
    // Create a deep copy
    Character* copy = new Character(*original);
    
    // If copy is shallow, 'copy' now holds a dangling pointer.
    delete original;

    // If shallow, this crashes.
    ICharacter* dummy = new Character("dummy");
    copy->use(0, *dummy);
    
    delete copy;
    delete dummy;

    std::cout << "\n--- 3. UNEQUIP & FLOOR CHECK ---" << std::endl;
    
    Character* hero = new Character("Hero");
    AMateria* item = new Cure();
    
    hero->equip(item);
    
    // Unequip it (Should NOT delete it, but save to floor list)
    hero->unequip(0);

    // When hero is deleted, it must clean up the floor
    // Valgrind will show 0 leaks if your destructor works.
    delete hero;

    return 0;
}