#include "ScalarConverter.hpp"
#include <cctype>
#include <climits>
#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

void print_pseudos(const std::string & literal)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if(literal == "nan" || literal == "nanf")
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if(literal == "-inf" || literal == "-inff")
    {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
    else{
        std::cout << "float: inff" << std::endl;
        std::cout << "double: inf" << std::endl;
    }
}


void printChar(double value)
{
    std::cout << "char: ";
    if(value < 0 || value > 127 || value != value)
    {
        std::cout << "impossible" << std::endl;
    }
    else {
        char c = static_cast<char>(value);
        if(std::isprint(c))
            std::cout << "'" << c << "'" << std::endl;
        else
            std::cout << "Non displayable" << std::endl;
    }
}

void printInt(double value)
{
    std::cout << "int: ";
    if (value < INT_MIN || value > INT_MAX || value != value)
        std::cout << "impossible" << std::endl;
    else{
        std::cout << static_cast<int>(value) << std::endl;
    }
}

void printFloat(double value) {
    std::cout << "float: ";
    if (value == std::floor(value) && !std::isinf(value) && (value == value)) { 
        std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
    } else {
        std::cout << static_cast<float>(value) << "f" << std::endl;
    }
}

void printDouble(double value) {
    std::cout << "double: ";
    if (value == std::floor(value) && !std::isinf(value) && (value == value)) {
        std::cout << std::fixed << std::setprecision(1) << value << std::endl;
    } else {
        std::cout << value << std::endl;
    }
}

void ScalarConverter::convert(const std::string &literal) {
    int type = check_type(literal);
    double value = 0;

    if (type == character) {
        value = static_cast<double>(literal[0]);
    } else if (type == pseudo_literal) {
        print_pseudos(literal);
        return;
    } else if (type != unknown) {
        value = std::strtod(literal.c_str(), NULL);
    } else {
        std::cout << "Error: Invalid literal" << std::endl;
        return;
    }

    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}