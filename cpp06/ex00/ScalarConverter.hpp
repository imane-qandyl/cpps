#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <cctype>

class ScalarConverter {
    private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(ScalarConverter const& copy);
        ScalarConverter& operator=(ScalarConverter const& copy);
    public:
        static void convert(const std::string& input);
};

/*char literals like 'a'

int literals like 42

float literals like 42.0f, nanf, +inff, -inff

double literals like 42.0, nan, +inf, -inf
Class is non-instantiable (private constructor).

*/