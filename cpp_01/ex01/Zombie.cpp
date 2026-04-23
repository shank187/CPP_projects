#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie( std::string z_name ) : name(z_name)
{
}

Zombie::Zombie() : name("no name")
{
}


Zombie::~Zombie()
{
    std::cout << name << " is killed :(" << std::endl;
}

void Zombie::announce( void )
{
    std::cout << "Zombie " << name << " is coming!" << std::endl;
}

void Zombie::setName(std::string z_name)
{
    name = z_name;
}
