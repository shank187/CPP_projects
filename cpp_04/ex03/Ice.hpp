#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice: public AMateria
{
    public:
        AMateria *clone() const;
        Ice();
        ~Ice();
        Ice(const Ice& other);
        Ice& operator=(const Ice& other);
        void use(ICharacter& target);
};

#endif