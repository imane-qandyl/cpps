#pragma once

#include <iostream>

// Base class
class Base {
public:
    virtual ~Base(); // Virtual destructor for proper cleanup
};

// Standalone function declarations
Base* generate();
void identify(Base* p);
void identify(Base& p);