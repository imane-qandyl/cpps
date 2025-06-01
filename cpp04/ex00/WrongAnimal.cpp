#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("") 
{ 
    std::cout << "WrongAnimal Constructor called" << std::endl; 
}
WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
    if (this != &copy)
        this->type = copy.type;
    std::cout << "WrongAnimal Copy Constuctor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy)
{
    if (this != &copy)
        this->type = copy.type;
    std::cout << "WrongAnimal Copy Assignment Constructor Called" << std::endl;
    return (*this);
}

WrongAnimal::~WrongAnimal() 
{
    std::cout << "WrongAnimal Destructor called" << std::endl;
}
const std::string WrongAnimal::getType(void) const 
{
    return (this->type);
}
void WrongAnimal::makeSound(void) const 
{
    std::cout << "WrongAnimal sound Nothing" << std::endl;
}