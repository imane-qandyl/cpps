#include "Cat.hpp"

Cat::Cat() : AAnimal()
{
    this->brain = new Brain();
    this->type = "Cat";
    std::cout << "Cat Constructor called" << std::endl;
}

Cat::Cat(const Cat &copy) : AAnimal()
{
    if (this != &copy)
    {    
        this->type = copy.type;
        this->brain = new Brain(*copy.brain);
    }
    std::cout << "Cat Copy Constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &copy)
{
    if (this != &copy)
    {   
        this->type = copy.type;
        if (this->brain)
            delete this->brain;
        this->brain = new Brain(*copy.brain);
    }
    std::cout << "Cat Copy Assignment Operator called" << std::endl;
    return (*this);
}

void Cat::makeSound() const 
{
    std::cout << "Cat sound: meow!" << std::endl;
}

void Cat::setBrain(const std::string& idea, int index)
{
    if (brain)
        brain->setIdea(index, idea);
}

Brain* Cat::getBrain() const 
{ 
    return brain; 
}

Cat::~Cat() 
{
    delete this->brain;
    std::cout << "Cat Destructor called" << std::endl;
}