/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirmizi <tkirmizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:56:47 by taha              #+#    #+#             */
/*   Updated: 2025/02/28 12:50:20 by tkirmizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <ostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <numeric>
#include <utility>
#include <set>

class Span
{
	private:
		unsigned int N;
		std::vector<int> vec;

	public:
		// Canonical
		Span(unsigned int N);
		Span(Span const &other);
		Span&operator=(Span const &other);
		~Span();

		// Exception classes
		class AlreadyEnoughNumbers: public std::exception
			{ public: const char *what() const noexcept override; };
		class NotEnoughNumbersToSort: public std::exception
			{ public: const char *what() const noexcept override; };

		// Member functions
		void addNumber(int i);
		int shortestSpan();
		int longestSpan();
		
		void generateRandomNumbers(unsigned long count, int min, int max);
		std::vector<int>& getVec();
		
		template <typename Iterator>
		void addRange(Iterator begin, Iterator end);

};

void printVector(std::vector<int> vec);


template <typename Iterator>
void Span::addRange(Iterator begin, Iterator end)
{
	unsigned int remainingCapacity = N - vec.size();
	unsigned int distance = std::distance(begin, end);
	if (distance > remainingCapacity)
		throw AlreadyEnoughNumbers();
	vec.insert(vec.end(), begin, end);
}
