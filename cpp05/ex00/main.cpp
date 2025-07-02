#include "Bureaucrat.hpp"

int main() {
    // Test 1: Valid bureaucrat
    try {
        Bureaucrat alice("Alice", 75);
        std::cout << alice << std::endl;
        alice.incrementGrade();
        std::cout << alice << std::endl;
    }
    catch (std::exception & e) {
        std::cout << "Exception1: " << e.what() << std::endl; //// This WON'T execute no exeption
    }

    // Test 2: Grade too high (constructor)
    try {
        Bureaucrat bob("Bob", 0);
    }
    catch (std::exception & e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 3: Grade too low (constructor)
    try {
        Bureaucrat charlie("Charlie", 151);
    }
    catch (std::exception & e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 4: Increment beyond limit
    try {
        Bureaucrat dave("Dave", 1);
        dave.incrementGrade();
    }
    catch (std::exception & e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 5: Decrement beyond limit
    try {
        Bureaucrat eve("Eve", 150);
        eve.decrementGrade();
    }
    catch (std::exception & e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}