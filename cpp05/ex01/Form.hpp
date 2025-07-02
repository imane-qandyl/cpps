#pragma once

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"
class Bureaucrat;

class Form {
    private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;
    Form();
    public:
    class GradeTooHighException;
    class GradeTooLowException;
    Form(const std::string &name, int gradeToSign, int gradeToExecute);
    ~Form();
    Form(const Form &other);
    Form &operator=(const Form &other);
    std::string const& getName() const;
    bool getIsSigned() const;
    int const& getGradeToSign() const;
    int const& getGradeToExecute() const;
    void beSigned(const Bureaucrat &bureaucrat);
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
std::ostream& operator<<(std::ostream& output, const Form& f);
