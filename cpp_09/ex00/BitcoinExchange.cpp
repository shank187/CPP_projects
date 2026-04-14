#include "BitcoinExchange.hpp"
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

