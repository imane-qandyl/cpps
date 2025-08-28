/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 20:01:22 by imqandyl          #+#    #+#             */
/*   Updated: 2025/08/28 23:23:41 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "iostream"
#include "limits" 


template <typename T1,  size_t N>
void    iter(T1 (&address)[N], size_t size, void (*function) (T1 const&))
{
	if (N < size)
		return (std::cerr << "Invalid size" << std::endl, void());
	for (size_t	i = 0; i < size; i++)
        function(address[i]);
};

template <typename T>
void print(const T& print) {
    std::cout << print << std::endl;
}

//can print ANY type.
//Templates are NOT functions - they're instructions to create functions
