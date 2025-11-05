/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:35:51 by vviterbo          #+#    #+#             */
/*   Updated: 2025/11/04 17:19:10 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <vector>
#include <list>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <deque>
#include <map>

/*
typedef struct s_elem
{
	std::deque<struct s_elem>	winner;
	std::deque<struct s_elem>	loser;
}	t_elem;
*/

extern std::deque<size_t> insertionOrder; 

bool				parseInput(std::deque<int> &vals, int argc, char *argv[]);
std::deque<size_t>	getInsertionOrder(int listSize);
bool				isNonZero(std::string s);
void				printList(std::list<int> l);
void				printDeque(std::deque<int> d);
void				printDeque(std::deque<size_t> d);
void				printPairing(std::map<int, int> pairing);
