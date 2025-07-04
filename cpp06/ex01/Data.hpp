#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include <iostream>

class Data {
public:
    Data(int n, const std::string& str) : number(n), text(str) {}

    int number;        // Example data member (an integer)
    std::string text;  // Example data member (a string)

    // A simple display method for testing
    void display() const {
        std::cout << "Data { number: " << number << ", text: \"" << text << "\" }" << std::endl;
    }
};

#endif
