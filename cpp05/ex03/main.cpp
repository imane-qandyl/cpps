/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 20:02:36 by imqandyl          #+#    #+#             */
/*   Updated: 2025/07/21 09:44:31 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include "Intern.hpp"

int main() {
    Intern someRandomIntern;
    AForm* rrf;
    
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf) {
        std::cout << *rrf << std::endl; // Print form details
        delete rrf; // Clean up the form
    } else {
        std::cout << "Failed to create form." << std::endl;
    }
}
