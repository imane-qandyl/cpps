#include "MutantStack.hpp"

template <typename T>
void		print_stack(const MutantStack<T>& stack) {
	typename MutantStack<T>::const_reverse_iterator start = stack.rbegin();
	typename MutantStack<T>::const_reverse_iterator end = stack.rend();
	for (typename MutantStack<T>::const_reverse_iterator iter = start; iter != end; iter++) {
		std::cout << *iter << std::endl;
	}
}

int main()
{
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << "The top element is: " << mstack.top() << std::endl;

        mstack.pop();
        std::cout << "The current size is: " << mstack.size() << std::endl;

        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);

        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();

        ++it;
        --it;

        // while (it != ite--)
        // {
        //     std::cout << *ite << std::endl;
        // }
        std::cout << "============================" << std::endl;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }

        std::stack<int> s(mstack);
    }

    std::cout << "=============== for list ===============" << std::endl;
    {
        std::list<int> mlist;
        mlist.push_back(5);
        mlist.push_back(17);
    
        std::cout << "The top element is: " << mlist.back() << std::endl;

        mlist.pop_back();

        std::cout << "The current size is: " << mlist.size() << std::endl;

        mlist.push_back(3);
        mlist.push_back(5);
        mlist.push_back(737);

        mlist.push_back(0);
        std::list<int>::iterator it = mlist.begin();
        std::list<int>::iterator ite = mlist.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }

        std::list<int> s(mlist);
    }

    std::cout << "=============== for const ===============" << std::endl;
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << "The top element is: " << mstack.top() << std::endl;

        mstack.pop();
        std::cout << "The current size is: " << mstack.size() << std::endl;

        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);

        print_stack(mstack);

        MutantStack<int> mstack2(mstack);
        std::cout << "The top element of the copied stack is: " << *(mstack2.begin()) << std::endl;
        std::cout << "The top element of the copied stack is: " << *(mstack2.end()) << std::endl;
    }
    return 0;
}
