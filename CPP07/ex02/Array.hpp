/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirmizi <tkirmizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 19:57:01 by tkirmizi          #+#    #+#             */
/*   Updated: 2025/02/17 20:04:05 by tkirmizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename T>
class Array
{
	private:
		T			*_array;
		unsigned int _size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &src);
		~Array();
		Array &operator=(const Array &src);
		unsigned int size() const;
		T &operator[] (unsigned int index);
};

#include "Array.tpp"
#endif