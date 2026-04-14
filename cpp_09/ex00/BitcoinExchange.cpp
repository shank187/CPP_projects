#include "BitcoinExchange.hpp"
#include <exception>
#include <fstream>
#include <iostream>
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
        this->validateLines(db, false);
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

void BitcoinExchange::validateLines(const std::ifstream & file, bool is_input_file)
{

}