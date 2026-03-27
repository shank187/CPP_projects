#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

typedef enum TYPE_LIST
{
	character,
	pseudo_literal,
	float_num,
	double_num,
    int_num,
    unknown
}	TypeList;


class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter & other);
        ScalarConverter &operator=(const ScalarConverter & other);
        ~ScalarConverter();
    public:
        static void convert(const std::string& literal);
};

int check_type(const std::string & literal);
#endif