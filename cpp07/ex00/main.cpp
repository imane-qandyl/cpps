/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 20:01:10 by imqandyl          #+#    #+#             */
/*   Updated: 2025/08/31 18:45:23 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"


class And {
    public:
        And( void ) : _a(0) {}
        And(And const & src) { 
            std::cout << "Copy constructor called" << std::endl;
            *this = src; }
        And &operator=( And const & rhs) { if (this != &rhs) { this->_a = rhs._a; } return *this; }
        And( int a) : _a(a) {}
        ~And( void ) {}
        int getValue() const { return _a; }
    private:
        int _a;
};
    
int main() 
{
    std::cout << "----------------- Main 1 -----------------" << std::endl;
    
    And obj1(42), obj2(84);
    swap(obj1, obj2);
    std::cout << "obj1 = " << obj1.getValue()  << std::endl;
    
    std::cout << "----------------- Main 2 -----------------" << std::endl;
	{
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
}