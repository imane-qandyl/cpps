#pragma once
#include <list>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
#include <deque>

// MutantStack: a stack that exposes iterators to its underlying container
template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
    public:
        MutantStack() : std::stack<T, Container>()
        {
            std::cout << "Constructor being called here " << std::endl;
        }
        ~MutantStack(){
                std::cout << "Deconstructor being called here " << std::endl;
        }
        typedef typename Container::iterator iterator;
        iterator begin() { return this->c.begin(); }
        iterator end() { return this->c.end(); }
};
