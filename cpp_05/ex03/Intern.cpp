#include "Intern.hpp"

Intern::Intern(){}

Intern::~Intern(){}

Intern& Intern::operator=(const Intern & other)
{
    (void) other;
    return (*this);
}

Intern::Intern(const Intern & other)
{
    (void) other;
}


AForm* Intern::makePresidential(const std::string& target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeRobotomy(const std::string & target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::makeShrubbery(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeForm(const std::string& FormName, std::string FormTarget)
{
    static const std::string forms_list[] = {"robotomy request", 
                                "shrubbery creation",
                                "presidential pardon"};
    typedef AForm* (Intern::*funcptr)(const std::string &other);
    funcptr fn_list[] = {&Intern::makeRobotomy,
                        &Intern::makeShrubbery,
                        &Intern::makePresidential};
    for (int i = 0; i < 3; i++)
    {
        if(FormName == forms_list[i])
        {
            std::cout << "intern creates " << FormName <<  std::endl;
            return (this->*fn_list[i]) (FormTarget);
        }
    }
    std::cout << "the type of \"" << FormName << "\" doesn't exists" << std::endl;
    return NULL;
}
