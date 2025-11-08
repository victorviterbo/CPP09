/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_deque.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:35:51 by vviterbo          #+#    #+#             */
/*   Updated: 2025/11/08 11:08:46 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <deque>

extern std::deque<size_t> insertionOrder_d; 

bool				parseInput(std::deque<int> &vals, int argc, char *argv[]);
std::deque<size_t>	getInsertionOrder(int listSize);
bool				isNonZero(std::string s);
void				printDeque(std::deque<int> d, size_t n);
void				printDeque(std::deque<size_t> d, size_t n);
void				checkSort(std::deque<int> d);