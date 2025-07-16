#include "easyfind.hpp"

int main() {
    try {
        std::vector<int> vec = {10, 20, 30, 40};
        std::vector<int>::const_iterator it = easyfind(vec, 30);
        std::cout << "Found in vector: " << *it << std::endl;

        std::list<int> lst = {1, 2, 3, 4, 5};
        std::list<int>::const_iterator it2 = easyfind(lst, 4);
        std::cout << "Found in list: " << *it2 << std::endl;

        easyfind(lst, 99); // This will throw
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
