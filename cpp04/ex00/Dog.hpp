#ifndef dog_HPP
#define dog_HPP

#include "Animal.hpp"
#include <iostream>
#include <string>

class Dog : public Animal
{
    public:
    Dog ();
    Dog (const Dog &copy);
    Dog &operator=(const Dog &copy);
    ~Dog ();
    const std::string getType() const;
    void makeSound() const;

};
#endif