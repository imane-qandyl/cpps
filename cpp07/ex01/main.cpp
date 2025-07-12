/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 20:01:25 by imqandyl          #+#    #+#             */
/*   Updated: 2025/07/12 20:01:26 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main() {
    std::cout << "Printing integers: " << std::endl;
    int numbers[] = {1, 2, 3, 4, 5};
    size_t length = sizeof(numbers) / sizeof(numbers[0]);
    ::iter(numbers, length, printString<int>);

    std::string words[] = {"Hello", "World", "Template", "Functions"};
    size_t wordLength = sizeof(words) / sizeof(words[0]);
    std::cout << "Printing words: " << std::endl;
    ::iter(words, wordLength, printString<std::string>);

    double doubnumbers[] = {11.1, 22.2, 33.3, 44.4, 55.5};
    size_t doublelength = sizeof(doubnumbers) / sizeof(doubnumbers[0]);
    std::cout << "Printing doubles: " << std::endl;
    ::iter(doubnumbers, doublelength, printString<double>);
    return 0;
}