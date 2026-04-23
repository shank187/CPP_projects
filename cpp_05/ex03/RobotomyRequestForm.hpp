#ifndef  ROBOTOMYREQUESTFORM_HPP
#define  ROBOTOMYREQUESTFORM_HPP


#include "AForm.hpp"
#include <string>
#include <cstdlib>
#include <ctime>

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;
    public:
        RobotomyRequestForm();
        ~RobotomyRequestForm();
        RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        void execute(Bureaucrat const & executor) const;
};


#endif