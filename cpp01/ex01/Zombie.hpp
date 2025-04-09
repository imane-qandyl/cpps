/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:53:29 by imqandyl          #+#    #+#             */
/*   Updated: 2025/04/09 19:01:52 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

class Zombie
{
	private:
		std::string name;
	public:
		Zombie();
        Zombie(std::string name);
		~Zombie(void);
		void	announce(void) const;
		void	setName(std::string name);
};
Zombie* zombieHorde( int N, std::string name );

#endif

