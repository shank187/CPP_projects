#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>


class BitcoinExchange {
    private:
        std::map<std::string, float> Price_History;
    public:
    
        BitcoinExchange();
        BitcoinExchange(const std::string & DataBase);
        BitcoinExchange(const BitcoinExchange & other);
        ~BitcoinExchange();
        BitcoinExchange & operator=(const BitcoinExchange & other);
        void loadDatabase(const std::string & path);
        void exchangeBtc(const std::string & path, bool is_input_file);
        void validatePath(const std::string &path) const;
        void validateLine(const std::string & line, bool is_input_file) const;
        void parseDate(const std::string & field) const;
        void parsePrice(const std::string & field) const;
};



#endif