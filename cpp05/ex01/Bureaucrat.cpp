#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name), grade(grade) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    std::cout << "Bureaucrat constructor called\n" << std::endl;
}
Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat destructor called\n" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade) {
    std::cout << "Bureaucrat copy constructor called\n" << std::endl;
    *this =other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
    if (this != &other) {
        this->grade = other.grade;
        // Note: name is const, so we cannot assign it
        // (std::string)this->name = other.name; // This line would cause a compilation error
    }
    std::cout << "Bureaucrat assignment operator called\n" << std::endl;
    return *this;
}

std::string const& Bureaucrat::getName() const {
    return this->name;
}

int const& Bureaucrat::getGrade() const {
    return this->grade;
}
//1 (highest rank) to 150 (lowest rank)
void Bureaucrat::incrementGrade() {
    if (this->grade <= 1)
        throw GradeTooHighException();
    this->grade--;
}

void Bureaucrat::decrementGrade() {
    if (this->grade >= 150)
        throw GradeTooLowException();
    this->grade++;
}

void Bureaucrat::signForm(Form &form) {
    try {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << this->getName() << " couldn't sign " << form.getName() 
                  << " because " << e.what() << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low!";
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& object) {
    o << object.getName() << ", bureaucrat grade " << object.getGrade() << ".";
    return o;
}

