/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirmizi <tkirmizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:12:49 by tkirmizi          #+#    #+#             */
/*   Updated: 2025/01/31 15:25:55 by tkirmizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

std::string PhoneBook::lengthChecker(std::string str)
{
	std::string tempStr;
	if (str.length() > 10)
	{
		tempStr = str.substr(0,9);
		tempStr += '.';
		return tempStr;
	}
	else
		return str;
}

Contact PhoneBook::copyCont(Contact copiedCont)
{
	Contact newCont;
	newCont.setFirstName(copiedCont.getFirstName());
	newCont.setLastName(copiedCont.getLastName());
	newCont.setNickName(copiedCont.getNickName());
	newCont.setPhoneNumber(copiedCont.getPhoneNumber());
	newCont.setDarkestSecret(copiedCont.getDarkestSecret());
	return newCont;
}

void PhoneBook::doAdd(){
		std::string input;
		Contact newContact;
		
		std::cout << "Please provide inputs\nFirst Name = ";
		std::getline(std::cin, input);
		if (input != "")
			newContact.setFirstName(input);
		else{
			std::cout << "error: empty input" << std::endl;
			return;
		}

		std::cout << "last name = ";
		std::getline(std::cin, input);
		if (input != "")
			newContact.setLastName(input);
		else{
			std::cout << "error: empty input" << std::endl;
			return;
		}

		std::cout << "nick name = ";
		std::getline(std::cin, input);
		if (input != "")
			newContact.setNickName(input);
		else{
			std::cout << "error: empty input" << std::endl;
			return;
		}

		std::cout << "phone number = ";
		std::getline(std::cin, input);
		if (input != "")
			newContact.setPhoneNumber(input);
		else{
			std::cout << "error: empty input" << std::endl;
			return;
		}

		std::cout << "darkest secret = ";
		std::getline(std::cin, input);
		if (input != "")
			newContact.setDarkestSecret(input);
		else{
			std::cout << "error: empty input" << std::endl;
			return;
		}

		this->contactObj[this->lastIndex] = newContact;
		this->lastIndex = (this->lastIndex+1)%8;
		if (this->count < 8)
			++this->count;
	}

void	PhoneBook::doSearch(){
	std::string input;
	int tempInt;

	if (this->count == 0)
	{
		std::cout << "Empty phonebook" << std::endl;
		return;
	}

	std::cout
	<< std::setw(10) << std::right << "index" << "|" 
	<< std::setw(10) << std::right << "first name" << "|"
	<< std::setw(10) << std::right << "last name" << "|"
	<< std::setw(10) << std::right << "nick name" << "|"
	<< std::endl;
	for (int i = 0; i < this->count; i++)
	{
		std::cout << 
		std::setw(10) << std::right << i << "|"
		<< std::setw(10) << std::right << lengthChecker(this->contactObj[i].getFirstName()) << "|"
		<< std::setw(10) << std::right << lengthChecker(this->contactObj[i].getLastName()) << "|"
		<< std::setw(10) << std::right << lengthChecker(this->contactObj[i].getNickName()) << "|"
		<< std::endl;
	}

	std::cout << "enter an index to search" << std::endl;
	std::getline(std::cin, input);
	try
	{
		if (input.empty() || input.find_first_not_of("0123456789") != std::string::npos)
			throw ("error: empty or non-digit input");
		tempInt = std::stoi(input);
		if (tempInt >= this->count || tempInt < 0)
			throw std::out_of_range("error: index out of range");
		std::cout
		<< this->contactObj[tempInt].getFirstName() << std::endl 
		<< this->contactObj[tempInt].getLastName() << std::endl 
		<< this->contactObj[tempInt].getNickName() << std::endl 
		<< this->contactObj[tempInt].getPhoneNumber() << std::endl 
		<< this->contactObj[tempInt].getDarkestSecret() << std::endl 
		<< std::endl;
	}
		catch(...){std::cout << "error: bad index" << std::endl;}
}