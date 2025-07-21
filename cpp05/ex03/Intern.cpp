/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 09:11:07 by imqandyl          #+#    #+#             */
/*   Updated: 2025/07/21 09:47:49 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& copy) {
    (void)copy;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

Intern::~Intern() {}

static AForm* createRobotomyRequestForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

static AForm* createShrubberyCreationForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

static AForm* createPresidentialPardonForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    struct FormPair {
        std::string name;
        AForm* (*create)(const std::string& target);
    };

    FormPair forms[] = {
        {"robotomy request", createRobotomyRequestForm},
        {"shrubbery creation", createShrubberyCreationForm},
        {"presidential pardon", createPresidentialPardonForm}
    };

    for (size_t i = 0; i < sizeof(forms) / sizeof(forms[0]); ++i) {
        if (forms[i].name == formName) {
            std::cout << "Intern creates " << formName << std::endl;
            return forms[i].create(target);
        }
    }

    std::cout << "Form name invalid: " << formName << " not found" << std::endl;
    return nullptr;
}
