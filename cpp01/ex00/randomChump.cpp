/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:00:14 by imqandyl          #+#    #+#             */
/*   Updated: 2025/04/09 16:29:22 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
//a temporary Zombie object
void	randomChump(std::string name)
{
    Zombie s_Zombie(name);
    s_Zombie.announce();
}