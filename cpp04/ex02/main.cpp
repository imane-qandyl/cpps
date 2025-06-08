#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
int main()
{
	Cat		cat;
	Animal*	dog = new Dog();

	std::cout << "\n";

	cat.makeSound();
	dog->makeSound();

	std::cout << "\n";

	delete(dog);

	return (0);
}