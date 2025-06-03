#include "Dog.hpp"

Dog::Dog() : Animal()
{
    this->brain = new Brain();
    this->type = "Dog";
    std::cout << "Dog Constructor called" << std::endl;
}
Dog::Dog(const Dog &copy) : Animal()
{
    if (this != &copy)
    {    
        this->type = copy.type;
        this->brain = new Brain(*copy.brain);
    }
    std::cout << "Dog Copy Constuctor called" << std::endl;
}

Dog &Dog::operator=(const Dog &copy)
{
    if (this != &copy)
    {
        this->type = copy.type;
        if (this->brain)
        delete this->brain; //to avoid memory leaks.
        delete brain;
        this->brain = new Brain(*copy.brain);
    }
    std::cout << "Dog Copy Assignment Constructor Called" << std::endl;
    return (*this);
}
void Dog::makeSound(void) const 
{
    std::cout << "Dog sound : hawhaw!" << std::endl;
}
Brain* Dog::getBrain() const {
    return brain;
}
Dog::~Dog() 
{
    delete brain;
    std::cout << "Dog destroyed\n";
}