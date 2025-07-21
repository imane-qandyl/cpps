/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 20:02:41 by imqandyl          #+#    #+#             */
/*   Updated: 2025/07/12 20:02:42 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) 
    : AForm("Presidential Pardon", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) 
    : AForm(copy), target(copy.target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src) {
    if (this != &src) {
        this->target = src.target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
    if (!this->getIsSigned())
        throw std::runtime_error("Form is not signed");
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    
    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
