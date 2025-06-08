#include "Cat.hpp"

Cat::Cat() : Animal()
{
    this->type = "Cat";
    std::cout << "Cat Constructor called" << std::endl;
}
Cat::Cat(const Cat &copy) : Animal()
{
    if (this != &copy)
        this->type = copy.type;
    std::cout << "Cat Copy Constuctor called" << std::endl;
}

Cat &Cat::operator=(const Cat &copy)
{
    if (this != &copy)
        this->type = copy.type;
    std::cout << "Cat Copy Assignment Constructor Called" << std::endl;
    return (*this);
}
void Cat::makeSound(void) const 
{
    std::cout << "Cat sound : meow!" << std::endl;
}
Cat::~Cat() 
{
    std::cout << "Cat Destructor called" << std::endl;
}