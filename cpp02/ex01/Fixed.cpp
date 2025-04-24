/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:38:15 by imqandyl          #+#    #+#             */
/*   Updated: 2025/04/24 17:24:15 by imqandyl         ###   ########.fr       */
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
Fixed::Fixed(const int n) {
    std::cout << "Int constructor called" << std::endl;
    this->fixedPoint = n << fractionalBits; //10 × 2^8
}

// Float constructor
Fixed::Fixed(const float f) {
    std::cout << "Float constructor called" << std::endl;
    this->fixedPoint = roundf(f * (1 << fractionalBits)); // 10860 
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// Convert fixed point to float
float Fixed::toFloat(void) const {
    return (float)this->fixedPoint / (1 << fractionalBits); ///2^8 /// 10860 / 256 = 42.421875
}

// Convert fixed point to int
int Fixed::toInt(void) const {
    return this->fixedPoint >> fractionalBits; //shifts right by 8 bits
}
int Fixed::getRawBits(void) const 
{
    return (this->fixedPoint);
}

void Fixed::setRawBits(int const raw) 
{
    this->fixedPoint = raw;
}
Fixed& Fixed::operator=(const Fixed &copy) 
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy) {
        this->fixedPoint = copy.getRawBits();
    }
    return *this;
}
// << operator overload Lets you print the object as a float
std::ostream& operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}
