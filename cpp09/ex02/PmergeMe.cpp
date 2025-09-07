#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src) 
{
    *this = src;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
    if (this != &rhs)
    {
        // Nothing to copy for now
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

// Jacobsthal number
int PmergeMe::jacobsthal(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; ++i)
    {
        c = b + 2 * a;
        a = b;
        b = c;
    }
    return b;
}

// Ford-Johnson sort in C++98 style
std::vector<int> PmergeMe::fordJohnsonSortVector(std::vector<int> vector)
{
    if (vector.size() <= 1)
        return vector;

    std::vector<std::pair<int, int> > pairs;
    size_t i = 0;
    bool hasOdd = false;
    int oddElement = 0;

    // Create pairs, ensuring first < second
    for (; i + 1 < vector.size(); i += 2)
    {
        if (vector[i] > vector[i + 1])
            pairs.push_back(std::make_pair(vector[i + 1], vector[i]));
        else
            pairs.push_back(std::make_pair(vector[i], vector[i + 1]));
    }

    // Handle odd element
    if (i < vector.size())
    {
        hasOdd = true;
        oddElement = vector[i];
    }

    if (pairs.empty())
    {
        return vector;
    }

    // Recursively sort the larger elements
    std::vector<int> larger_elements;
    for (size_t j = 0; j < pairs.size(); j++)
        larger_elements.push_back(pairs[j].second);

    larger_elements = fordJohnsonSortVector(larger_elements);

    // Insert the first smaller element at the beginning
    std::vector<int> result;
    result.push_back(pairs[0].first);
    for (size_t j = 0; j < larger_elements.size(); j++)
        result.push_back(larger_elements[j]);

    // Insert remaining smaller elements using binary search
    for (size_t j = 1; j < pairs.size(); j++)
    {
        std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), pairs[j].first);
        result.insert(pos, pairs[j].first);
    }

    // Insert odd element if exists
    if (hasOdd)
    {
        std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), oddElement);
        result.insert(pos, oddElement);
    }

    return result;
}

std::deque<int> PmergeMe::fordJohnsonSortDeque(std::deque<int> deque)
{
    if (deque.size() <= 1)
        return deque;

    std::deque<std::pair<int, int> > pairs;
    size_t i = 0;
    bool hasOdd = false;
    int oddElement = 0;

    // Create pairs, ensuring first < second
    for (; i + 1 < deque.size(); i += 2)
    {
        if (deque[i] > deque[i + 1])
            pairs.push_back(std::make_pair(deque[i + 1], deque[i]));
        else
            pairs.push_back(std::make_pair(deque[i], deque[i + 1]));
    }

    // Handle odd element
    if (i < deque.size())
    {
        hasOdd = true;
        oddElement = deque[i];
    }

    if (pairs.empty())
    {
        return deque;
    }

    // Recursively sort the larger elements
    std::deque<int> larger_elements;
    for (size_t j = 0; j < pairs.size(); j++)
        larger_elements.push_back(pairs[j].second);

    larger_elements = fordJohnsonSortDeque(larger_elements);

    // Insert the first smaller element at the beginning
    std::deque<int> result;
    result.push_back(pairs[0].first);
    for (size_t j = 0; j < larger_elements.size(); j++)
        result.push_back(larger_elements[j]);

    // Insert remaining smaller elements using binary search
    for (size_t j = 1; j < pairs.size(); j++)
    {
        std::deque<int>::iterator pos = std::lower_bound(result.begin(), result.end(), pairs[j].first);
        result.insert(pos, pairs[j].first);
    }

    // Insert odd element if exists
    if (hasOdd)
    {
        std::deque<int>::iterator pos = std::lower_bound(result.begin(), result.end(), oddElement);
        result.insert(pos, oddElement);
    }

    return result;
}
