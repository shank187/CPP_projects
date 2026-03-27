#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>


int main(void)
{
    try
    {
        Bureaucrat b1(18, "aymane");
        std::cout << b1;
        try
        {
            for(int i = 0; i < 100; i++)
            {
                b1.increment_grade();
            }
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        try 
        {
            for (int i = 0; i < 200; i++)
            {
                b1.decrement_grade();
            }
        } catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        Bureaucrat b2(187, "elbour");
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

}
