#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
const Animal* meta = new Animal();
// const WrongAnimal* meta1 = new WrongAnimal();
const Animal* j = new Dog();
const Animal* i = new Cat();
// const WrongAnimal* b = new WrongCat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();
// b->makeSound();
// meta1->makeSound();

const WrongAnimal* wrongAnimal = new WrongAnimal();
const WrongAnimal* wrongCat = new WrongCat();
wrongCat->makeSound();

delete meta;
delete i;
delete j;
delete wrongAnimal;
delete wrongCat;

return 0;
}