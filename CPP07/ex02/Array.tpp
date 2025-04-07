/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirmizi <tkirmizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 19:58:32 by tkirmizi          #+#    #+#             */
/*   Updated: 2025/02/17 20:08:02 by tkirmizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array(): _size(0), _array(new T[0]){};

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {};

template <typename T>
Array<T>::Array(const Array<T> &src)
{
	this->_size = src._size;
	_array = new T[this->_size];
	for (unsigned int i = 0; i < _size ; i++)
		this->_array[i] = src._array[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &src)
{
	if (this != &src)
	{
		delete[] _array;
		_size = src._size;
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = src._array[i];
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	if (_array)
	{
		if (_size)
			delete [] _array;
	}
}

template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

template <typename T>
T &Array<T>::operator[] (unsigned int index)
{
	if (index >= _size)
		throw std::out_of_range("index out of bounds");
	return _array[index];
}



#endif