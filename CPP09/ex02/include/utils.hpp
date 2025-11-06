/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:35:51 by vviterbo          #+#    #+#             */
/*   Updated: 2025/11/06 17:17:11 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <deque>


extern std::deque<size_t> insertionOrder; 

bool				parseInput(std::deque<int> &vals, int argc, char *argv[]);
std::deque<size_t>	getInsertionOrder(int listSize);
bool				isNonZero(std::string s);
void				printDeque(std::deque<int> d);
void				printDeque(std::deque<size_t> d);
