/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 20:04:18 by imqandyl          #+#    #+#             */
/*   Updated: 2025/07/29 14:19:50 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(){}
Serializer::~Serializer(){}
Serializer::Serializer(const Serializer &copy){*this = copy;}
Serializer &Serializer::operator=(const Serializer &copy){(void)copy; return (*this);}
uintptr_t Serializer::serialize(Data *ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}
Data *Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data *>(raw);
}
/*serialize(Data* ptr) to convert a pointer to Data into a uintptr_t.

deserialize(uintptr_t raw) to convert a uintptr_t back into a pointer to Data.*/

/*
    uintptr_t is a data type in C++ that is an unsigned int but it's upper limit is guaranteed to store any pointer value.
*/
