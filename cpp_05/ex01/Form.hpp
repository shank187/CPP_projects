#ifndef FORM_HPP
#define  FORM_HPP

#include <ostream>
#include <string>

class Bureaucrat;

class Form 
{
    private:
        const std::string name;
        bool isSigned;
        const int signGrade;
        const int execGrade;
    public:
        class GradeTooHighException : public std::exception{
            public:
            virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception{
            public:
            virtual const char* what() const throw();
        };    
        Form(const std::string& name, const int& signGrade, const int& execGrade);
        Form();
        ~Form();

        Form(const Form&other);
        Form& operator=(const Form&other);

        const std::string& getName() const;
        const bool& getIsSigned() const;
        const int& getSignedGrade() const; 
        const int& getExecGrade() const;

        void beSigned(const Bureaucrat& b);

};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif