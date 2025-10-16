/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 11:57:55 by victorviter       #+#    #+#             */
/*   Updated: 2025/10/16 13:44:14 by vviterbo         ###   ########.fr       */
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