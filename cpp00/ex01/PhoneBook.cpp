/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 09:04:40 by imqandyl          #+#    #+#             */
/*   Updated: 2025/04/05 14:57:36 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void PhoneBook::addContact() {
	std::string input;
	Contact newContact;

	std::cout << "Enter First Name: ";
	std::getline(std::cin >> std::ws, input);
	if (input.empty()) return;
	newContact.setFirstName(input);

	std::cout << "Enter Last Name: ";
	std::getline(std::cin >> std::ws, input);
	if (input.empty()) return;
	newContact.setLastName(input);

	std::cout << "Enter Nickname: ";
	std::getline(std::cin >> std::ws, input);
	if (input.empty()) return;
	newContact.setNickName(input);

	std::cout << "Enter Darkest Secret: ";
	std::getline(std::cin >> std::ws, input);
	if (input.empty()) return;
	newContact.setDarkestSecret(input);

	// Validate phone number
	while (true) {
		std::cout << "Enter Phone Number: ";
		std::getline(std::cin >> std::ws, input);
		if (input == "EXIT")
			return;
		if (newContact.SetPhoneNumber(input))
			break;
		std::cout << "\033[0;31mInvalid phone number. Digits only.\033[0;0m" << std::endl;
	}

	// Store contact at next available/replaceable index
	int indexToStore;
	if (contactCount < 8)
		indexToStore = contactCount;
	else {
		indexToStore = oldestIndex;
		oldestIndex = (oldestIndex + 1) % 8; //it wraps back to 0.
	}

	contacts[indexToStore] = newContact;

	if (contactCount < 8)
		contactCount++;

	std::cout << "\033[0;32mContact added successfully!\033[0;0m" << std::endl;
}

std::string formatText(std::string str, int width) {
    if (str.length() > width)
		return str.substr(0, width - 1) + ".";  // Cut and add dot (e.g., "LongFirstname" → "LongFirstn.")
	else if (str.length() < width)
		return std::string(width - str.length(), ' ') + str;  // Add spaces before
	else
		return str;  // Exact fit
}
void PhoneBook::displayContact(int index)
{
	if (index < 0 || index >= contactCount)
	{
		std::cout << "Invalid contact index." << std::endl;
		return;
	}
//Print the table headers
	std::cout << std::setw(10) << "Index" << "|"
	          << std::setw(10) << "FirstName" << "|"
	          << std::setw(10) << "LastName" << "|"
	          << std::setw(10) << "NickName" << std::endl;
//Print the contact data
	std::cout << std::setw(10) << index << "|"
	          << std::setw(10) << formatText(contacts[index].getFirstName(), 10) << "|"
	          << std::setw(10) << formatText(contacts[index].getLastName(), 10) << "|"
	          << std::setw(10) << formatText(contacts[index].getNickName(), 10) << std::endl;
}

void	PhoneBook::searchContacts(std::string command)
{
	int i = -1;
	
	std::cout << "Enter the contact index: ";
	std::getline(std::cin >> std::ws, command);

	if (command == "EXIT" || std::cin.eof())
	return;

	// Check that it's all digits
	for (size_t i = 0; i < command.length(); i++) {
		if (!isdigit(command[i])) {
			std::cout << "Index should be a number.\n";
			return;
		}
	}

	int index = std::atoi(command.c_str());
	if (index < 0 || index >= contactCount) {
		std::cout << "Index must be between 0 and " << contactCount - 1 << ".\n";
		return;
	}
	displayContact(index);
}