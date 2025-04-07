/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:55:01 by taha              #+#    #+#             */
/*   Updated: 2025/02/05 17:07:16 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int main(int argc, char **argv){
	if (argc != 4)
	{
		std::cout << "error: bad argument." << std::endl;
		return 1;
	}
	std::string fileName = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	Replace program(fileName, s1, s2);
	return program.stringMani();
}