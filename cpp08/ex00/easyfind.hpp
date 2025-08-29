#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

template <typename T>
typename T::const_iterator easyfind(const T& container, int value) {

   typename T::const_iterator it = std::find(container.begin(), container.end(), value); //To tell the compiler: "This is a type nested inside the template parameter T."

    if (it == container.end()) {
        throw std::runtime_error("Value not found in container.");
    }
    return it;
}
