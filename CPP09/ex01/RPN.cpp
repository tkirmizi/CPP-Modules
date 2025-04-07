/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:18:31 by taha              #+#    #+#             */
/*   Updated: 2025/03/03 14:31:45 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::~RPN(){}
RPN::RPN(const RPN &src)
{
	this->count = src.count;
	for (int i = 0; i < MAX_TOKENS; i++)
		{ this->arg[i] = src.arg[i]; }
	this->rpnStack = src.rpnStack;
}

RPN &RPN::operator=(const RPN &src)
{
	if (this != &src)
	{
		this->count = src.count;
		for (int i = 0; i < MAX_TOKENS; i++)
		{
			this->arg[i] = src.arg[i];
		}
		this->rpnStack = src.rpnStack;
	}
	return *this;
}


const char *RPN::moreThanTenNbr::what() const noexcept
	{ return "Error: There are more than 10 passed number arguments"; }

const char *RPN::invalidArgument::what() const noexcept
	{ return "Error: Invalid argument "; }

RPN::RPN() : count(0) {}


bool RPN::parseInput(const std::string &input)
{
	count = 0;
	std::string currentToken = "";

	for (size_t i = 0; i < input.length(); i++)
	{
		if (input[i] != ' ')
		{
			currentToken += input[i];
			if (i == input.length() - 1 || input[i + 1] == ' ')
			{
				if (count < MAX_TOKENS && !currentToken.empty())
				{
					arg[count] = currentToken;
					count++;
					currentToken = "";
				}
			}
		}
	}
	return count > 0;
}

bool RPN::isOperator(const std::string &str)
	{ return (str == "+" || str == "-" || str == "*" || str == "/"); }

bool RPN::isNumber(const std::string &str)
	{ return (str >= "0" && str <= "9"); }

void RPN::firstOperate(std::string s1, std::string s2, std::string op)
{
	if (op == "+")
		rpnStack.push(std::stoi(s1) + std::stoi(s2));
	else if (op == "-")
		rpnStack.push(std::stoi(s1) - std::stoi(s2));
	else if (op == "*")
		rpnStack.push(std::stoi(s1) * std::stoi(s2));
	else if (op == "/")
	{
		if (std::stoi(s2) != 0)
			rpnStack.push(std::stoi(s1) / std::stoi(s2));
		else
			{throw std::runtime_error("Error: Any number cannot divided by zero");}
	}
}

void RPN::secondOperate(std::string s1, std::string op)
{
	int top =  rpnStack.top();
	rpnStack.pop();
	if (op == "+")
		rpnStack.push(top + std::stoi(s1));
	else if (op == "-")
		rpnStack.push(top - std::stoi(s1));
	else if (op == "*")
		rpnStack.push(top * std::stoi(s1));
	else if (op == "/")
	{
		if (std::stoi(s1) != 0)
			rpnStack.push(top / std::stoi(s1));
		else
			{throw std::runtime_error("Error: Any number cannot divided by zero");}
	}
}

void RPN::thirdOperate(std::string op)
{
	int secondValue = rpnStack.top();
	rpnStack.pop();
	int firstValue = rpnStack.top();
	rpnStack.pop();
	if (op == "+")
		rpnStack.push(firstValue + secondValue);
	else if (op == "-")
		rpnStack.push(firstValue - secondValue);
	else if (op == "*")
		rpnStack.push(firstValue * secondValue);
	else if (op == "/")
	{
		if (secondValue != 0)
			rpnStack.push(firstValue / secondValue);
		else
			{ throw std::runtime_error("Error: Any number cannot divided by zero"); }
	}
}


void RPN::Process()
{
	for (int i = 0; i < count; i++)
	{
		if (isNumber(arg[i]))
		{
			if (isNumber(arg[i+1]) && isNumber(arg[i+2]))
				rpnStack.push(std::stoi(arg[i]));
		}
		else if (isOperator(arg[i]))
		{
			if (isNumber(arg[i-1]) && isNumber(arg[i-2]))
				firstOperate(arg[i-2], arg[i-1], arg[i]);
			else if (isNumber(arg[i-1]) && isOperator(arg[i-2]))
				secondOperate(arg[i-1], arg[i]);
			else if (isOperator(arg[i-1]))
				thirdOperate(arg[i]);
		}
		else
			throw (invalidArgument());
	}
	std::cout << rpnStack.top() << std::endl;
}