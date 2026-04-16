#include "RPN.hpp"


RPN::~RPN(){}

RPN::RPN(){}

RPN::RPN(const RPN & other):stack_rpn(other.stack_rpn){}

RPN &RPN::operator=(const RPN & other)
{
    if(this != & other)
        this->stack_rpn = other.stack_rpn;
    return (*this);
}

const char * RPN::InvalidCharacter::what() const throw()
{
    return "Error: Invalid input.";
}

const char * RPN::InvalidDivision::what() const throw()
{
    return "Error: Division by 0.";
}

const char * RPN::ToomanyOperators::what() const throw()
{
    return "Error: Too many operators.";
}

const char * RPN::TooManyOperands::what() const throw()
{
    return "Error: Too many operands.";
}

bool RPN::is_in(char c, const std::string & s)
{
    for(int i = 0; i < s.length(); i ++)
    {
        if(s[i] == c)
            return true;
    }
    return false;
}

int RPN::calculateLastTwo(char op)
{
    int first = stack_rpn.top();
    stack_rpn.pop();
    int second  = stack_rpn.top();
    if(op == '-')
        return( second - first);
    else if('+' == op)
        return( second + first);        
    else if('*' == op)
        return( second * first); 
    if( first == 0)
        throw InvalidDivision();
    return(second / first);
}

int RPN::calculate(const std::string & exp)
{
    int current;
    int resultOfTwo;
    int operands_count = 0;

    for(std::size_t i = 0; i < exp.length(); i++)
    {
        if(!is_in(exp[i], "0123456789+-*/"))
            throw InvalidCharacter();
        else if (is_in(exp[i], "0123456789"))
            stack_rpn.push(exp[i] - 48);
        else if(is_in(exp[i], "+-*/"))
            stack_rpn.push(calculateLastTwo(exp[i]));

    }

    return 0;
}