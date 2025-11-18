#include "Cure.hpp"
#include "AMateria.hpp"

Cure::Cure():AMateria("ice")
{
}

Cure::~Cure()
{
}

Cure::Cure(const Cure& other):AMateria(other)
{
}

Cure& Cure::operator=(const Cure& other)
{
    if(this != &other)
        AMateria::operator=(other);
    return *this;
}

AMateria* Cure::clone() const
{
    return new Cure(*this);
}
