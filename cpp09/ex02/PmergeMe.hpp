#pragma once

#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <ctime>
#include <iomanip>

class PmergeMe
{
private:
    static int jacobsthal(int n);
    
public:
    PmergeMe();
    PmergeMe(const PmergeMe &src);
    PmergeMe &operator=(const PmergeMe &rhs);
    ~PmergeMe();
    
    std::vector<int> fordJohnsonSortVector(std::vector<int> vector);
    std::deque<int> fordJohnsonSortDeque(std::deque<int> deque);
    
    void processSequence(int argc, char **argv);
    static bool isValidPositiveInteger(const std::string &str);
    static void printContainer(const std::vector<int> &container, const std::string &label);
};

