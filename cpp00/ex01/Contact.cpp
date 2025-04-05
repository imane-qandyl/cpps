/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 08:20:23 by imqandyl          #+#    #+#             */
/*   Updated: 2025/04/05 14:25:43 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void Contact::setFirstName(const std::string& fn) {
	firstName = fn;
}

void Contact::setLastName(const std::string& ln) {
	lastName = ln;
}

void Contact::setNickName(const std::string& nn) {
	nickname = nn;
}

void Contact::setDarkestSecret(const std::string& secret) {
	darkestSecret = secret;
}
void	PhoneBook::SetIndex(int Setindex)
{
	index = Setindex;
}
int Contact::SetPhoneNumber(std::string pn)
{
	int i = 0;
	while (pn[i])
	{
		if (pn[i] < '0' || pn[i] > '9')
			return 0;
		i++;
	}
	phoneNumber = pn;
	return 1;
}
std::string Contact::getFirstName() const { return firstName; }
std::string Contact::getLastName() const { return lastName; }
std::string Contact::getNickName() const { return nickname; }
std::string Contact::getPhoneNumber() const { return phoneNumber; }
std::string Contact::getDarkestSecret() const { return darkestSecret; }

bool Contact::isValid() const {
	return !firstName.empty() && !lastName.empty() && !nickname.empty() &&
		   !phoneNumber.empty() && !darkestSecret.empty();
}
int 	PhoneBook::GetIndex()
{
	return (index);
}