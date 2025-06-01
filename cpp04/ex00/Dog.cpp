#include "Dog.hpp"

Dog::Dog() : Animal()
{
    this->type = "Dog";
    std::cout << "Dog Constructor called" << std::endl;
}
Dog::Dog(const Dog &copy) : Animal()
{
    if (this != &copy)
        this->type = copy.type;
    std::cout << "Dog Copy Constuctor called" << std::endl;
}

Dog &Dog::operator=(const Dog &copy)
{
    if (this != &copy)
        this->type = copy.type;
    std::cout << "Dog Copy Assignment Constructor Called" << std::endl;
    return (*this);
}
void Dog::makeSound(void) const 
{
    std::cout << "Dog sound : hawhaw!" << std::endl;
}
const std::string Dog::getType(void) const 
{
    return (this->type);
}
Dog::~Dog() 
{
    std::cout << "Dog Destructor called" << std::endl;
}