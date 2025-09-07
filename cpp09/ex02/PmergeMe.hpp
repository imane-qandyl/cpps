#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <utility>
#include <ctime>
#include <iomanip>

class PmergeMe
{
public:
    PmergeMe();
    PmergeMe(const PmergeMe &src);
    PmergeMe &operator=(const PmergeMe &rhs);
    ~PmergeMe();

    std::vector<int> fordJohnsonSortVector(std::vector<int> vector);
    std::deque<int> fordJohnsonSortDeque(std::deque<int> deque);

private:
    int jacobsthal(int n);
};