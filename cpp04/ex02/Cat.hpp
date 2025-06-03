#ifndef Cats_HPP
#define Cats_HPP

#include "animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

class Cat : public Animal
{
    private:
    Brain* brain;
    public:
    Cat ();
    Cat (const Cat &copy);
    Cat &operator=(const Cat &copy);
    ~Cat ();
    const std::string getType() const;
    void makeSound() const;
    Brain* getBrain() const;

};
#endif