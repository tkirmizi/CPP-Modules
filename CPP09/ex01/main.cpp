/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 20:19:17 by taha              #+#    #+#             */
/*   Updated: 2025/03/05 13:08:32 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: must be 2 argument!" << std::endl;
		return 1;
	}

	RPN rpnCalculator;

	try
		{ rpnCalculator.parseInput(argv[1]); }
	catch(const std::exception &e)
		{ std::cerr << e.what(); return 1 ; }

	for (int i = 0; i < rpnCalculator.getCount() ; i++)
	{
		if ((rpnCalculator.getArg())[i].size() != 1)
			{ std::cerr << "Error\n"; return 1; }
	}
		
	try
		{ rpnCalculator.Process(); }
	catch(const std::exception &e)
		{ std::cerr << e.what(); return 1 ; }

	return 0;
}