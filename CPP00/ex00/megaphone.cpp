/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirmizi <tkirmizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:13:18 by tkirmizi          #+#    #+#             */
/*   Updated: 2025/02/04 12:07:30 by tkirmizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv){
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	else
	{
		for (int i = 1; i < argc ; i++)
			for (auto c : std::string(argv[i]))
			{
				if (c >= 'a' && c <= 'z')
				{
					char newC = c -= 32;
					std::cout << newC;
				}
				else
					std::cout << c;
			}
			std::cout << std::endl;
	}
}


/*
./megaphone "shhhhh... I think the students are asleep..."
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...

./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.

./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *
$>
*/