#include "Brain.hpp"

Brain::Brain()
{
}

Brain::Brain(const Brain& other)
{
    for (int i = 0; i < 100; ++i)
        this->ideas[i] = other.ideas[i];
}

Brain::~Brain()
{
}


Brain& Brain::operator=(const Brain& other)
{
    if (this != &other)
    {
        for (int i = 0; i < 100; ++i)
            this->ideas[i] = other.ideas[i];
    }
    return *this;
}