#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm()
:AForm("Presidential Pardon request", 25, 5), _target("Presidential Pardon")
{

}

PresidentialPardonForm::PresidentialPardonForm(const std::string & target)
:AForm("Presidential Pardon request", 25, 5), _target(target) 
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & other)
:AForm(other), _target(other._target) 
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm & other)
{
    if(this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat & executor) const
{
    if(!this->getIsSigned())
        throw AForm::FormNotSignedException();
    if(executor.get_grade() > this->getExecGrade())
        throw AForm::GradeTooLowException();
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}


PresidentialPardonForm::~PresidentialPardonForm()
{

}