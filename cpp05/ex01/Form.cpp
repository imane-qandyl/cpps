/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 20:02:00 by imqandyl          #+#    #+#             */
/*   Updated: 2025/07/12 20:02:01 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
    std::cout << "Form constructor called\n" << std::endl;
}

Form::~Form() {
    std::cout << "Form destructor called\n" << std::endl;
}

Form::Form(const Form &other)
    : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {
    std::cout << "Form copy constructor called\n" << std::endl;
    *this = other;
}
Form &Form::operator=(const Form &other) {
    if (this != &other) {
        this->isSigned = other.isSigned;
        // Note: name, gradeToSign, and gradeToExecute are const, so we cannot assign them
        // (std::string)this->name = other.name; // This line would cause a compilation error
        // this->gradeToSign = other.gradeToSign; // This line would cause a compilation error
        // this->gradeToExecute = other.gradeToExecute; // This line would cause a compilation error
    }
    std::cout << "Form assignment operator called\n" << std::endl;
    return *this;
}

std::string const& Form::getName() const {
    return this->name;
}
bool Form::getIsSigned() const {
    return this->isSigned;
}
int const& Form::getGradeToSign() const {
    return this->gradeToSign;
}
int const& Form::getGradeToExecute() const {
    return this->gradeToExecute;
}
void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > this->gradeToSign)
        throw GradeTooLowException();
    this->isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream& operator<<(std::ostream& output, const Form& f)
{
    output << "Form: " << f.getName() << ", Signed: " << (f.getIsSigned() ? "Yes" : "No")
           << ", Grade to Sign: " << f.getGradeToSign()
           << ", Grade to Execute: " << f.getGradeToExecute();
    return output;
}
