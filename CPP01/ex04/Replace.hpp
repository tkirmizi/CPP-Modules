/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:42:48 by taha              #+#    #+#             */
/*   Updated: 2025/02/05 15:46:55 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <string>
#include <fstream>
#include <iostream>


class Replace{
	private:
		std::string		filename;
		std::string		s1;
		std::string		s2;
		std::ifstream	inFile;
		std::ofstream	outFile;
		std::string		line;
	public:
		Replace(std::string newFilename,std::string newS1,std::string newS2);
		std::string	getfileName();
		std::string	getS1();
		std::string	getS2();
		bool		isFileExist(void); // gonna handle to quit from program
		int			stringMani(void); // line'i manupile edip oyle yazdiracak
		bool		stringCheck(void);
};

#endif