#pragma once

#include <iostream>
#include <string>
#include <exception>


class Bureaucrat {
    private:
        const std::string name;
        int grade;
        Bureaucrat();
    public:
        class GradeTooHighException;
		class GradeTooLowException;
        Bureaucrat(const std::string &name, int grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        std::string const& getName() const;
        int const& getGrade() const;
        void incrementGrade();
        void decrementGrade();
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

