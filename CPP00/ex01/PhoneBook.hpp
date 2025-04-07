/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirmizi <tkirmizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:29:15 by taha              #+#    #+#             */
/*   Updated: 2025/01/31 15:26:00 by tkirmizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>
#include "Contact.hpp"

class PhoneBook{
	private:
		Contact	contactObj[8];
		int		count;
		int		lastIndex;
	public:
		PhoneBook():count(0),lastIndex(0){};
		Contact copyCont(Contact copiedCont);
		void doAdd();
		void doSearch();
		std::string lengthChecker(std::string str);
		~PhoneBook(){};
};

#endif