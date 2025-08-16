/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 11:57:52 by victorviter       #+#    #+#             */
/*   Updated: 2025/08/16 12:33:40 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template < typename T >
Array<T>::Array(void)
{
	this->_array = new T[0];
	this->_size = 0;
}

template < typename T >
Array<T>::Array(unsigned int n)
{
	this->_array = new T[n];
	this->_size = n;
}

template < typename T >
Array<T>::Array(const Array<T> &other)
{
	this->_array = new T[other._size];
	this->_size = other._size;
	for (int i = 0; i < other._size; i++)
		this->_array[i] = other._array[i];
}

template < typename T >
Array<T> &Array<T>::operator=(const Array<T> &other)
{
	delete[] this->_array;
	this->_array = new T[other._size];
	this->_size = other._size;
	for (int i = 0; i < other._size; i++)
		this->_array[i] = other._array[i];
	return (*this);
}

template < typename T >
T &Array<T>::operator[](int index)
{
	if (index >= this->_size || index < 0)
		throw std::out_of_range("Index out of bounds");
	return (this->_array[index]);
}

template < typename T >
Array<T>::~Array()
{
	delete[] this->_array;
}

template < typename T >
size_t  Array<T>::size(void)
{
	return (this->_size);
}
