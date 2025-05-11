/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    FragTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 11:10:20 by imqandyl          #+#    #+#             */
/*   Updated: 2025/05/11 11:10:21 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
    std::cout << "FragTrap constructor called for " << this->name << std::endl;
}

FragTrap::FragTrap(FragTrap &target) : ClapTrap(target)
{
    std::cout << "FragTrap Copy Constructor called for " << this->name << std::endl;
    *this = target;
}

FragTrap &FragTrap::operator=(const FragTrap &FragTrap)
{
    std::cout << "FragTrap Copy Assignment Constructor called for " << this->name << std::endl;
    if (this != &FragTrap)
    {
        this->name = FragTrap.name;
        this->hitPoints = FragTrap.hitPoints;
        this->energyPoints = FragTrap.energyPoints;
        this->attackDamage = FragTrap.attackDamage;
    }
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called for " << this->name << std::endl;
}


void FragTrap::attack(const std::string &target)
{
    if (this->energyPoints <= 0)
		std::cout << this->name << " doesn't have enough Energy Point to repaire" << std::endl;
	else
	{
    std::cout << "FragTrap " << this->name << " attacks " << target << " causing " << this->attackDamage << " points of damage!" << std::endl;
    }
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->name << " high fives!" << std::endl;
}

