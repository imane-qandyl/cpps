/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 19:02:07 by imqandyl          #+#    #+#             */
/*   Updated: 2025/04/09 19:06:42 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int numZombies = 5;
	Zombie* horde = zombieHorde(numZombies, "HordeZombie");
    for (int i = 0; i < numZombies; i++) {
        horde[i].announce();
    }
	delete[] horde;
}