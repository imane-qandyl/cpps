/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 18:18:42 by imqandyl          #+#    #+#             */
/*   Updated: 2025/04/05 14:57:55 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

class PhoneBook 
{
	private:
		Contact contacts[8];
		int contactCount;
		int oldestIndex;
		int index;

	public:
		//PhoneBook();
		void addContact();
		void searchContacts(std::string command);
		void displayContact(int index);
		void SetIndex(int Setindex);
		int	GetIndex();
};

#endif
