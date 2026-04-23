#include "BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error: invalid argument." << std::endl;
        return 1;
    }
    try
    {
        BitcoinExchange btc("cpp_09/data.csv");
        btc.exchangeBtc(av[1]);
    }
    catch (const std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
}