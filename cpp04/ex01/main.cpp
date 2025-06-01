#include "animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const Animal* a1 = new Dog();
    const Animal* a2 = new Cat();

    delete a1;
    delete a2;

    std::cout << "\n--- Deep Copy Test ---" << std::endl;

    std::cout << "\n---Dog ---" << std::endl;
    Dog original;
    original.getBrain()->setIdea(0, "Chase the Dog");

    Dog copy = original; // Deep copy
    copy.getBrain()->setIdea(0, "Eat the bone");

    std::cout << "Original Dog idea: " << original.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied Dog idea: " << copy.getBrain()->getIdea(0) << std::endl;
    std::cout << "Dog end" << std::endl;

    std::cout << "\n---Cat ---" << std::endl;
    Cat original1;
    original1.getBrain()->setIdea(0, "Chase the cat");

    Cat copy1 = original1; // Deep copy
    copy1.getBrain()->setIdea(0, "Eat the bone");

    std::cout << "Original Cat idea: " << original1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied Cat idea: " << copy1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Cat end" << std::endl;

    return 0;
}
