/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FordJohnson.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:02:59 by vviterbo          #+#    #+#             */
/*   Updated: 2025/11/02 19:32:52 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils.hpp"

typedef struct s_column
{
	int							value;
	std::deque<struct s_column>	predecessors;	
}	column;

std::deque<column>	recursiveMergeInsert(std::deque<column> mixed);
void				mergeInMain(std::deque<column> &main);
void				insertIntoMain(std::deque<int> &main, int n, int indx);
