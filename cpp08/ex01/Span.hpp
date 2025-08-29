#pragma once

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>
#include <iostream>

class Span {
    private:
        unsigned int _maxSize;
        std::vector<int> _numbers;

    public:
        Span(unsigned int N);
        Span(const Span &copy);
        Span& operator=(const Span &copy);
        ~Span();
        void addNumber(int number);
        int shortestSpan();
        int longestSpan();
};
//max()To guarantee that any real distance you calculate will be smaller

//1, 5, 7, 100 //100-1=99 longest
/*10, 5, 20, 3
minSpan starts as the biggest possible int (randomly).
Sort: 3, 5, 10, 20

Compare:

5 - 3 = 2 < minspan

10 - 5 = 5

20 - 10 = 10

Shortest span: 2*/
