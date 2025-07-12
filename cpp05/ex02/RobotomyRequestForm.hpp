/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 20:02:57 by imqandyl          #+#    #+#             */
/*   Updated: 2025/07/12 20:02:58 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <fstream>

class RobotomyRequestForm: public AForm {
private:
    std::string target;

public:
    RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(const RobotomyRequestForm& copy);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& src);
    ~RobotomyRequestForm();

    void execute(Bureaucrat const& executor) const;
};
