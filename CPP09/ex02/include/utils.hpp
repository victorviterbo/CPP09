/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:35:51 by vviterbo          #+#    #+#             */
/*   Updated: 2025/08/30 18:39:23 by victorviter      ###   ########.fr       */
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

typedef struct s_intpair {
	int		big;
	int		small;
}	intpair;

bool	is_non_zero(std::string s);
void	print_list(std::list<intpair> l);
void	print_list(std::list<int> l);
void	print_deque(std::deque<int> d);
void	print_pairing(std::map<int, std::list<intpair>::iterator> pairing);