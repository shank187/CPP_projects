#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN
{
    private:
        std::stack<int> stack_rpn;
        int calculateLastTwo(char op);
    public:
        RPN(const RPN & other);
        RPN &operator=(const RPN & other);
        RPN();
        ~RPN();

        class TooManyOperands: public std::exception
        {
            public:
                virtual const char * what() const throw();
        };
        class ToomanyOperators: public std::exception
        {
            public:
                virtual const char * what() const throw();
        };
        class InvalidDivision: public std::exception
        {
            public:
                virtual const char * what() const throw();
        };
        class InvalidCharacter: public std::exception
        {
            public:
                virtual const char * what() const throw();
        };

        int calculate(const std::string & exp);

        static bool is_in(char c, const std::string & s);
};

#endif