/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:35:51 by vviterbo          #+#    #+#             */
/*   Updated: 2025/11/09 13:50:19 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>

extern std::deque<int> insertionOrder_d; 

template < typename T >
bool	parseInput(T &vals, int argc, char *argv[]);

template < typename T >
T		getInsertionOrder(int listSize);

bool	isNonZero(std::string s);

template < typename T >
void	printDeque(T d, size_t n);

template < typename T >
void	checkSort(T d);

#include "utils.tpp"