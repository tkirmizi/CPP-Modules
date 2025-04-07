/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:42:15 by taha              #+#    #+#             */
/*   Updated: 2025/03/05 12:56:04 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 3)
	{ std::cerr << "Error: arguments must be at least 2\n"; return 1; }
	
	PmergeMe sorter;

	// Parsing
	try
	{ sorter.isNbr(argv, argc); }
	catch(const std::exception &e)
	{ std::cerr << e.what() << std::endl; return 1; }
	
	size_t totalLen = 0;
	for (int i = 1; i < argc; i++)
		totalLen += std::strlen(argv[i]) + 1;
	char *array = new char[totalLen + 1];
	array = sorter.duplicateCheck(argv, argc, array);

	// Sorting
	sorter.vecSorting();
	sorter.deqSorting();
	
	delete[] array;
	return 0;
}