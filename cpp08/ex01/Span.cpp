#include "Span.hpp"

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(const Span &copy) : _maxSize(0) {
    this->_maxSize = copy._maxSize;
    std::cout << "Copy Span Constructor Called" << std::endl;
}

Span &Span::operator=(const Span &copy)
{
    if(this != &copy)
    {    
        this->_maxSize = copy._maxSize;
        std::cout << "Copy Assignment Span Constructor Called" << std::endl;
    }
    return (*this);
}

Span::~Span() {
    std::cout << "Span Destructor Called" << std::endl;
}

void Span::addNumber(int number) {
    if (_numbers.size() >= _maxSize)
        throw std::overflow_error("Cannot add more numbers: Span is full.");
    _numbers.push_back(number);
}

int Span::shortestSpan() {
    if (_numbers.size() < 2)
        throw std::logic_error("Not enough numbers to find a span.");

    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());

    int minSpan = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sorted.size(); ++i) {
        int span = sorted[i] - sorted[i - 1];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

int Span::longestSpan() {
    if (_numbers.size() < 2)
        throw std::logic_error("Not enough numbers to find a span.");

    int minVal = *(std::min_element(_numbers.begin(), _numbers.end()));
    int maxVal = *(std::max_element(_numbers.begin(), _numbers.end()));

    return maxVal - minVal;
}
