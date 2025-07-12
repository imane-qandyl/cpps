/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 20:01:22 by imqandyl          #+#    #+#             */
/*   Updated: 2025/07/12 20:01:23 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "iostream"

template <typename T2>
void printString(T2 print) {
    std::cout << print << std::endl;
}

template <typename T1, typename F>
void iter(T1 *address, size_t length, F printString)
{
    for (size_t i = 0; i < length; i++)
        printString(address[i]);
};
//can print ANY type.
//Templates are NOT functions - they're instructions to create functions
