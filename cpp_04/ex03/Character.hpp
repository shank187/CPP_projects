#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <pthread.h>
#include <string>

class Character: public ICharacter
{
    private:
        AMateria* inventory[4];
        std::string name;
    public:
        Character();
        Character& operator=(const Character& other);
        Character(const Character& other);
        Character(const std::string& name);
        virtual ~Character();
        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);


};

#endif