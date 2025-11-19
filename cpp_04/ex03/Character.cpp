#include "Character.hpp"
#include "AMateria.hpp"
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <string>

Character::Character():name("default")
{
    inventory[0] = NULL;
    inventory[1] = NULL;
    inventory[2] = NULL;
    inventory[3] = NULL;
}

Character::Character(const std::string& name): name(name)
{
    inventory[0] = NULL;
    inventory[1] = NULL;
    inventory[2] = NULL;
    inventory[3] = NULL;
}

Character::Character(const Character& other)
: name(other.name)
{
    for (int i = 0; i < 4; ++i)
    {
        if (other.inventory[i])
            this->inventory[i] = other.inventory[i]->clone();
        else
            this->inventory[i] = NULL;
    }
}

Character& Character::operator=(const Character& other)
{
    if (this == &other)
        return *this;
    name = other.name;
    for (int i = 0; i < 4; ++i)
    {
        if (inventory[i])
        {
            delete inventory[i];
            inventory[i] = NULL;
        }
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();
    }
    return *this;
}

std::string const & Character::getName() const
{
    return name;
}

void Character::equip(AMateria* m)
{
    if(!m)
        return ;
    for(int i = 0; i < 4; i++)
    {
        if(!inventory[i])
        {
            inventory[i] = m;
            return;
        }
    }
    std::cout << "The inventory is full, pls unequip a materia first !" << std::endl;
}

void Character::unequip(int idx)
{
    if(idx < 0 || idx > 3)
    {
        std::cout << idx <<" is out of range !!" << std::endl;
        return;
    }
    if(!inventory[idx])
        std::cout << "the " << idx << "'th slot is already empty" << std::endl;
    else
        inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
        if(idx < 0 || idx > 3)
    {
        std::cout << idx <<" is out of range !!" << std::endl;
        return;
    }
    if(!inventory[idx])
        std::cout << "you can't use an empty slot" << std::endl;
    else
        inventory[idx]->use(target);
}