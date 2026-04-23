#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm()
:AForm("Shrubbery Creation", 145, 137)  ,_target("default_shrub")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string & target)
:AForm("Shrubbery Creation", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
:AForm(other), _target(other._target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->_target = other._target;    
    }
    return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (!this->getIsSigned())
        throw AForm::FormNotSignedException();

    if (executor.get_grade() > this->getExecGrade())
        throw AForm::GradeTooLowException();

    std::ofstream outfile((this->_target + "_shrubbery").c_str());
    if (outfile.is_open())
    {
        outfile << "      /\\      " << std::endl;
        outfile << "     /\\*\\     " << std::endl;
        outfile << "    /\\O\\*\\    " << std::endl;
        outfile << "   /*/\\/\\/\\   " << std::endl;
        outfile << "  /\\O\\/\\*\\/\\  " << std::endl;
        outfile << "      ||      " << std::endl;
        outfile.close();
    }
    else
    {
        std::cerr << "Warning: Could not create shrubbery file for target: " 
                  << _target << std::endl;
    }
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}