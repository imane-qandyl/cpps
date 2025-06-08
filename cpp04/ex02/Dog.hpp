#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

class Dog : public AAnimal
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
    void setBrain(const std::string& idea, int index);
    Brain* getBrain() const;

};
#endif