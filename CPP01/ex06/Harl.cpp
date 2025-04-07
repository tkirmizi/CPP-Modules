/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirmizi <tkirmizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:37:01 by taha              #+#    #+#             */
/*   Updated: 2025/02/06 11:24:17 by tkirmizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void){std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;}
void Harl::info(void){std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;}
void Harl::warning(void){std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;}
void Harl::error(void){std::cout << "this is unacceptable! I want to speak to the manager now." << std::endl;}

void Harl::complain(Levels level) 
{
	switch (level)
	{
		case DEBUG:
			writeAbove(0);
			break;
		case INFO:
			writeAbove(1);
			break;
		case WARNING:
			writeAbove(2);
			break;
		case ERROR:
			writeAbove(3);
			break;
		case INVALID:
			std::cout << "invalid"<< std::endl;
			break;

	}
}

Harl::Harl() // constructor
{
	functionPtr[0] = &Harl::debug; functionPtr[1] = &Harl::info;
	functionPtr[2] = &Harl::warning; functionPtr[3] = &Harl::error;
}

void Harl::writeAbove(int i){
	for (; i < 4 ; i++)
		(this->*functionPtr[i])();
}

