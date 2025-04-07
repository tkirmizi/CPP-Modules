/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:22:06 by taha              #+#    #+#             */
/*   Updated: 2025/02/16 17:22:16 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
void swap(T& a, T& b){
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
T min(T& a, T& b){
	if (a == b)
		return b;
	return (a < b) ? a : b;
}

template <typename T>
T max(T& a, T& b){
	if (a == b)
		return b;
	return (a > b) ? a : b;
}