/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 20:02:45 by imqandyl          #+#    #+#             */
/*   Updated: 2025/07/12 20:02:46 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <fstream>

class PresidentialPardonForm : public AForm {
private:
    std::string target;

public:
    PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(const PresidentialPardonForm& copy);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& src);
    ~PresidentialPardonForm();
    class FileNotOpenException : public std::exception {
		virtual const char* what() const throw();
	};
    void execute(Bureaucrat const& executor) const;
};
