#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <ostream>
#include <string>


const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed yet!";
}

AForm::AForm() : name("default"), isSigned(false), signGrade(75), execGrade(75)
{
}

AForm::AForm(const std::string& name, const int& signGrade, const int& execGrade):
name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw AForm::GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw AForm::GradeTooLowException();
}

AForm::~AForm()
{
}

AForm::AForm(const AForm& other)
:   name(other.getName()),
    isSigned(other.getIsSigned()),
    signGrade(other.getSignedGrade()),
    execGrade(other.getExecGrade())
{
}

AForm& AForm::operator=(const AForm& other)
{
    if(this!= &other)
        this->isSigned = other.getIsSigned();
    return (*this);
}

const std::string& AForm::getName() const
{
    return name;
}

const bool& AForm::getIsSigned() const
{
    return isSigned;
}

const int& AForm::getSignedGrade() const
{
    return signGrade;
}

const int& AForm::getExecGrade() const
{
    return execGrade;
}


void AForm::beSigned(const Bureaucrat& b)
{
    if (b.get_grade() <= signGrade)
        isSigned = true;
    else
        throw AForm::GradeTooLowException();
}

std::ostream& operator<<(std::ostream &os, const AForm& f)
{
    os << f.getName() 
    << ", sign grade "<< f.getSignedGrade()
    << ", exec Grade" << f.getExecGrade()
    << (f.getIsSigned() ? ", is signed." : ", is not signed.")
    << std::endl;

    return os;
}