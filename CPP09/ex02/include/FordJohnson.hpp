/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FordJohnson.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:02:59 by vviterbo          #+#    #+#             */
/*   Updated: 2025/08/20 17:18:53 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <list>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <deque>
#include <map>

typedef struct s_intpair {
	int		big;
	int		small;
}	intpair;

void			initial_split(std::deque<int> &vals, std::list<intpair> &main);
void			generate_Jacobsthal(int n, std::deque<int> &q);
std::deque<int>	recursive_merge_insert(std::list<intpair> unsorted);
void			merge_into_main(std::deque<int> &main, std::list<intpair> sorted, std::map<int, std::list<intpair>::iterator>	pairing);
void			insert_into_main(int n,  std::deque<int> &main, int i, int jacob);
