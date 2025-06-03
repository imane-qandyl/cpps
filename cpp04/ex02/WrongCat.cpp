#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    std::cout << "WrongCat Constructor called" << std::endl;
}
WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal()
{
    if (this != &copy)
        this->type = copy.type;
    std::cout << "WrongCat Copy Constuctor is being called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &copy)
{
    if (this != &copy)
        this->type = copy.type;
    std::cout << "WrongCat Copy Assignment Constructor is Called" << std::endl;
    return (*this);
}

WrongCat::~WrongCat() 
{
    std::cout << "WrongCat Destructor is being called" << std::endl;
}
const std::string WrongCat::getType(void) const 
{
    return (this->type);
}
void WrongCat::makeSound(void) const 
{
    std::cout << "WrongCat sound : meow!" << std::endl;
}