#pragma once

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"
class Bureaucrat;

class AForm {
    private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;
    AForm();
    public:
    AForm(const std::string &name, int gradeToSign, int gradeToExecute);
    ~AForm();
    AForm(const AForm &copy);
    AForm &operator=(const AForm &other);
    std::string const& getName() const;
    bool getIsSigned() const;
    int const& getGradeToSign() const;
    int const& getGradeToExecute() const;
    void beSigned(const Bureaucrat &bureaucrat);
    virtual void execute(Bureaucrat const& executor) const = 0; // Abstract
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
std::ostream& operator<<(std::ostream& output, const AForm& f);


/*These forms must perform some action, and a bureaucrat must be able to execute them.
That means AForm must declare execute() as a virtual function — ideally abstract (pure virtual) since every derived form will implement it differently
*/