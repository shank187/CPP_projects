#include "RPN.hpp"
#include <cstddef>
#include <stdexcept>
#include <climits>

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
    for(std::size_t i = 0; i < s.length(); i ++)
    {
        if(s[i] == c)
            return true;
    }
    return false;
}
int RPN::calculateLastTwo(char op)
{
    if(stack_rpn.size() < 2) throw ToomanyOperators();
    
    int first = stack_rpn.top(); stack_rpn.pop();
    int second = stack_rpn.top(); stack_rpn.pop();

    if (op == '+')
    {
        if (second > 0 && first > INT_MAX - second) throw std::runtime_error("Error: Overflow.");
        if (second < 0 && first < INT_MIN - second) throw std::runtime_error("Error: Underflow.");
        return second + first;
    }
    else if (op == '-')
    {
        if (first < 0 && second > INT_MAX + first) throw std::runtime_error("Error: Overflow.");
        if (first > 0 && second < INT_MIN + first) throw std::runtime_error("Error: Underflow.");
        return second - first;
    }
    else if (op == '*')
    {
        double check = static_cast<double>(second) * static_cast<double>(first);
        if (check > INT_MAX || check < INT_MIN) throw std::runtime_error("Error: Overflow|Underflow.");
        return second * first;
    }
    else if (op == '/')
    {
        if (first == 0) throw InvalidDivision();
        return second / first;
    }
    return 0;
}

int RPN::calculate(const std::string & exp)
{

    for(std::size_t i = 0; i < exp.length(); i++)
    {
        if(exp[i] == ' ' || exp[i] =='\t')
            continue;
        if(!is_in(exp[i], "0123456789+-*/"))
            throw InvalidCharacter();
        else if (is_in(exp[i], "0123456789"))
            stack_rpn.push(exp[i] - '0');
        else if(is_in(exp[i], "+-*/"))
            stack_rpn.push(calculateLastTwo(exp[i]));
    if(i + 1 < exp.length() && exp[i+1] != ' ' && exp[i+1] != '\t')
        throw std::runtime_error("Error: Numbers and operators must be separated by spaces.");
    }
    if(stack_rpn.size() > 1)
        throw TooManyOperands();
    else if (!stack_rpn.size())
        throw std::runtime_error("Error: empty string.");
    return stack_rpn.top();

}