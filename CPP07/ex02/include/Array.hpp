/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 11:57:55 by victorviter       #+#    #+#             */
/*   Updated: 2025/08/16 12:33:16 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdio>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <stdexcept>

template < typename T >
class Array {
	public :
	// CONSTRUCTORS
		Array();
		Array(unsigned int n);
		Array(const Array<T> &other);
		Array &operator=(const Array<T> &other);
		T &operator[](int index);
	//DESTUCTORS
		~Array();
	//GETTERS
	//SETTERS
	//MEMBER FUNCTIONS
		size_t	size(void);
	private :
		T		*_array;
		int		_size;
};

#include "Array.tpp"