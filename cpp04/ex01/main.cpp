#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "\n----MAIN 1----\n" << std::endl;
	{
		const Animal* animals[4];
	
		// Assign half cats and half dogs to the animal pointer array of size 4.
		for (int i = 0; i < 2; i++) {
			animals[i] = new Cat();
		}
		for (int i = 2; i < 4; i++) {
			animals[i] = new Dog();
		}

		std::cout << "\n\n";
		// Free the dynamically allocated memory for members of the animals array.
		for (int i = 0; i < 4; i++) {
			delete (animals[i]);
		}
	}
}
