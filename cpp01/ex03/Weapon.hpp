/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 07:52:14 by imqandyl          #+#    #+#             */
/*   Updated: 2025/04/11 09:05:53 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <iomanip>
#include <string>


class Weapon
{
    private:
        std::string type;
    public:
        Weapon(std::string Type);
        ~Weapon();

		std::string const getType();
        void setType(std::string Type);
};

#endif