#pragma once

#include "AForm.hpp"
#include <fstream>

class PresidentialPardonForm : public AForm {
private:
    std::string target;

public:
    PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(const PresidentialPardonForm& copy);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& src);
    ~PresidentialPardonForm();
    class FileNotOpenException : public std::exception {
		virtual const char* what() const throw();
	};
    void execute(Bureaucrat const& executor) const;
};
