/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FordJohnson.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:02:59 by vviterbo          #+#    #+#             */
/*   Updated: 2025/11/05 16:49:28 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils.hpp"

std::deque<int>		recursiveMergeInsert(std::deque<int> &main, std::deque<int> &mixed, unsigned int level);
void				blockSort(std::deque<int> &mixed, unsigned int level);
void				mergeInMain(std::deque<int> &main, std::deque<int> predecessors);
size_t				insertIntoMain(std::deque<int> &main, int n, size_t indx);