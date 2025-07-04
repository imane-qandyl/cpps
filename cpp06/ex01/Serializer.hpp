#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <cctype>
// #include <cstdint>
class Data;

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