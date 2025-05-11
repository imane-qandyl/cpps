/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 08:33:58 by imqandyl          #+#    #+#             */
/*   Updated: 2025/05/11 08:47:49 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap constructor called for " << this->name << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor called for " << this->name << std::endl;
}
ClapTrap::ClapTrap(ClapTrap &target)
{
	std::cout << "ClapTrap Copy Constructor is Called" << std::endl;
	*this = target;
}
ClapTrap &ClapTrap::operator=(const ClapTrap &ClapTrap)
{
	std::cout << "ClapTrap Copy Assignment Constructor is Called" << std::endl;
	if (this != &ClapTrap)
	{
		this->name = ClapTrap.name;
		this->hitPoints = ClapTrap.hitPoints;
		this->energyPoints = ClapTrap.energyPoints;
		this->attackDamage = ClapTrap.attackDamage;
	}
	return (*this);
}
//Checks if the ClapTrap is alive and has energy
void ClapTrap::attack(const std::string &target) {
    if (hitPoints <= 0 || energyPoints <= 0) {
        std::cout << "ClapTrap " << name << " cannot attack! Not enough energy or hit points." << std::endl;
        return;
    }
        energyPoints--; //spends 1 energy point
    std::cout << "ClapTrap " << name << " attacks " << target
              << ", causing " << attackDamage << " points of damage! (Energy left: " << energyPoints << ")" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (hitPoints <= 0 || energyPoints <= 0 || (unsigned int)amount >= hitPoints) {
        hitPoints = 0;
        std::cout << name << " is dead" << std::endl;
    } else {
        hitPoints -= amount;
        std::cout << "ClapTrap " << name << " took " << amount
                  << " damage! (HP left: " << hitPoints << ")" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (hitPoints <= 0 || energyPoints <= 0) {
        std::cout << "ClapTrap " << name << " cannot repair! Not enough energy or hit points." << std::endl;
        return;
    }
    hitPoints += amount;
    energyPoints--;
    std::cout << "ClapTrap " << name << " repairs itself for " << amount
              << " HP! (HP: " << hitPoints << ", Energy left: " << energyPoints << ")" << std::endl;
}
/*attack()	Deals damage to a target	-1 energy
takeDamage()	Reduces HP when hit	Free
beRepaired()	Heals HP	-1 energy*/