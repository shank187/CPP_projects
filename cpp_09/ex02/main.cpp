#include <iostream>
#include "PmergeMe.hpp"


int main(int ac, char **av)
{
    if(ac == 1)
    {
        std::cerr << "Error: No argument" << std::endl;
        return 1;
    }
    try
    {
        PmergeMe merge;
        merge.loadAndParse(ac, av);
        merge.solve();
    }    
    catch (const std::exception & e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}