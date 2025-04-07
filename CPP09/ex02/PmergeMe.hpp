/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:54:24 by taha              #+#    #+#             */
/*   Updated: 2025/03/05 14:03:58 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	orthodox canonical gonna add
*/

#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <cstring>
#include <algorithm>
#include <exception>
#include <chrono>

class PmergeMe
{
	private:
		std::vector<int> vec;
		std::deque<int> deq;
	public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe &src);
	PmergeMe &operator=(const PmergeMe &src);
		class ThereIsNegative : public std::exception
		{ public: const char *what() const noexcept override; };
	
		class AlreadySorted : public std::exception
		{ public: const char *what() const noexcept override; };
	
		bool isPosInt(int i);
		int isNbr(char **argv, int argc);
		char *duplicateCheck(char **argv, int argc, char *array);
		bool isSorted(char **argv, int argc);

		template <typename Container>
		void mergeInsertion( Container& arr );

		void mergeInsertionVec( void );
		void mergeInsertionDeq( void );
		
		template <typename Container>
		void containerWritter( Container& arr );

		void beforeWritter( void );
		const std::vector<int> &getVec(){return (this->vec);}
		const std::deque<int> &getDeq() {return (this->deq);}
		void vecSorting( void );
		void deqSorting( void );
};

template <typename Container>
void PmergeMe::containerWritter(Container& arr)
{
	std::cout << "After:	";
	for (size_t i = 0; i < arr.size(); i++)
	{
		std::cout << arr[i];
		if (i < arr.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}

template <typename Container>
void PmergeMe::mergeInsertion( Container& arr )
{
	bool isOdd = arr.size() % 2 != 0;
	typename Container::value_type lastElement;
	if (isOdd)
	{
		lastElement = arr.back();
		arr.pop_back();
	}
	std::vector<std::pair<typename Container::value_type, typename Container::value_type>> pairs;
	for (size_t i = 0; i < arr.size(); i += 2)
	{
		if (i + 1 < arr.size()) {
			if (arr[i] > arr[i + 1])
				pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
			else
				pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
		}
	}
	Container largeElements;
	for (const auto& pair : pairs)
		{ largeElements.push_back(pair.first); }

	if (largeElements.size() > 10)
		{ std::sort(largeElements.begin(), largeElements.end()); }
	else if (largeElements.size() > 1)
		{ mergeInsertion(largeElements); }

	std::vector<typename Container::value_type> smallElements;
	for (const auto& pair : pairs) 
		{ smallElements.push_back(pair.second); }

	Container result;
	for (const auto& element : largeElements)
		{ result.push_back(element); }

	if (!smallElements.empty())
	{
		auto pos = std::lower_bound(result.begin(), result.end(), smallElements[0]);
		result.insert(pos, smallElements[0]);
	}
	std::vector<size_t> jacobsthalIndices;
	size_t jacobPrev = 1;
	size_t jacobCurr = 3;
	while (jacobCurr < smallElements.size())
	{
		jacobsthalIndices.push_back(jacobCurr);
		size_t jacobNext = jacobCurr * 2 - jacobPrev + 1;
		jacobPrev = jacobCurr;
		jacobCurr = jacobNext;
	}
	for (size_t i = jacobPrev; i < smallElements.size(); i++)
		{ jacobsthalIndices.push_back(i); }

	for (size_t idx : jacobsthalIndices)
	{
		if (idx < smallElements.size())
		{
			auto pos = std::lower_bound(result.begin(), result.end(), smallElements[idx]);
			result.insert(pos, smallElements[idx]);
		}
	}
	
	for (size_t i = 1; i < smallElements.size(); i++) {
		if (std::find(jacobsthalIndices.begin(), jacobsthalIndices.end(), i) == jacobsthalIndices.end()) {
			auto pos = std::lower_bound(result.begin(), result.end(), smallElements[i]);
			result.insert(pos, smallElements[i]);
		}
	}
	
	if (isOdd)
	{
		auto pos = std::lower_bound(result.begin(), result.end(), lastElement);
		result.insert(pos, lastElement);
	}
	
	arr = result;
}