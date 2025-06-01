#include "animal.hpp"

Animal::Animal() : type("") 
{ 
    std::cout << "Animal Constructor called" << std::endl; 
}
Animal::Animal(const Animal &copy)
{
    if (this != &copy)
        this->type = copy.type;
    std::cout << "Animal Copy Constuctor called" << std::endl;
}

Animal &Animal::operator=(const Animal &copy)
{
    if (this != &copy)
        this->type = copy.type;
    std::cout << "Animal Copy Assignment Constructor is Called" << std::endl;
    return (*this);
}

Animal::~Animal() 
{
    std::cout << "Animal Destructor called" << std::endl;
}
const std::string Animal::getType(void) const 
{
    return (this->type);
}
void Animal::makeSound(void) const 
{
    std::cout << "Animal sound Nothing" << std::endl;
}