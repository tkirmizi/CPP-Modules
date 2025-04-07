/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 19:17:48 by taha              #+#    #+#             */
/*   Updated: 2025/03/01 19:20:38 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string str)
{
	inFileData.open("data.csv");
	inFileInput.open(str);

	if (!inFileData.is_open())
		{ std::cerr << " data.cvs couldnt open\n"; return; }
	if (!inFileInput.is_open())
		{ std::cout << "input.txt couldnt open\n"; return; }
	while (getline(inFileData, line))
	{
		if (line.find("date") != std::string::npos)
			continue;
		dataMap.insert(std::pair<std::string, double>(line.substr(0, (line.find(','))), std::stod(line.substr(line.find(',')+1))));
	}
	line.clear();
	getline(inFileInput, line);
	while(getline(inFileInput, line))
	{
		// date check
		std::string	date;
		std::string	value;
		if (line.find('|') != std::string::npos)
		{
			date = line.substr(0, line.find('|')-1);
			value = line.substr(line.find('|')+2);
		}
		else
		{
			date = line.substr(0, line.find('|')-1);
			value = "bad input";
		}

		if (date != "bad input")
		{
			if ((date.size() != 10 || date[4] != '-' || date[7] != '-'))
				value = "bad input";
			for (size_t i = 0; i < 4; i++)
			{
				if (!isdigit(date[i]))
					value = "bad input";
			}
			for (size_t i = 5; i < 7; i++)
			{
				if (!isdigit(date[i]))
					value = "bad input";
			}
			for (size_t i = 8; i < 10; i++)
			{
				if (!isdigit(date[i]))
					value = "bad input";
			}
			if (date[5] >= '2' || (date[5] == '1' && date[6] > '2'))
				value = "bad input";
			if (date[8] > '3' || (date[8] == '3' && date[9] > '1'))
				value = "bad input";
		}
		// date check end

		if (value == "bad input")
			std::cout << "Error: bad input => " << date << std::endl;

	// value check
		else
		{
			double dvalue;
			try 
			{
				dvalue = std::stod(value);
				if (dvalue <= 0)
				{ 
					std::cout << "Error: not a positive number." << std::endl; 
					continue;
				}
				if (dvalue > 1000 || dvalue > INT_MAX)
				{
					std::cout << "Error: too large a number." << std::endl;
					continue;
				}
				auto it = dataMap.find(date);
				if (it == dataMap.end())
				{
					it = dataMap.lower_bound(date);
					if (it != dataMap.begin() && it != dataMap.end() && it->first > date)
						--it;
					else if (it == dataMap.end() && !dataMap.empty())
					{
						it = dataMap.end();
						--it;
					}
					else if (dataMap.empty() || it == dataMap.end())
					{
						std::cout << "Error: no valid date found in database" << std::endl;
						continue;
					}
				}
				double exchangeRate = it->second;
				double result = dvalue * exchangeRate;
				std::cout << date << " => " << dvalue << " = " << std::fixed << std::setprecision(countDecimalPlaces(result)) << result << std::endl;
			}
			catch(const std::invalid_argument& e)
			{ std::cout << "Error: bad input => " << value << std::endl; }
			catch(const std::out_of_range& e)
			{ std::cout << "Error: too large a number." << std::endl; }
		}
	}
}


BitcoinExchange::~BitcoinExchange()
{
	if (this->inFileData.is_open()) {
		this->inFileData.close();
	}
	if (this->inFileInput.is_open()) {
		this->inFileInput.close();
	}
}
BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
	this->dataMap = src.dataMap;
	this->inputMap = src.inputMap;
	this->line = src.line;
}
BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &src)
{
	if (this != &src)
	{
		this->dataMap.clear();
		this->inputMap.clear();
		this->line.clear();

		if (this->inFileData.is_open())
			this->inFileData.close();

		if (this->inFileInput.is_open())
			this->inFileInput.close();

		this->dataMap = src.dataMap;
		this->inputMap = src.inputMap;
		this->line = src.line;
	}
	return *this;
}


int BitcoinExchange::countDecimalPlaces(double num)
{
	int count = 0;
	while (std::fmod(num, 1) != 0)
	{
		num *= 10;
		count++;
	}
	return count;
}