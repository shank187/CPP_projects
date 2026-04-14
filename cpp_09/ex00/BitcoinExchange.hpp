#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <exception>
#include <fstream>
#include <map>
#include <string>


class BitcoinExchange {
    private:
        std::map<std::string, float> Price_History;
    public:
        class DataBaseException: public std::exception{
            public:
                virtual const char * what() const throw();
        };
        class InputFileException: public std::exception{
            public:
                virtual const char * what() const throw();
        };
        BitcoinExchange();
        BitcoinExchange(const std::string & DataBase);
        BitcoinExchange(const BitcoinExchange & other);
        ~BitcoinExchange();
        BitcoinExchange & operator=(const BitcoinExchange & other);
        void loadDatabase(const std::string & path);
        void exchangeBtc(const std::string & path, bool is_input_file);
        void validatePath(const std::string &path, std::ifstream & to_save, bool is_input_file) const;
        void validateLines(const std::ifstream & file, bool is_input_file);
        void parseDate(const std::string & field) const;
        void parsePrice(const std::string & field) const;

        //helpers
        static bool endwith(const std::string &str, const std::string &suffix);
};



#endif