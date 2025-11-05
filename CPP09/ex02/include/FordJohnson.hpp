/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FordJohnson.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:02:59 by vviterbo          #+#    #+#             */
/*   Updated: 2025/11/04 17:16:37 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils.hpp"

std::deque<int>		recursiveMergeInsert(std::deque<int> mixed, unsigned int level);
void				mergeInMain(std::deque<int> &main, std::deque<int> &semiSorted, unsigned int level);
void				insertIntoMain(std::deque<int> &main, int n, int indx);
