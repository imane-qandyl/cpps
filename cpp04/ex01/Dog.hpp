#ifndef dog_HPP
#define dog_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

class Dog : public Animal
{
    private:
    Brain* brain;
    public:
    Dog ();
    Dog (const Dog &copy);
    Dog &operator=(const Dog &copy);
    ~Dog ();
    void makeSound() const;
    void setBrain(const std::string& idea, int index);
    Brain* getBrain() const;
};
#endif