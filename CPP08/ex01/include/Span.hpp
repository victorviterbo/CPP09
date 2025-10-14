/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 15:58:49 by victorviter       #+#    #+#             */
/*   Updated: 2025/10/14 18:52:24 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <array>
#include <deque>
#include <forward_list>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>

class Span {
	public :
	// CONSTRUCTORS
		Span(unsigned int n);
		Span(Span &other);
		Span &operator=(Span &other);
	//DESTUCTORS
		~Span();
	//GETTERS
	//SETTERS
	//MEMBER FUNCTIONS
		void			addNumber(int val);
  		template <typename T>
		void			addNumber(T begin, T end);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
		void			printValues();
	private :
		std::vector<int>	_nums;
		unsigned int		_size;
		
};

#include "Span.tpp"