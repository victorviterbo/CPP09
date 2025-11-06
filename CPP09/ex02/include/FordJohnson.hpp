/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FordJohnson.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:02:59 by vviterbo          #+#    #+#             */
/*   Updated: 2025/11/06 17:35:00 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils.hpp"

void		recursiveMergeInsert(std::deque<int> &main, std::deque<int> &mixed, unsigned int level);
void		blockSort(std::deque<int> &mixed, unsigned int level);
void		mergeInMain(std::deque<int> &main, std::deque<int> &predecessors);
size_t		insertIntoMain(std::deque<int> &main, int n, size_t indx);