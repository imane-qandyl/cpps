#pragma once

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat {
    private:
        const std::string name;
        int grade;
        Bureaucrat();
    public:
        Bureaucrat(const std::string &name, int grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        std::string const& getName() const;
        int const& getGrade() const;
        void incrementGrade();
        void decrementGrade();
        void signForm(Form &form);
        /* Exceptions */
        class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw();
        };
};             
std::ostream&		operator<<(std::ostream& o, const Bureaucrat& object);

