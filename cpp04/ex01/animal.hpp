#ifndef ANIMAL_HPP
#define ANIMAL_HPP


#include <iostream>
#include <string>

class Animal
{
    protected:
    std::string type;
    public:
    Animal();
    Animal(const Animal &copy);
    Animal &operator=(const Animal &copy);
    virtual ~Animal();
    const std::string getType() const;
    virtual void makeSound() const;
};
#endif