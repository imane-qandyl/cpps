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
        MutantStack(const MutantStack& other) : std::stack<T, Container>(other)
        {
            std::cout << "Copy constructor being called here " << std::endl;
            *this = other;
        }
        MutantStack& operator=(const MutantStack& other)
        {
            if (this != &other)
                std::stack<T, Container>::operator=(other);
            std::cout << "Assignment operator being called here " << std::endl;
            return *this;
        }
        ~MutantStack(){
                std::cout << "Destructor being called here " << std::endl;
        }

        typedef typename Container::iterator iterator;
        iterator begin() { return this->c.begin(); };
        iterator end() { return this->c.end(); };

        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		reverse_iterator	rbegin() {return this->c.rbegin();};
		reverse_iterator	rend() {return this->c.rend();};

		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		const_iterator		begin() const {return this->c.begin();};
		const_iterator		end() const {return this->c.end();};

		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
		const_reverse_iterator		rbegin() const {return this->c.rbegin();};
		const_reverse_iterator		rend() const {return this->c.rend();};
};

//gets access to that protected member c.