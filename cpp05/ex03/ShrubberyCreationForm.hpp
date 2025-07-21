/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 20:03:07 by imqandyl          #+#    #+#             */
/*   Updated: 2025/07/12 20:03:08 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
private:
    std::string target;

public:
    ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm& copy);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& src);
    ~ShrubberyCreationForm();
    class FileNotOpenException : public std::exception {
        virtual const char* what() const throw();
    };

    void execute(Bureaucrat const& executor) const;
};
#endif
