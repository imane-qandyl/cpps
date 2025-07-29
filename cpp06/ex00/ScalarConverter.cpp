/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 20:03:52 by imqandyl          #+#    #+#             */
/*   Updated: 2025/07/29 14:12:22 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}
ScalarConverter::~ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter &copy){*this = copy;}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy){(void)copy; return (*this);}
void ScalarConverter::convert(const std::string& input)
{
    if (input.empty())
        return;
    if (input.length() == 1 && !std::isdigit(input[0])) { //If the input is a single non-digit character, it treats it as a char type and converts it to int, double, and float.
        char ch = input[0];
        std::cout << "char: '" << static_cast<unsigned char>(ch) << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(ch) << std::endl;
        std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(ch) << std::endl;
        std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(ch) << "f" << std::endl;
        return;
    }
    char* end;
    if (input.find('.') == std::string::npos)
    {
        long value = strtol(input.c_str(), &end, 10);
        if (*end != '\0' && *end != 'f') {
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: impossible" << std::endl;
                std::cout << "float: " << input <<  "f" << std::endl;
                std::cout << "double: " << input << std::endl;
            return ;
        }
        if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max()) {
            std::cout << "char: impossible" << std::endl;
        } else
            if (std::isprint(static_cast<unsigned char>(value))) {
                    std::cout << "char: '" << static_cast<unsigned char>(value) << "'" << std::endl;
                } else {
                    std::cout << "char: Non displayable" << std::endl;
        }

        if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max()) {
            std::cout << "int: impossible" << std::endl;
        } else {
            std::cout << "int: " << static_cast<int>(value) << std::endl;
        }
        std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(value) << std::endl;
        std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(value) << "f" << std::endl;
    }
    /*Double path (no 'f' suffix): Uses strtod()
    Float path (has 'f' suffix): Uses strtof()*/
    else
    {
        if (input.find('f') == std::string::npos)
        {
            double value = strtod(input.c_str(), &end);
            if (*end != '\0' && *end != 'f') {
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: impossible" << std::endl;
                std::cout << "float: " << input <<  "f" << std::endl;
                std::cout << "double: " << input << std::endl;
                return ;
            }
            if (std::isprint(static_cast<unsigned char>(value))) {
                    std::cout << "char: '" << static_cast<unsigned char>(value) << "'" << std::endl;
                } else {
                    std::cout << "char: Non displayable" << std::endl;
                }
            std::cout << "int: " << static_cast<int>(value) << std::endl;
            std::cout << std::fixed << std::setprecision(1) << "double: " << value << std::endl;
            std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(value) << "f" << std::endl;
        }
        else
        {
            float value = strtof(input.c_str(), &end); //Converts C++ string to C-style null-terminated character array
            if (*end != '\0' && *end != 'f') {
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: impossible" << std::endl;
                std::cout << "float: " << input <<  "f" << std::endl;
                std::cout << "double: " << input << std::endl;
                return ;
            }
            if (std::isprint(static_cast<unsigned char>(value))) {
                    std::cout << "char: '" << static_cast<unsigned char>(value) << "'" << std::endl;
                } else {
                    std::cout << "char: Non displayable" << std::endl;
                }
            std::cout << "int: " << static_cast<int>(value) << std::endl;
            std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(value) << std::endl;
            std::cout << std::fixed << std::setprecision(1) << "float: " << value << "f" << std::endl;
        }
    }
}
/*Input "42" → Detected as int, converts to all types
Input "42.5" → Detected as double, converts to all types
Input "42.5f" → Detected as float, converts to all types
Input "A" → Detected as char, shows ASCII value conversions
Input "invalid" → Shows "impossible" for char/int, echoes input for float/double*/


/*strtol: Converts string to long int
strtod:  Converts string to double
strtof: Converts string to float
*/