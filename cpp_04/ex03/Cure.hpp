#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
    public:
        AMateria *clone() const;
        Cure();
        ~Cure();
        Cure(const Cure& other);
        Cure& operator=(const Cure& other);
        void use(ICharacter& target);
};

#endif