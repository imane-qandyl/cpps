/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 09:20:40 by imqandyl          #+#    #+#             */
/*   Updated: 2025/04/09 11:09:53 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main() {
	PhoneBook phonebook;
	std::string command;
	int i = 0;
	std::cout << "\033[1;36mWelcome to Your Awesome PhoneBook 📞\033[0m" << std::endl;
	while (true) {
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::cin >> command;
		
		if(std::cin.eof() || command == "EXIT")
		{	
			std::cout << "\033[1;35mExiting PhoneBook... Goodbye!\033[0m" << std::endl;
			break;
		}
		else if (command == "ADD")
			phonebook.addContact();
		else if (command == "SEARCH")
			phonebook.searchContacts(command);
		else
			std::cout << "\033[1;31mInvalid command. Please try again.\033[0m" << std::endl;
	}
}
