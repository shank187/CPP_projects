#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <string>
#include "Bureaucrat.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm():
AForm("Robotomy Request", 72, 45), _target("default_robot")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string & target):
AForm("Robotomy Request", 72, 45), _target(target)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
:AForm(other), _target(other._target)
{

}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if(this != &other)
    {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (!this->getIsSigned())
        throw AForm::FormNotSignedException();

    if (executor.get_grade() > this->getExecGrade())
        throw AForm::GradeTooLowException();
    int n = rand() % 2;

    if (n)
    {
        std::cout << "BZZZZT! " << _target << " has been robotomized successfully" << std::endl;
    }
    else
    {
        std::cout << "BZZZZT! " << _target << " has failed to be robotomized" << std::endl;
    }
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}