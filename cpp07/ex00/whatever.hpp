/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 20:01:14 by imqandyl          #+#    #+#             */
/*   Updated: 2025/08/31 18:23:48 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}  

template <typename T>
T min(T a, T b) {
  return (a < b) ? a : b;
}  

template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}
// "T can be any type"
// Works for int, double, string, and ANY type
//max(5, 10.0);         // ERROR! Can't mix types without explicit casting