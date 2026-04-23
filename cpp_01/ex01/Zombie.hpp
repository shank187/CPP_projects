#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
    private:
        std::string name;
    public:
        void announce( void );
        void setName(std::string z_name);
        Zombie();
        Zombie(std::string z_name);
        ~Zombie();
};

#endif