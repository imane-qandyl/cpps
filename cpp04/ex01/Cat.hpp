#ifndef Cats_HPP
#define Cats_HPP

#include "Animal.hpp"
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
    void makeSound() const;
    void setBrain(const std::string& idea, int index);
    Brain* getBrain() const;
};
#endif