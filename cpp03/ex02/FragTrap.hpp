/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    FragTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 11:10:11 by imqandyl          #+#    #+#             */
/*   Updated: 2025/05/11 11:10:12 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap(std::string name);
        FragTrap(FragTrap &target);
        FragTrap &operator=(const FragTrap &ClapTrap);
        ~FragTrap();
        void    attack(const std::string &target);
        void    highFivesGuys(void);
};
#endif