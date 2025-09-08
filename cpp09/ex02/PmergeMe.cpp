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

    // Handle odd element (remaining )
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

bool PmergeMe::isValidPositiveInteger(const std::string &str)
{
    if (str.empty())
        return false;
    
    for (size_t i = 0; i < str.length(); ++i)
    {
        if (!std::isdigit(str[i]))
            return false;
    }
    
    // Convert and check if it's positive
    std::istringstream iss(str);
    int num;
    iss >> num;
    return num > 0;
}

void PmergeMe::printContainer(const std::vector<int> &container, const std::string &label)
{
    std::cout << label;
    for (size_t i = 0; i < container.size(); ++i)
    {
        std::cout << container[i];
        if (i < container.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::processSequence(int argc, char **argv)
{
    std::vector<int> numbers;
    
    // Parse and validate arguments
    for (int i = 1; i < argc; ++i)
    {
        std::string arg(argv[i]);
        if (!isValidPositiveInteger(arg))
        {
            throw std::invalid_argument("Invalid argument: " + arg);
        }
        
        std::istringstream iss(arg);
        int num;
        iss >> num;
        numbers.push_back(num);
    }
    
    if (numbers.empty())
        throw std::invalid_argument("No valid numbers provided");
    
    // Display original sequence
    printContainer(numbers, "Before: ");
    
    // Sort with vector and measure time
    clock_t start = clock();
    std::vector<int> sortedVector = this->fordJohnsonSortVector(numbers);
    clock_t end = clock();
    double vectorTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
    
    // Sort with deque and measure time
    std::deque<int> dequeNumbers(numbers.begin(), numbers.end());
    start = clock();
    std::deque<int> sortedDeque = this->fordJohnsonSortDeque(dequeNumbers);
    end = clock();
    double dequeTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
    
    // Display sorted sequence
    std::vector<int> resultVector(sortedVector.begin(), sortedVector.end());
    printContainer(resultVector, "After:  ");
    
    // Display timing information
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Time to process a range of " << numbers.size() 
              << " elements with std::vector : " << vectorTime << " us" << std::endl;
    std::cout << "Time to process a range of " << numbers.size() 
              << " elements with std::deque  : " << dequeTime << " us" << std::endl;
}
