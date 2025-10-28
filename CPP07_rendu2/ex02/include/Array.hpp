/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 11:57:55 by victorviter       #+#    #+#             */
/*   Updated: 2025/10/28 17:01:42 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdio>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstring>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

template < typename T >
class Array {
	public :
	// CONSTRUCTORS
		Array();
		Array(unsigned int n);
		Array(const Array<T> &other);
		Array &operator=(const Array<T> &other);
		T &operator[](int index);
		const T &operator[](int index) const;
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