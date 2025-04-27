/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 07:12:04 by imqandyl          #+#    #+#             */
/*   Updated: 2025/04/27 07:58:23 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    this->fixedPoint = 0;
}

Fixed::Fixed(const Fixed &fixedPoint)
{
    *this = fixedPoint;
}
Fixed::Fixed(const int n) {
    this->fixedPoint = n << fractionalBits; //10 × 2^8
}

// Float constructor
Fixed::Fixed(const float f) {
    this->fixedPoint = roundf(f * (1 << fractionalBits)); //Fixed a(42.42f);// 10860 
}

Fixed::~Fixed() {
}
    float Fixed::toFloat(void) const {
        return (float)this->fixedPoint / (1 << fractionalBits); ///2^8 /// 10860 / 256 = 42.421875
}

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
    if (this != &copy)
        this->fixedPoint = copy.getRawBits();
    return *this;
}
// << operator overload Lets you print the object as a float
//C++ doesn't know how to print Fixed objects. Fixed a(42.42f); print 42.4219(10860/256) instead 10860 
std::ostream& operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}

bool Fixed::operator>(const Fixed &copy) const {return this->fixedPoint > copy.fixedPoint;}

bool Fixed::operator<(const Fixed &copy) const {return this->fixedPoint < copy.fixedPoint;}

bool Fixed::operator>=(const Fixed &copy) const {return this->fixedPoint >= copy.fixedPoint;}

bool Fixed::operator<=(const Fixed &copy) const {return this->fixedPoint <= copy.fixedPoint;}

bool Fixed::operator==(const Fixed &copy) const {return this->fixedPoint == copy.fixedPoint;}

bool Fixed::operator!=(const Fixed &copy) const {return this->fixedPoint != copy.fixedPoint;}


Fixed Fixed::operator+(const Fixed& copy) const {
    return Fixed(this->toFloat() + copy.toFloat());
}

Fixed Fixed::operator-(const Fixed& copy) const {
    return Fixed(this->toFloat() - copy.toFloat());
}

Fixed Fixed::operator*(const Fixed& copy) const {
    return Fixed(this->toFloat() * copy.toFloat());
}

Fixed Fixed::operator/(const Fixed& copy) const {
    if (copy.fixedPoint == 0)
		throw std::runtime_error("Division by zero");
    return Fixed(this->toFloat() / copy.toFloat());
}

// Pre-increment (++a)
Fixed& Fixed::operator++() {
    this->fixedPoint++;
    return *this;
}

// Post-increment (a++)
Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    this->fixedPoint++;
    return temp;
}

// Pre-decrement (--a)
Fixed& Fixed::operator--() {
    this->fixedPoint--;
    return *this;
}

// Post-decrement (a--)
Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    this->fixedPoint--;
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}
