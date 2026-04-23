#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <exception>
#include <iostream>



int main(void)
{
    RobotomyRequestForm Robotomize("Bender");
    ShrubberyCreationForm shrub("Home");
    PresidentialPardonForm pardon("Arthur");
    
    Bureaucrat aymane(1, "SI AYMANE");
    Bureaucrat intern(137, "shi 7ed");

    std::srand(std::time(0));
    try
    {
        aymane.signForm(shrub);
        intern.signForm(Robotomize);
    }
    catch (const std::exception & e)
    {
        std::cout << "critical error: " << e.what() << std::endl;
    }
    try
    {
        aymane.executeForm(shrub);
        aymane.executeForm(Robotomize);
    }
    catch (const std::exception & e)
    {
        std::cout << "critical error: " << e.what() << std::endl;
    }
    try 
    {
        for (int i = 137; i >= 7; i--)
        {
            intern.increment_grade();
        }
        intern.signForm(Robotomize);
        for (int i = 0; i < 4; i++) {
            aymane.executeForm(Robotomize);
        }
        aymane.executeForm(pardon);
    }
    catch (const std::exception & e)
    {
        std::cout << "critical error: " << e.what() << std::endl;
    }
    try
    {
        intern.signForm(pardon);
        aymane.executeForm(pardon);
        for (int i = 7;i <= 100; i++)
            intern.decrement_grade();
        intern.executeForm(pardon);
    }
    catch (const std::exception & e)
    {
        std::cout << "critical error: " << e.what() << std::endl;
        
    }
    return 0;
}

