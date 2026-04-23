#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <ostream>
#include <string>


const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low !";
}

Form::Form() : name("default"), isSigned(false), signGrade(75), execGrade(75)
{
}

Form::Form(const std::string& name, const int& signGrade, const int& execGrade):
name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw Form::GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw Form::GradeTooLowException();
}

Form::~Form()
{
}

Form::Form(const Form& other)
:   name(other.getName()),
    isSigned(other.getIsSigned()),
    signGrade(other.getSignedGrade()),
    execGrade(other.getExecGrade())
{
}

Form& Form::operator=(const Form& other)
{
    if(this!= &other)
        this->isSigned = other.getIsSigned();
    return (*this);
}

const std::string& Form::getName() const
{
    return name;
}

const bool& Form::getIsSigned() const
{
    return isSigned;
}

const int& Form::getSignedGrade() const
{
    return signGrade;
}

const int& Form::getExecGrade() const
{
    return execGrade;
}

void Form::beSigned(const Bureaucrat& b)
{
    if (b.get_grade() <= signGrade)
        isSigned = true;
    else
        throw Form::GradeTooLowException();
}

std::ostream& operator<<(std::ostream &os, const Form& f)
{
    os << f.getName() 
    << ", sign grade "<< f.getSignedGrade()
    << ", exec Grade" << f.getExecGrade()
    << (f.getIsSigned() ? ", is signed." : ", is not signed.")
    << std::endl;

    return os;
}