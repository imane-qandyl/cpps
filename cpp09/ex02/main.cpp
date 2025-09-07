#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <ctime>
#include <iomanip>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    std::vector<int> numbers;
    
    // Parse and validate input
    for (int i = 1; i < argc; i++)
    {
        std::string arg = argv[i];
        if (arg.empty())
            continue;
            
        std::istringstream iss(arg);
        int num;
        if (!(iss >> num) || !iss.eof() || num < 0)
        {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        numbers.push_back(num);
    }

    if (numbers.empty())
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    // Display "Before"
    std::cout << "Before: ";
    for (size_t i = 0; i < numbers.size() && i < 5; i++)
    {
        std::cout << numbers[i];
        if (i < numbers.size() - 1 && i < 4)
            std::cout << " ";
    }
    if (numbers.size() > 5)
        std::cout << " [...]";
    std::cout << std::endl;

    PmergeMe sorter;

    // Sort with vector and measure time
    clock_t start = clock();
    std::vector<int> sortedVector = sorter.fordJohnsonSortVector(numbers);
    clock_t end = clock();
    double vectorTime = (static_cast<double>(end - start) / CLOCKS_PER_SEC) * 1000000.0;

    // Sort with deque and measure time
    std::deque<int> numbersDeque(numbers.begin(), numbers.end());
    start = clock();
    std::deque<int> sortedDeque = sorter.fordJohnsonSortDeque(numbersDeque);
    end = clock();
    double dequeTime = (static_cast<double>(end - start) / CLOCKS_PER_SEC) * 1000000.0;

    // Display "After"
    std::cout << "After: ";
    for (size_t i = 0; i < sortedVector.size() && i < 5; i++)
    {
        std::cout << sortedVector[i];
        if (i < sortedVector.size() - 1 && i < 4)
            std::cout << " ";
    }
    if (sortedVector.size() > 5)
        std::cout << " [...]";
    std::cout << std::endl;

    // Display timing results
    std::cout << "Time to process a range of " << numbers.size() 
              << " elements with std::[..] : " << std::fixed << std::setprecision(5) 
              << vectorTime << " us" << std::endl;
    std::cout << "Time to process a range of " << numbers.size() 
              << " elements with std::[..] : " << std::fixed << std::setprecision(5) 
              << dequeTime << " us" << std::endl;

    return 0;
}


