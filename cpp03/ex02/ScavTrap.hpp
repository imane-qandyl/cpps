/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 08:30:11 by imqandyl          #+#    #+#             */
/*   Updated: 2025/05/21 19:51:08 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap(const std::string &name);
        ScavTrap(const ScavTrap &target);
        ScavTrap &operator=(const ScavTrap &ClapTrap);
        ~ScavTrap();

        void    attack(const std::string &target);
        void    guardGate();
};

#endif