#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm: public AForm
{
    private:
        std::string _target;
    public:
        PresidentialPardonForm();
        ~PresidentialPardonForm();
        PresidentialPardonForm(const std::string& target);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        void execute(Bureaucrat const & executor) const;

};

#endif