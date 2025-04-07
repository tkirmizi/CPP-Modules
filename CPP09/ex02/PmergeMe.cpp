/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:54:45 by taha              #+#    #+#             */
/*   Updated: 2025/03/05 14:06:02 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


PmergeMe::PmergeMe(){};
PmergeMe::~PmergeMe(){};

PmergeMe::PmergeMe(const PmergeMe &src)
	{ this->vec = src.vec; this->deq = src.deq; }

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	if (this != &src)
	{
		this->vec = src.vec;
		this->deq = src.deq;
	}
	return *this;
}


const char *PmergeMe::ThereIsNegative::what() const noexcept
{ return "Error"; }

const char *PmergeMe::AlreadySorted::what() const noexcept
{ return "Error: Already sorted numbers"; }

int PmergeMe::isNbr(char **argv, int argc)
{
	std::vector<int> numbers;
	
	for (int i = 1; i < argc; i++)
	{
		std::string arg = argv[i];
		for (size_t j = 0; j < arg.length(); j++)
		{
			if (!isdigit(arg[j]))
				throw std::invalid_argument("Error no digit");
		}
		int num = std::stoi(arg);
		if (isPosInt(num) == false)
			throw ThereIsNegative();
		numbers.push_back(num);
	}
	if (std::is_sorted(numbers.begin(), numbers.end()))
		throw AlreadySorted();
		
	return 0;
}

bool PmergeMe::isPosInt(int i)
{
	if (i < 0)
		return false;
	return true;
}

char *PmergeMe::duplicateCheck(char** argv, int size, char *array)
{
	int arrayIndex = 0;
	
	for (int i = 1; i < size; i++)
	{
		int num = std::stoi(argv[i]);
		if (std::find(vec.begin(), vec.end(), num) == vec.end())
		{
			if (arrayIndex > 0)
				array[arrayIndex++] = ' ';
			std::string numStr = argv[i];
			for (char c : numStr)
				array[arrayIndex++] = c;
			vec.push_back(num);
			deq.push_back(num);
		}
	}
	array[arrayIndex] = '\0';
	return array;
}

bool PmergeMe::isSorted(char **argv, int argc)
{
	std::vector<int> numbers;
	for (int i = 1; i < argc; i++)
		numbers.push_back(std::stoi(argv[i]));
	return std::is_sorted(numbers.begin(), numbers.end());
}

void PmergeMe::mergeInsertionVec( void )
	{ mergeInsertion(this->vec); }

void PmergeMe::mergeInsertionDeq( void )
	{ mergeInsertion(this->deq); }


void PmergeMe::beforeWritter( void )
{
	std::cout << "Before:	";
	for (size_t i = 0; i < vec.size() ; i++)
		std::cout << vec.operator[](i) << " ";
	std::cout << std::endl;
}

void PmergeMe::vecSorting( void )
{
	beforeWritter();
	auto start = std::chrono::high_resolution_clock::now();
	mergeInsertionVec();
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::micro> elapsed = end - start;
	containerWritter(vec);
	
	std::cout << "Time to process a range of " << (vec.size()) << " elements with std::vector : "
	<< elapsed.count() << " us" << std::endl;
}

void PmergeMe::deqSorting( void )
{
	auto start2 = std::chrono::high_resolution_clock::now();
	mergeInsertionDeq();
	auto end2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::micro> elapsed2 = end2 - start2;
	std::cout << "Time to process a range of " << (deq.size()) << " elements with std::deque : "
	<< elapsed2.count() << " us" << std::endl;
}