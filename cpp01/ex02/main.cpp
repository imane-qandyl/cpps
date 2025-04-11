/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 07:27:36 by imqandyl          #+#    #+#             */
/*   Updated: 2025/04/11 07:35:47 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{

    std::string brain = "HI THIS IS BRAIN";

    std::string *stringPTR = &brain;     
    std::string &stringREF = brain;      

    std::cout << "Memory address of the string variable: " << &brain << std::endl;
    std::cout << "Memory address held by stringPTR:     " << stringPTR << std::endl;
    std::cout << "Memory address held by stringREF:     " << &stringREF << std::endl;

    // Printing values
    std::cout << "Value of the string variable:         " << brain << std::endl;
    std::cout << "Value pointed to by stringPTR:        " << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF:        " << stringREF << std::endl;

    return 0;
}