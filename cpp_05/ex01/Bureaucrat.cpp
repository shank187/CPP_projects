#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <cstdio>
#include <exception>
#include <iostream>

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}

Bureaucrat::~Bureaucrat()
{
	
}

Bureaucrat::Bureaucrat(): name("default"), grade(75)
{
}

Bureaucrat::Bureaucrat(int grade, const std::string& name)
: name(name), grade(grade)
{
	if(grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	}

Bureaucrat::Bureaucrat(const Bureaucrat&  other)
:name(other.name), grade(other.grade)
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if(this != &other)
		this->grade = other.grade;
	return *this;
}

void Bureaucrat::increment_grade()
{
	if (grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	grade--;
}

void Bureaucrat::decrement_grade()
{
	if (grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	grade++;
}

const std::string& Bureaucrat::get_name() const
{
	return name;
}

int Bureaucrat::get_grade() const
{
	return grade;
}

void Bureaucrat::signForm(Form& f)
{
	try {
		f.beSigned(*this);
		std::cout << name << " signed " << f.getName() << std::endl;
	} catch (const std::exception &e) {
		std::cout << name << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << obj.get_name() << ", bureaucrat grade " << obj.get_grade() << "." << std::endl;
	return os;
}