#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat b("Test", 50);
        std::cout << b << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}
