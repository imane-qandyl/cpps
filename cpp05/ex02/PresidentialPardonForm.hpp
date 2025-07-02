#pragma once

#include "AForm.hpp"
#include <fstream>

class PresidentialPardonForm : public AForm {
private:
    std::string target;

public:
    PresidentialPardonForm(const std::string& target);
    ~PresidentialPardonForm();

    void execute(Bureaucrat const& executor) const;
};
