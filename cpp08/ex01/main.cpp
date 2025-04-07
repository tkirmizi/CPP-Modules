/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirmizi <tkirmizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:42:07 by tkirmizi          #+#    #+#             */
/*   Updated: 2025/02/28 12:51:48 by tkirmizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	std::cout << "\n====Test1 - Exception classes ====\n";
	Span a(30);
	try
	{
		std::vector<int> numbers;
		for (int i = 0; i < 31; i++) {
			numbers.push_back(std::rand() % (10000 - 100 + 1) + 100);
		}
		a.addRange(numbers.begin(), numbers.end());
	}
	catch(std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n====Test2 - Exception classes ====\n";
	Span b(1);
	{
		std::vector<int> singleNum = {std::rand() % (10000 - 100 + 1) + 100};
		b.addRange(singleNum.begin(), singleNum.end());
	}
	try
	{
		b.shortestSpan();
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n====Test3 - 1.000 Numbers====\n";
	Span c(10000);
	{
		std::srand(std::time(0));
		std::set<int> uniqueNumbers;
		while (uniqueNumbers.size() < 1000){
			uniqueNumbers.insert(std::rand() % (914748364 - (-914748364) + 1) + (-914748364));
		}
		c.addRange(uniqueNumbers.begin(), uniqueNumbers.end());
	}
	std::vector<int> vec = c.getVec();
	std::sort(vec.begin(), vec.end());
	printVector(vec);
	std::cout << "Initiated with 1.000 numbers\n";
	std::cout << "shortest span: " << c.shortestSpan()
	<< "\nlongest span: " << c.longestSpan() << "\n";

	std::cout << "\n====Test3 - 10.000 Numbers====\n";
	Span d(10000);
	{
		std::set<int> uniqueNumbers;
		while (uniqueNumbers.size() < 10000) {
			uniqueNumbers.insert(std::rand() % (914748364 - (-914748364) + 1) + (-914748364));
		}
		d.addRange(uniqueNumbers.begin(), uniqueNumbers.end());
	}
	std::cout << "Initiated with 10.000 numbers\n";
	std::cout << "shortest span: " << d.shortestSpan()
	<< "\nlongest span: " << d.longestSpan() << "\n";
}

/*
SUBJECT TEST

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}
*/

