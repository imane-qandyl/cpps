/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 20:03:59 by imqandyl          #+#    #+#             */
/*   Updated: 2025/07/12 20:04:00 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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