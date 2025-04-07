/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirmizi <tkirmizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:34:25 by tkirmizi          #+#    #+#             */
/*   Updated: 2025/02/17 16:40:21 by tkirmizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void print(T &i)
{
	std::cout << i << " ";
}

template <typename T>
void doubleVal(T &i)
{
	i *= 2;
}

template <typename T>
void iter(T arr[], size_t size, void(*func)(T&))
{
	for (size_t i = 0; i < size ; i++)
		func(arr[i]);
}


#endif