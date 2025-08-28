/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 20:01:10 by imqandyl          #+#    #+#             */
/*   Updated: 2025/08/26 22:57:31 by imqandyl         ###   ########.fr       */
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
    
int main( void ) {

    And obj1(42), obj2(84);
    swap(obj1, obj2);
    // std::cout << "obj1 = " << obj1.getValue()  << std::endl;

    return 0;
}