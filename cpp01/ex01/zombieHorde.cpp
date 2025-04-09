/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:48:26 by imqandyl          #+#    #+#             */
/*   Updated: 2025/04/09 19:05:31 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//create an array of zombies dynamically on the heap
#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    if (N <= 0)
        return nullptr;

    Zombie* horde = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        horde[i].setName(name);
    }
    return horde;
}