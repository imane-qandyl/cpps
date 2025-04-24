/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:29:24 by imqandyl          #+#    #+#             */
/*   Updated: 2025/04/24 11:38:40 by imqandyl         ###   ########.fr       */
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

};
std::ostream& operator<<(std::ostream &out, const Fixed &fixed);

#endif