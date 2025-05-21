/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 08:45:52 by imqandyl          #+#    #+#             */
/*   Updated: 2025/05/21 19:42:01 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
    protected:        
        std::string name;
        unsigned  int hitPoints;
        unsigned  int energyPoints;
        unsigned  int attackDamage;
    
    public:
        ClapTrap(const std::string &name);
        ClapTrap(const ClapTrap &target);
        ClapTrap &operator=(const ClapTrap &ClapTrap);
        ~ClapTrap();
        void attack(const std::string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

};

#endif