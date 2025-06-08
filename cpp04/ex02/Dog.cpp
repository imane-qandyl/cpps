#include "Dog.hpp"

Dog::Dog() : AAnimal()
{
    this->brain = new Brain();
    this->type = "Dog";
    std::cout << "Dog Constructor called" << std::endl;
}

Dog::Dog(const Dog &copy) : AAnimal()
{
    if (this != &copy)
    {    
        this->type = copy.type;
        this->brain = new Brain(*copy.brain);
    }
    std::cout << "Dog Copy Constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &copy)
{
    if (this != &copy)
    {
        this->type = copy.type;
        if (this->brain)
            delete this->brain;
        this->brain = new Brain(*copy.brain);
    }
    std::cout << "Dog Copy Assignment Operator called" << std::endl;
    return (*this);
}

void Dog::makeSound() const 
{
    std::cout << "Dog sound: hawhaw!" << std::endl;
}

void Dog::setBrain(const std::string& idea, int index)
{
    if (brain)
        brain->setIdea(index, idea);
}

Brain* Dog::getBrain() const 
{
    return brain;
}

Dog::~Dog() 
{
    delete brain;
    std::cout << "Dog destroyed" << std::endl;
}