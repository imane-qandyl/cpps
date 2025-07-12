/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 20:03:02 by imqandyl          #+#    #+#             */
/*   Updated: 2025/07/12 20:03:04 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :AForm("Shrubbery Creation", 145, 137), target(target){}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy), target(copy.target)
{
     std::cout << "ShrubberyCreationForm copy constructor called\n" << std::endl;
    *this = copy;
}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
    if (this != &src) {
        this->target = src.target;
        // Note: AForm's name, isSigned, gradeToSign, and gradeToExecute are const, so we cannot assign them
    }
    std::cout << "ShrubberyCreationForm assignment operator called\n" << std::endl;
    return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor called\n" << std::endl;
}
const char* ShrubberyCreationForm::FileNotOpenException::what() const throw() {
    return "File could not be opened";
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
    if (!this->getIsSigned())
        throw std::runtime_error("Form is not signed");
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    
    std::string filename = this->target + "_shrubbery";
    std::ofstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Could not open file");
    
    file << "       _-_\n";
    file << "    /~~   ~~\\\n";
    file << " /~~         ~~\\\n";
    file << "{               }\n";
    file << " \\  _-     -_  /\n";
    file << "   ~  \\\\ //  ~\n";
    file << "_- -   | | _- _\n";
    file << "  _ -  | |   -_\n";
    file << "      // \\\\\n";
    file << "     //   \\\\\n";
    file << "    //     \\\\\n";
    file << "   ||       ||\n";
    file << "   ||       ||\n";
    file << "   ||_______||\\n";
    
    file.close();
    std::cout << "Shrubbery has been planted at " << filename << std::endl;
}