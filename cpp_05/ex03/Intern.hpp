#ifndef INTERN_HPP
#define INTERN_HPP


#include "AForm.hpp"
#include <string>
#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


class Intern 
{
    private:
        AForm* makePresidential(const std::string& target);
        AForm* makeRobotomy(const std::string& target);
        AForm* makeShrubbery(const std::string& target);
    public:
        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern();
        AForm* makeForm(const std::string& FormName, std::string FormTarget);
};


#endif 