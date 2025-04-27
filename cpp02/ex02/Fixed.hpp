/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 07:07:25 by imqandyl          #+#    #+#             */
/*   Updated: 2025/04/27 07:15:45 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
	private:
		int fixedPoint;
		static const int fractionalBits = 8;
	public:
		Fixed();
        Fixed(const int n);
        Fixed(const float f);
		~Fixed();
		Fixed(const Fixed &fixedPoint);// Copy constructor
		Fixed	&operator=(const Fixed &copy);
		int		getRawBits(void)const;
		void	setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
        
            // Comparison Operators
        bool operator>(const Fixed &copy) const;
        bool operator<(const Fixed &copy) const;
        bool operator>=(const Fixed &copy) const;
        bool operator<=(const Fixed &copy) const;
        bool operator==(const Fixed &copy) const;
        bool operator!=(const Fixed &copy) const;
        // Arithmetic Operatord &copy
        Fixed operator+(const Fixed &copy) const;
        Fixed operator-(const Fixed &copy) const;
        Fixed operator*(const Fixed &copy) const;
        Fixed operator/(const Fixed &copy) const;

        // Increment / Decrement Operators
        Fixed& operator++();    // pre-increment
        Fixed operator++(int);  // post-increment
        Fixed& operator--();    // pre-decrement
        Fixed operator--(int);  // post-decrement

        // Static min/max
        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);

};
std::ostream& operator<<(std::ostream &out, const Fixed &fixed);

#endif