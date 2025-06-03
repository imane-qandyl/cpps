#ifndef WrongAnimal_HPP
#define WrongAnimal_HPP


#include <iostream>
#include <string>

class WrongAnimal
{
    protected:
    std::string type;
    public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal &copy);
    WrongAnimal &operator=(const WrongAnimal &copy);
    virtual ~WrongAnimal();
    const std::string getType() const;
    virtual void makeSound() const;
};
#endif