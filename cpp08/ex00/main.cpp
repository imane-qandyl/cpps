#include "easyfind.hpp"

int main() {
    try {
        std::vector<int> vec;
        vec.push_back(10);
        vec.push_back(20);
        vec.push_back(30);
        vec.push_back(40);
        std::vector<int>::const_iterator it = easyfind(vec, 30);
        std::cout << "Found in vector: " << *it << std::endl;

        std::list<int> lst;
        lst.push_back(2);
        lst.push_back(1);
        lst.push_back(3);
        lst.push_back(4);
        lst.push_back(5);
        std::list<int>::const_iterator it2 = easyfind(lst, 4);
        std::cout << "Found in list: " << *it2 << std::endl;

        easyfind(lst, 99); // This will throw
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
