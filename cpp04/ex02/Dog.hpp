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
    const std::string getType() const;
    void makeSound() const;
    void setBrain(std::string ideas, int index);
    Brain* getBrain() const;

};
#endif