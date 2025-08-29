#include "MutantStack.hpp"

int main()
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
    std::cout << "=============================" << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::cout << "=============================" << std::endl;

    MutantStack<int> mstack2(mstack);
    std::cout << "The top element of the copied stack is: " << *(mstack2.begin()) << std::endl;
    std::cout << "The top element of the copied stack is: " << *(mstack2.end()) << std::endl;

    return 0;
}
