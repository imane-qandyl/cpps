/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 08:23:40 by imqandyl          #+#    #+#             */
/*   Updated: 2025/05/15 20:07:50 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
    ClapTrap ct("Clappy") ;

    std::cout << "\n-- Actions Begin --\n";
    ct.attack("target dummy");
    ct.takeDamage(4);
    ct.beRepaired(3);
    ct.takeDamage(7);
    ct.attack("target dummy");
    ct.beRepaired(5);

    std::cout << "-- Actions End --\n";

    return 0;
}
