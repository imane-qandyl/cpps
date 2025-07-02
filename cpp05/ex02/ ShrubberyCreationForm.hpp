#pragma once

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
private:
    std::string target;

public:
    ShrubberyCreationForm(const std::string& target);
    ~ShrubberyCreationForm();

    void execute(Bureaucrat const& executor) const;
};
