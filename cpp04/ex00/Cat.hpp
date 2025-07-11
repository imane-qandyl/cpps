#ifndef Cats_HPP
#define Cats_HPP

#include "Animal.hpp"
#include <iostream>
#include <string>

class Cat : public Animal
{
    public:
    Cat ();
    Cat (const Cat &copy);
    Cat &operator=(const Cat &copy);
    ~Cat ();
    void makeSound() const;
};
#endif