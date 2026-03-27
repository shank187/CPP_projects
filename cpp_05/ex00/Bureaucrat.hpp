#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <ostream>
#include <string>
#include <exception>

class Bureaucrat
{
	private:
		/* data */
		const std::string name;
		int grade;
	public:
		class GradeTooHighException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
		Bureaucrat(int grade, const std::string& name);
		Bureaucrat();
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();
		const std::string& get_name() const;
		int get_grade() const;
		void increment_grade();
		void decrement_grade();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif