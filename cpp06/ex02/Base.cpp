#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base::~Base() {
    std::cout << "Base Destructor called" << std::endl;
}

Base* generate() {
    std::srand(std::time(0));
    int r = std::rand() % 3;

    switch (r) {
        case 0: std::cout << "Generated: A\n"; return new A;
        case 1: std::cout << "Generated: B\n"; return new B;
        case 2: std::cout << "Generated: C\n"; return new C;
        default: return nullptr;
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "The pointer type of Base is A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "The pointer type of Base is B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "The pointer type of Base is C" << std::endl;
    else
        std::cout << "The pointer type of Base is invalid" << std::endl;
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "The reference type of Base is A" << std::endl;
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "The reference type of Base is B" << std::endl;
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "The reference type of Base is C" << std::endl;
    } catch (...) {}
}