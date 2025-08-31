/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FordJohnson.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:02:59 by vviterbo          #+#    #+#             */
/*   Updated: 2025/08/30 18:27:08 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils.hpp"

void			initial_split(std::deque<int> &vals, std::list<intpair> &main);
void			generate_Jacobsthal(int n, std::deque<int> &q);
std::deque<int>	recursive_merge_insert(std::list<intpair> unsorted);
void			merge_into_main(std::deque<int> &main, std::list<intpair> sorted, std::map<int, std::list<intpair>::iterator>	pairing);
void			insert_into_main(int n,  std::deque<int> &main, int i, int jacob);
