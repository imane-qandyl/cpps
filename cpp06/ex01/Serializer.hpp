/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 20:04:23 by imqandyl          #+#    #+#             */
/*   Updated: 2025/07/12 20:09:51 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <cctype>
// #include <cstdint>
struct Data;

class Serializer {
    private:
        Serializer();
        ~Serializer();
        Serializer(Serializer const& copy);
        Serializer& operator=(Serializer const& copy);
    public:
        static Data* deserialize(uintptr_t raw);

        static uintptr_t serialize(Data* ptr);;
};

/*char literals like 'a'

int literals like 42

float literals like 42.0f, nanf, +inff, -inff

double literals like 42.0, nan, +inf, -inf
Class is non-instantiable (private constructor).

*/