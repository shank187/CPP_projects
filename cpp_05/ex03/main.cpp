#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <exception>
#include <iostream>



int main(void)
{
    Intern intern;
    Bureaucrat aymane(1, "aymane");

    std::cout << "--- test 1: INVALID FORM ---" << std::endl;
    AForm *test = intern.makeForm("fake form", "nothing");
    std::srand(std::time(0));

    if (test)
    {
        aymane.signForm(*test);
        delete test;
    }
    else
    {
        std::cout << "test 1 passed: intern correctly returned NULL for fake form."<< std::endl;
    }
    std::cout << "\n--- test 2: VALID FORM ---" << std::endl;
    
    AForm *valid_test = intern.makeForm("presidential pardon", "president");
    if (valid_test)
    {
        std::cout << "test 2 passed: Form created successfully."<< std::endl;
        aymane.signForm(*valid_test);
        aymane.executeForm(*valid_test);
        delete valid_test;
    }
    return (0);
}

