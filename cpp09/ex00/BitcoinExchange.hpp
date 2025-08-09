#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <stdexcept>
#include <cmath>
#include <climits>

class BitcoinExchange {
    private:
        std::map<std::string, double> _db; // date -> rate
        bool isValidDate(std::string &date) const;
        bool isValidValue(std::string &str, double &value) const;
        void trim(std::string &str) const;
        
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

        void loadDatabase(const std::string &filename);
        void processInput(const std::string &filename) const;
};
    

