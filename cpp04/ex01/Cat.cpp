#include "Cat.hpp"

Cat::Cat() : Animal()
{
    this->brain = new Brain();
    this->type = "Cat";
    std::cout << "Cat Constructor called" << std::endl;
}
Cat::Cat(const Cat &copy) : Animal()
{
    if (this != &copy)
    {    
        this->type = copy.type;
        this->brain = new Brain (*copy.brain);
    }
    std::cout << "Cat Copy Constuctor called" << std::endl;
}

Cat &Cat::operator=(const Cat &copy)
{
    if (this != &copy)
     {   
        this->type = copy.type;
        if (this->brain)
        delete this->brain; //to avoid memory leaks.
        this->brain = new Brain (*copy.brain);
    }
    std::cout << "Cat Copy Assignment Constructor Called" << std::endl;
    return (*this); // to allow assignment chaining like a = b = c
}
void Cat::makeSound(void) const 
{
    std::cout << "Cat sound : meow!" << std::endl;
}

Brain* Cat::getBrain() const { return brain; }

Cat::~Cat() 
{
    delete this->brain;
    std::cout << "Cat Destructor called" << std::endl;
}