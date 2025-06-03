#include "Brain.hpp"

Brain::Brain() 
{
    for (int i = 0; i < 100; i++)
        this->ideas[i] = " is default ";
    std::cout << "Brain constructed\n";
}

Brain::Brain(const Brain& copy) {
    for (int i = 0; i < 100; i++)
        this->ideas[i] = copy.ideas[i];
    std::cout << "Brain copy constructed\n";
}

Brain& Brain::operator=(const Brain& copy) 
{
    if (this != &copy) {
        for (int i = 0; i < 100; i++)
        this->ideas[i] = copy.ideas[i];
    }
    std::cout << "Brain assigned\n";
    return *this;
}
std::string Brain::getIdea(int index) const {
    if (index < 0 || index >= 100) return "";
    return ideas[index];
}

void Brain::setIdea(int index, const std::string& idea) {
    if (index < 0 || index >= 100) return;
    ideas[index] = idea;
}
Brain::~Brain() {
    std::cout << "Brain destroyed\n";
}
