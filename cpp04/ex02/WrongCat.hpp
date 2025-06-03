#ifndef WrongCat_HPP
#define WrongCat_HPP

#include "WrongAnimal.hpp"
#include <iostream>
#include <string>

class WrongCat : public WrongAnimal
{
    public:
    WrongCat ();
    WrongCat (const WrongCat &copy);
    WrongCat &operator=(const WrongCat &copy);
    ~WrongCat ();
    const std::string getType() const;
    void makeSound() const;
};
#endif