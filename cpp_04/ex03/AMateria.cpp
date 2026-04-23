#include "AMateria.hpp"

AMateria::AMateria(std::string const & type): type(type)
{
}

AMateria::~AMateria(){}

AMateria::AMateria():type("amateria"){}

AMateria& AMateria::operator=(const AMateria& other)
{
    if(this != &other)
        this->type = other.type;
    return *this;
}

AMateria::AMateria(const AMateria& other): type(other.type)
{}

void AMateria::use(ICharacter& target)
{
    (void)target;
}

std::string const & AMateria::getType() const
{
    return this->type;
}