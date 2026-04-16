#include "RPN.hpp"
#include <exception>
#include <iostream>

int main(int ac, char ** av)
{
    if(ac != 2)
        return(std::cerr << "Error: invalid argumenet" << std:: endl, 1);
    RPN rpn;
    try {
        std::cout << rpn.calculate(av[1]) << std::endl;
    } catch (const std::exception & e) {
        std::cout << e.what() << std::endl;
    }
}