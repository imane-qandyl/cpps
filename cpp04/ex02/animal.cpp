#include "Animal.hpp"

AAnimal::AAnimal() : type("") 
{ 
    std::cout << "AAnimal Constructor called" << std::endl; 
}

AAnimal::AAnimal(const AAnimal &copy)
{
    if (this != &copy)
        this->type = copy.type;
    std::cout << "AAnimal Copy Constructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &copy)
{
    if (this != &copy)
        this->type = copy.type;
    std::cout << "AAnimal Copy Assignment Operator called" << std::endl;
    return (*this);
}

AAnimal::~AAnimal() 
{
    std::cout << "AAnimal Destructor called" << std::endl;
}

const std::string AAnimal::getType() const 
{
    return (this->type);
}

void AAnimal::makeSound(void) const 
{
    std::cout << "Animal sound Nothing" << std::endl;
}