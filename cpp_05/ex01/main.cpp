#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    std::cout << "--- TEST 1: SUCCESSFUL SIGNING ---" << std::endl;
    try
    {
        // Constructor order: (grade, name)
        Bureaucrat bob(10, "Bob");     
        Form       tax("Tax Form", 20, 50);

        std::cout << bob;
        std::cout << tax;

        bob.signForm(tax); // Success: 10 <= 20
        std::cout << tax;
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 2: GRADE TOO LOW ---" << std::endl;
    try
    {
        Bureaucrat jim(100, "Jim");
        Form       nda("NDA", 50, 50);

        std::cout << jim;
        jim.signForm(nda); // Fails: 100 > 50
    }
    catch (const std::exception &e)
    {
        std::cout << "Critical Error: " << e.what() << std::endl;
    }

    return 0;
}