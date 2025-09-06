#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <stdexcept>
#include <climits>
#include <sstream>
#include <algorithm>
#include <utility> // for std::pair
#include <iterator>
#include <cstring>
#include <cctype>
#include <cerrno>
#include <cmath>
#include <limits>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &src);
        PmergeMe &operator=(const PmergeMe &rhs);
        ~PmergeMe();
    
        void fillContainers(char **av);
        void printContainers(std::string msg);
        void sortContainers();
        void printTimeTaken();
    
    private:
        std::vector<int> _vector;
        std::deque<int> _deque;
        double _vectorTime;
        double _dequeTime;
    
        // Ford-Johnson sort in C++98 style
        std::vector<int> fordJohnsonSortVector(std::vector<int> &vector);
        std::deque<int> fordJohnsonSortDeque(std::deque<int> &deq);
    
        // Jacobsthal number
        int jacobsthal(int n);
};