#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
    private:
        std::string ideas[100];
    public:
        Brain();
        Brain& operator=(const Brain& other); 
        Brain(const Brain& other); 
        ~Brain();
};

#endif