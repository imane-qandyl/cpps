#pragma once

#include "AForm.hpp"
#include <fstream>

class RobotomyRequestForm: public AForm {
private:
    std::string target;

public:
    RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(const RobotomyRequestForm& copy);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& src);
    ~RobotomyRequestForm();

    void execute(Bureaucrat const& executor) const;
};
