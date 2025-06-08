#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "\n----MAIN 1: Array of Animals----\n" << std::endl;
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

    std::cout << "\n----MAIN 2: Deep Copy Test----\n" << std::endl;
    {
        Dog dog1;
        dog1.setBrain("I am a dog", 0);
        
        Dog dog2(dog1);  // Copy constructor
        dog2.setBrain("I am a copy dog", 0);
        
        Dog dog3;
        dog3 = dog1;     // Assignment operator
        dog3.setBrain("I am an assigned dog", 0);

        std::cout << "Original dog idea: " << dog1.getBrain()->getIdea(0) << std::endl;
        std::cout << "Copied dog idea: " << dog2.getBrain()->getIdea(0) << std::endl;
        std::cout << "Assigned dog idea: " << dog3.getBrain()->getIdea(0) << std::endl;
    }

    std::cout << "\n----MAIN 3: Cat Deep Copy Test----\n" << std::endl;
    {
        Cat cat1;
        cat1.setBrain("I am a cat", 0);
        
        Cat cat2(cat1);  // Copy constructor
        cat2.setBrain("I am a copy cat", 0);
        
        Cat cat3;
        cat3 = cat1;     // Assignment operator
        cat3.setBrain("I am an assigned cat", 0);

        std::cout << "Original cat idea: " << cat1.getBrain()->getIdea(0) << std::endl;
        std::cout << "Copied cat idea: " << cat2.getBrain()->getIdea(0) << std::endl;
        std::cout << "Assigned cat idea: " << cat3.getBrain()->getIdea(0) << std::endl;
    }
}
