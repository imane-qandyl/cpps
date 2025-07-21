#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

int main() {
    Base* hello = generate(); // Generate a random Base-derived object
    identify(hello);          // Identify the type using a pointer
    identify(*hello);         // Identify the type using a reference

    delete hello;             // Clean up the dynamically allocated object
    return 0;
}