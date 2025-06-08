#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

class Cat : public AAnimal
{
    private:
    Brain* brain;
    public:
    Cat();
    Cat(const Cat &copy);
    Cat &operator=(const Cat &copy);
    ~Cat();
    void makeSound() const;
    void setBrain(const std::string& idea, int index);
    Brain* getBrain() const;
};
#endif