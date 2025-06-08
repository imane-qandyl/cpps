#ifndef BRAIN_HPP
#define BRAIN_HPP
#include "Animal.hpp"

class Brain 
{
    public:
        std::string ideas[100];
        Brain();
        Brain(const Brain &copy);
        Brain &operator=(const Brain &copy);
        std::string getIdea(int index) const;
        void setIdea(int index, const std::string& idea);
        ~Brain();

    
};
#endif