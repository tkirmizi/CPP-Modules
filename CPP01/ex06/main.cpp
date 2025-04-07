/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:02:12 by taha              #+#    #+#             */
/*   Updated: 2025/02/05 19:09:47 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Harl.hpp"


Levels getLevel(std::string levelStr){
	if (levelStr == "DEBUG") return DEBUG;
	if (levelStr == "INFO") return INFO;
	if (levelStr == "WARNING") return WARNING;
	if (levelStr == "ERROR") return ERROR;
	return INVALID;
}

int main(int argc, char **argv){
	Harl harlObj;

	if (argc != 2)
	{
		std::cout << "error: bad argument" << std::endl;
		return 1;
	}
	Levels level;
	std::string levelStr = argv[1];
	level = getLevel(levelStr);
	if (level < 0 || level > 3)
	{
		std::cout << "error: bad argument" << std::endl;
		return 1;
	}
	harlObj.complain(level);
}