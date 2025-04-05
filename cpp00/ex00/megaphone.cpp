/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:00:22 by imqandyl          #+#    #+#             */
/*   Updated: 2025/04/04 17:18:03 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

void str_to_upper(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (islower(str[i]))
			std::cout << (char)toupper(str[i]);
		else
			std::cout << str[i];
		i++;
	}
}

int main(int argc, char **argv)
{
	char **args;

	args = ++argv;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (*args != NULL)
			{
				str_to_upper(*args);
				args++;
			}
		std::cout << std::endl;
	}
	return (0);
}