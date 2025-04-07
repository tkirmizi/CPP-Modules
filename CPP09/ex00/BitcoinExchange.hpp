/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 19:04:10 by taha              #+#    #+#             */
/*   Updated: 2025/03/01 19:18:07 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>
#include <fstream>

class BitcoinExchange
{
	private:
		std::multimap <std::string, double> dataMap;
		std::multimap <std::string, double> inputMap;
		std::ifstream inFileData;
		std::ifstream inFileInput;
		std::string line;
	public:
		BitcoinExchange(std::string str);
		~BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &src);
		BitcoinExchange &operator=(BitcoinExchange const &src);
		int countDecimalPlaces(double num);

};