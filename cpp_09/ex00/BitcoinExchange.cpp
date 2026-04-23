#include "BitcoinExchange.hpp"
#include <cstddef>
#include <exception>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>
#include <algorithm>

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
    return "An error occurred During Opening/reading the DataBase.";
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
{   
        std::ifstream db;
        this->validatePath(path, db, false);
        this->validateDB(db);
}

void BitcoinExchange::validatePath(const std::string & path, std::ifstream & to_save, bool is_input_file) const
{
    if(!is_input_file && !BitcoinExchange::endwith(path, ".csv"))
        throw std::runtime_error("Error: This program must use a database in csv format.");
    
    to_save.open(path.c_str());
    if (!to_save.is_open() && !is_input_file)
        throw DataBaseException();
    if (!to_save.is_open() && is_input_file)
        throw InputFileException();
    if (to_save.is_open())
    {
        char c;
        to_save.read(&c, 1);
        
        if (to_save.fail())
        {
            to_save.close();
            throw std::runtime_error("Error: " + path + " is a directory or unreadable.");
        }

        to_save.clear(); 
        to_save.seekg(0, std::ios::beg);
    }
}

void BitcoinExchange::parseDate(const std::string & field) const
{
    int year, month, day;
    char dash1,dash2;
    std::stringstream ss(field);

    if (ss >> year >> dash1 >> month >> dash2 >> day)
    {
        char remaining;
        if(dash1 != '-' || dash2!= '-' || ss >> remaining || year <= 0)
            return(throw std::runtime_error("Error: bad input => " + field));
        if (month <= 0 || month > 12)
            return(throw std::runtime_error("Error: bad input => " + field));
        bool isLeap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        if (month == 2 && ((day == 29 && !isLeap) || day > 29))
            throw std::runtime_error("Error: invalid day => " + field);
        if(day == 31 && (month == 4 || month == 6 || month == 9 || 11 == month))
            return(throw std::runtime_error("Error: invalid day => " + field));
        if(day <= 0 || day> 31)
            return(throw std::runtime_error("Error: bad input => " + field));
    }
    else
        return(throw std::runtime_error("Error: bad input => " + field));
}

float BitcoinExchange::parsePrice(const std::string & field) const
{
    float price;
    char remaining;
    std::stringstream ss(field);

    if(ss >> price)
    {
        if(ss >> remaining)
            return(throw std::runtime_error("Error: invalid price => " + field), 0); 
        if(price < 0 )
            return(throw std::runtime_error("Error: not a positive number. => " + field), 0); 
        return price;
    }
    else
        return(throw std::runtime_error("Error: invalid price => " + field), 0); 
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
            float rate = parsePrice(price);
            std::string date = line.substr(0, pos);
            parseDate(date);
            Price_History[date] = rate;
        }
        else {
            throw std::runtime_error("An error occurred During opening/reading the DataBase.");
        }
    }
}

float BitcoinExchange::get_price_date(const std::string & date)
{
    float rate = 0;
    std::map<std::string, float>::iterator it = Price_History.upper_bound(date);
    if(it == Price_History.begin())
    {
        throw std::runtime_error("Error: date too early");
    }
    else 
    {
        --it;
        rate = it->second;
    }
    return rate;
}


void BitcoinExchange::parseExchangeLine(const std::string & line)
{
    try
    {
        std::size_t seppos = line.find("|");
        std::string date =  line.substr(0, seppos);
        date.erase(std::remove_if(date.begin(), date.end(), ::isspace), date.end());
        parseDate(date);
        std::string value_str = line.substr(seppos + 1);
        value_str.erase(std::remove_if(value_str.begin(), value_str.end(), ::isspace), value_str.end());
        float value = parsePrice(value_str);
        if(value > 1000)
            throw std::runtime_error("Error: too large number.");
        float rate = get_price_date(date);
        std::cout << date << " => " << value << " = " << rate * value << std::endl;
    }
    catch (const std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
}

void BitcoinExchange::traverseInput(std::ifstream & ifile)
{
    std::string line;
    std::getline(ifile, line);

    if(line != "date | value")
        parseExchangeLine(line);

    while(std::getline(ifile, line))
    {
        parseExchangeLine(line);
    }
}

void BitcoinExchange::exchangeBtc(const std::string & inputPath)
{
    try
    {
        std::ifstream ifile;
        this->validatePath(inputPath, ifile, true);
        this->traverseInput(ifile);
    }
    catch (const std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
}

