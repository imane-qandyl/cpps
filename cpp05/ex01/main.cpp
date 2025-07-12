/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 20:02:09 by imqandyl          #+#    #+#             */
/*   Updated: 2025/07/12 20:02:10 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        // Test successful signing
        Bureaucrat alice("Alice", 30);
        Form taxForm("Tax Form", 50, 40);
        alice.signForm(taxForm);
        std::cout << taxForm << std::endl;

        // Test failed signing
        Bureaucrat bob("Bob", 100);
        Form vipForm("VIP Form", 20, 10);
        bob.signForm(vipForm);
        std::cout << vipForm << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}