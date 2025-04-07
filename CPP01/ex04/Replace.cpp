/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:43:11 by taha              #+#    #+#             */
/*   Updated: 2025/02/05 15:46:28 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace(std::string newFilename,std::string newS1,std::string newS2): filename(newFilename), s1(newS1), s2(newS2) {};

std::string	Replace::getfileName(){return filename;}
std::string	Replace::getS1(){return s1;}
std::string	Replace::getS2(){return s2;}

bool Replace::isFileExist(void) // gonna handle to quit from program
{
	inFile.open(filename);
	if (!inFile.is_open()){
		std::cout << "error: file doesnt exist or readable" << std::endl;
		return false;
	} else
	{
		outFile.open(filename + ".replace");
		if (!outFile.is_open()){
			std::cout << "error: file doesnt exist or readable" << std::endl;
			return false;
		}
	}
	return true;
}
int Replace::stringMani(void) // line'i manupile edip oyle yazdiracak
{
	size_t pos;
	if (isFileExist() == false)
	{
		inFile.close(); outFile.close();
		return 1;
	}
	if (stringCheck() == false)
	{
		inFile.close(); outFile.close();
		return 1;
	}
	while (std::getline(inFile, line))
	{	
		while (line.find(s1) != std::string::npos)
		{
			pos = line.find(s1);
			line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
		}
		outFile << line << std::endl;
	}
	inFile.close(); outFile.close();
	return 0;
}
bool Replace::stringCheck(void){
	if (s1.empty() || s2.empty())
	{
		std::cout << "error: s1 or s2 is empty." << std::endl;
		return false;
	}
	else if (s1 == s2)
	{
		std::cout << "error: s1 and s2 are identical." << std::endl;
		return false;
	}
	return true;
}