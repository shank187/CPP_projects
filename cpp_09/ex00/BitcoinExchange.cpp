#include "BitcoinExchange.hpp"
#include <cstddef>
#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const std::string & DataBase)
{
    this->loadDatabase(DataBase);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & other) : Price_History(other.Price_History){}

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange & other){
    if(this != &other)
        this->Price_History = other.Price_History;
    return *this;
}

BitcoinExchange::~BitcoinExchange(){}

const char * BitcoinExchange::DataBaseException::what() const throw()
{
    return "An error occurred During opening/reading the DataBase.";
}

const char * BitcoinExchange::InputFileException::what() const throw()
{
    return "An Error occurred during Opening/Reading the Input File.";
}

bool BitcoinExchange::endwith(const std::string &str, const std::string &suffix)
{
    if(str.length() >= suffix.length())
    {
        return (0 == str.compare(str.length() - suffix.length(), suffix.length(), suffix));
    }
    return false;
}

void BitcoinExchange::loadDatabase(const std::string & path)
{   try
    {
        std::ifstream db;
        this->validatePath(path, db, false);
        this->validateDB(db);
    }
    catch (const std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
}

void BitcoinExchange::validatePath(const std::string & path, std::ifstream & to_save, bool is_input_file) const
{
    if(!is_input_file && !BitcoinExchange::endwith(path, ".csv"))
        throw std::runtime_error("This program must use a database in csv format.");
    to_save.open(path);
    if (to_save.is_open())
        throw DataBaseException();
}

void BitcoinExchange::parseDate(const std::string & field) const
{
    int year, month, day;
    char dash1,dash2;

    std::stringstream ss(field);
    if (ss >> year >> dash1 >> month >> dash2 >> day)
    {
        char remaining;
        if(dash1 != '-' || dash2!= '-' || ss >> remaining)
            return(throw std::runtime_error("Error: invalid date => " + field));
        if (month <= 0 || month > 12)
            return(throw std::runtime_error("Error: invalid date => " + field));
        bool isLeap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        if (month == 2 && day == 29 && !isLeap)
            throw std::runtime_error("Error: invalid date => " + field);
        if(day == 31 && (month == 4 || month == 6 || month == 9 || 11 == month))
            return(throw std::runtime_error("Error: invalid date => " + field));
        if(day <= 0 || day> 31)
            return(throw std::runtime_error("Error: invalid date => " + field));
    }
}

float BitcoinExchange::parsePrice(const std::string & field) const
{

    return 0;
}

void BitcoinExchange::validateDB(std::ifstream & file)
{
    std::string line;
    std::getline(file, line);
    if(line != "date,exchange_rate")
        throw std::runtime_error("Invalid Header.");
    while (std::getline(file, line)) {
        std::size_t pos = line.find(",");
        if(pos != std::string::npos)
        {
            std::string price = line.substr(pos + 1);
            parsePrice(price);
            std::string date = line.substr(0, pos);
            parseDate(date);
        }
    }
}