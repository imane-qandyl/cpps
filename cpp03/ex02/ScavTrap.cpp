/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 08:30:20 by imqandyl          #+#    #+#             */
/*   Updated: 2025/05/15 20:48:04 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) 
{
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;

	std::cout << "ScavTrap " << name << " constructed!\n";
}

ScavTrap::ScavTrap(ScavTrap &target) : ClapTrap(target)
{
    std::cout << "ScavTrap Copy Constructor is called" << std::endl;
	*this = target;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &ScavTrap)
{
	if (this != &ScavTrap)
	{
		this->name = ScavTrap.name;
		this->hitPoints = ScavTrap.hitPoints;
		this->energyPoints = ScavTrap.energyPoints;
		this->attackDamage = ScavTrap.attackDamage;
	}
    std::cout << "ScavTrap Copy Assignement operator is called" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " destructed!\n";
}

void ScavTrap::attack(const std::string &target) {
	if ((hitPoints <= 0 || energyPoints <= 0))
		std::cout << this->name << " doesn't have enough Energy Point to repaire" << std::endl;
	else
	{
		std::cout << "ScavTrap " << this->name << " attacks " << target <<  " causing " << this->attackDamage << " points of damage! " << std::endl;
		this->energyPoints--;
	}
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode.\n";
}
