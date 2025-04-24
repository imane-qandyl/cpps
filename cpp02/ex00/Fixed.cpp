/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 08:04:36 by imqandyl          #+#    #+#             */
/*   Updated: 2025/04/24 11:24:11 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->fixedPoint = 0;
}

Fixed::Fixed(const Fixed &fixedPoint)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = fixedPoint;
}

Fixed& Fixed::operator=(const Fixed &copy) 
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy) {
        this->fixedPoint = copy.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const 
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->fixedPoint);
}

void Fixed::setRawBits(int const raw) 
{
    std::cout << "setRawBits member function called" << std::endl;
    this->fixedPoint = raw;
}
//copy object data without making a new object