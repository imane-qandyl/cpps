#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other) {
        _db = other._db;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::isValidDate(std::string &date) const {
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    if (month < 1 || month > 12 || day < 1)
        return false;
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31 };
    // Leap year adjustment for February
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        daysInMonth[1] = 29;

    // Check if day exceeds max for the given month
    if (day > daysInMonth[month - 1])
        return false;
    return true;
}

bool BitcoinExchange::isValidValue(std::string &str, double &value) const {
    char *end;
    value = std::strtod(str.c_str(), &end);
    if (*end != '\0')
        return false;
    if (value < 0 || value > INT_MAX)
        throw std::runtime_error("Error: not a positive number.");
    if (value > 1000)
        throw std::runtime_error("Error: too large a number.");
    return true;
}

void BitcoinExchange::trim(std::string &str) const {
	str.erase(0, str.find_first_not_of(' '));
	str.erase(str.find_last_not_of(' ') + 1);
}

void BitcoinExchange::loadDatabase(const std::string &filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty())
            continue;
        std::stringstream ss(line);
        std::string date, rateStr;
        if (!std::getline(ss, date, ',') || !std::getline(ss, rateStr))
            continue;
        trim(date);
        double rate = std::atof(rateStr.c_str());
        _db[date] = rate;
    }
    file.close();
}
void BitcoinExchange::processInput(const std::string &filename) const {
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");

    std::string line;

    while (std::getline(file, line)) {
        if (line.empty())
            continue;
        std::stringstream ss(line);
        std::string date, valueStr;
        if (!std::getline(ss, date, '|') || !std::getline(ss, valueStr)) {
            // If that fails, reset and try ','
            ss.clear();
            ss.str(line);
            if (!std::getline(ss, date, ',') || !std::getline(ss, valueStr)) {
                std::cerr << "Error: bad input => " << line << std::endl;
                continue;
            }
        }
        trim(date);
        trim(valueStr);
        if (!isValidDate(date)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
    double value;//hold the amount of Bitcoin
        try {
            if (!isValidValue(valueStr, value)) {
                std::cerr << "Error: bad input => " << line << std::endl;
                continue;
            }
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
            continue;
        }

        // Find exchange rate (closest earlier date if exact not found)
        std::map<std::string, double>::const_iterator it = _db.lower_bound(date);
        if (it == _db.end() || it->first != date) {
            if (it == _db.begin()) {
                std::cerr << "Error: no earlier date in database." << std::endl;
                continue;
            }
            --it;
        }

        double rate = it->second;
        std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
    }
    file.close();

}
/*If divisible by 400 → leap year.

Else if divisible by 4 but not by 100 → leap year.

Otherwise → not a leap year.


If it is at the beginning → there’s no earlier date → print error & skip.

Otherwise → --it moves to the previous date in _db (the closest earlier date).
Exact matches → use that rate.

No match → use the closest earlier date in the database.


lower_bound(date) it picks the first >= date
*/