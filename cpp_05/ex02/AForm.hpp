#ifndef AFORM_HPP
#define  AFORM_HPP

#include <ostream>
#include <string>

class Bureaucrat;

class AForm 
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
        class FormNotSignedException : public std::exception{
            public:
                virtual const char* what() const throw();
        };
        AForm(const std::string& name, const int& signGrade, const int& execGrade);
        AForm();
        virtual ~AForm();

        AForm(const AForm&other);
        AForm& operator=(const AForm&other);

        const std::string& getName() const;
        const bool& getIsSigned() const;
        const int& getSignedGrade() const; 
        const int& getExecGrade() const;

        virtual void execute(Bureaucrat const & executor) const = 0;
        void beSigned(const Bureaucrat& b);

};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif