#include "ScalarConverter.hpp"

bool is_literal_char(const std::string & literal)
{
    return (literal.length() == 1 && !std::isdigit(literal[0]));
}

bool is_pseudo_literal(const std::string & literal) {
    if (literal == "nan" || literal == "nanf" || literal == "inf" || literal == "inff" || 
        literal == "+inf" || literal == "+inff" || literal == "-inf" || literal == "-inff")
        return true;
    return false;
}

bool is_literal_int(const std::string & literal) {
    if (literal.empty()) return false;
    size_t start = 0;
    if (literal[0] == '-' || literal[0] == '+') start = 1;
    if (start == literal.length()) return false;
    for (size_t i = start; i < literal.length(); i++) {
        if (!std::isdigit(literal[i])) return false;
    }
    return true;
}

bool is_literal_double(const std::string &literal) {
    if (literal.empty()) return false;
    size_t start = 0;
    if (literal[0] == '-' || literal[0] == '+') start = 1;
    
    bool dot_reached = false;
    bool has_digit = false;

    for(size_t i = start; i < literal.length(); i++) {
        if (std::isdigit(literal[i]))
            has_digit = true;
        else if (literal[i] == '.' && !dot_reached)
            dot_reached = true;
        else
            return false;
    }
    return dot_reached && has_digit;
}

bool is_literal_float(const std::string &literal) {
    if (literal.length() < 2 || literal[literal.length() - 1] != 'f')
        return false;

    return is_literal_double(literal.substr(0, literal.length() - 1));
}

int check_type(const std::string & literal)
{
    if (is_literal_char(literal) )
        return character;
    else if(is_pseudo_literal(literal))
        return pseudo_literal;
    else if(is_literal_int(literal))
        return int_num;
    else if (is_literal_float(literal))
        return float_num;
    else if (is_literal_double(literal))
        return double_num;
    return unknown;
}