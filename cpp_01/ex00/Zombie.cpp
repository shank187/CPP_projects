#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie( std::string z_name ) : name(z_name)
{
}

Zombie::~Zombie()
{
    std::cout << name << " is killed :(" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
