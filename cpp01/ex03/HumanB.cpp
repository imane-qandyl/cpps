/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 07:52:03 by imqandyl          #+#    #+#             */
/*   Updated: 2025/04/11 09:03:16 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) :name(name)
{
	return ;
}

HumanB::~HumanB(void)
{

}

void HumanB::attack(void)
{
	std::cout << this->name << " attacks with their " << (*this->weapon).getType() << std::endl;
}

void HumanB::setWeapon(Weapon &Weapon)
{
	this->weapon = &Weapon;
}