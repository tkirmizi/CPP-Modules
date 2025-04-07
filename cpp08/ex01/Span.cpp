/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirmizi <tkirmizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:57:07 by taha              #+#    #+#             */
/*   Updated: 2025/02/28 12:45:46 by tkirmizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"


Span::Span(unsigned int N){this->N = N; vec.reserve(N);}
Span::Span(Span const &other){*this = other;}
Span &Span::operator=(Span const &other){ if (this != &other){ this->N = other.N; this->vec = other.vec; } return *this;}
Span::~Span(){}


void Span::generateRandomNumbers(unsigned long count, int min, int max) {
	if (count > N - vec.size())
		throw AlreadyEnoughNumbers();

	std::set<int> uniqueNumbers;
	std::srand(std::time(0));

	while (uniqueNumbers.size() < count) {
		int randomNum = std::rand() % (max - min + 1) + min;
		uniqueNumbers.insert(randomNum);
	}

	for (int num : uniqueNumbers) {
		this->addNumber(num);
	}
}

const char *Span::AlreadyEnoughNumbers::what() const noexcept
	{ return "Error: There are already N numbers in the vector."; }

const char *Span::NotEnoughNumbersToSort::what() const noexcept
	{ return "Error: only 1 number or not any in vector"; }

int Span::longestSpan()
{
	if (vec.size() <= 1)
		throw NotEnoughNumbersToSort();

	auto minMax = std::minmax_element(vec.begin(), vec.end());
	return *minMax.second - *minMax.first;
}

int Span::shortestSpan()
{
	if (vec.size() <= 1)
		throw NotEnoughNumbersToSort();

	std::vector<int> sortedVec = vec;
	std::sort(sortedVec.begin(), sortedVec.end());

	auto minDiff = std::numeric_limits<int>::max(); // max int

	for (auto it = sortedVec.begin(); it != sortedVec.end() - 1; ++it)
	{
		auto next = it+1;
		int diff = *next - *it;
		minDiff = std::min(minDiff, diff);
	}

	return minDiff;
}
void Span::addNumber(int i)
{
	if (vec.size() >= this->N)
		throw(AlreadyEnoughNumbers());
	vec.push_back(i);
}

void printVector(std::vector<int> vec)
{
	int i = 1;
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << "[" << i++ << "]" << *it << std::endl;
	std::cout << "\n";
}

std::vector<int> &Span::getVec()
{
	return this->vec;
}