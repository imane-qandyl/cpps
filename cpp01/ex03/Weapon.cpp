/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 07:52:33 by imqandyl          #+#    #+#             */
/*   Updated: 2025/04/11 09:04:03 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string Type) :type(Type)
{
	return ;
}

Weapon::~Weapon(void)
{
	return ;
}

std::string const Weapon::getType(void)
{
	return (this->type);
}

void Weapon::setType(std::string Type)
{
	this->type = Type;
}