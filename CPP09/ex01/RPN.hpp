/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:17:54 by taha              #+#    #+#             */
/*   Updated: 2025/03/05 13:05:54 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <ostream>
#include <algorithm>
#include <cctype>
#define MAX_TOKENS 50

class RPN
{
	private:
		std::string arg[MAX_TOKENS];
		int count;
		std::stack<int> rpnStack;

	public:
		RPN();
		~RPN();
		RPN(RPN const &src);
		RPN &operator=(RPN const &src);

		bool parseInput(const std::string &input);
		bool isOperator(const std::string &str);
		bool isNumber(const std::string &str);
		void firstOperate(std::string s1, std::string s2, std::string op);
		void secondOperate(std::string s1, std::string op);
		void thirdOperate(std::string op);
		void Process();

		std::string* getArg() { return this->arg; }
		int getCount ( void ){return (this->count);}
		const std::stack<int> &getStack( void ){return (this->rpnStack);}


		class moreThanTenNbr : public std::exception
			{ public: const char *what() const noexcept override; };

		class invalidArgument : public std::exception
			{ public: const char *what() const noexcept override; };

};