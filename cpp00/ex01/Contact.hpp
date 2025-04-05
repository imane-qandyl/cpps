/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 18:14:19 by imqandyl          #+#    #+#             */
/*   Updated: 2025/04/05 12:42:24 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>

class Contact 
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;

	public:
		// Setters
		void setContact(std::string firstName, std::string lastName,
			std::string nickname, std::string darkestSecret, std::string phoneNumber);
		void setFirstName(const std::string& fn);
		void setLastName(const std::string& ln);
		void setNickName(const std::string& nn);
		void setDarkestSecret(const std::string& secret);
		int  SetPhoneNumber(std::string phoneNumber); // validates and sets
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickName() const;
		std::string getPhoneNumber() const;
		std::string getDarkestSecret() const;
		bool isValid() const;
};

#endif
