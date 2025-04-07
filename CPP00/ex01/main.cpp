/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirmizi <tkirmizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:45:29 by taha              #+#    #+#             */
/*   Updated: 2025/01/31 15:26:44 by tkirmizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int main(int argc, char **argv)
{
	PhoneBook phoneObj;
	std::string input;
	(void)argc;
	(void)argv;

	while (1)
	{
		std::getline(std::cin, input);
		if (input == "ADD")
		{
			phoneObj.doAdd();
		}
		else if (input == "SEARCH")
		{
			phoneObj.doSearch();
		}
		else if (input ==  "EXIT")
		{
			std::cout << "you typed exit" << std::endl;;
			exit(0);
		}
		else
			std::cout << "error: bad argument" << std::endl;;
	}
}
