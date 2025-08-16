/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EasyFind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 14:00:00 by victorviter       #+#    #+#             */
/*   Updated: 2025/08/16 15:24:34 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <array>
#include <deque>
#include <forward_list>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>

template < typename T >
int easyfind(T container, int value)
{
	typename T::const_iterator	ret;
	
	ret = std::find(container.begin(), container.end(), value);
	if (ret != container.end())
		return (*ret);
	throw std::runtime_error("Value not in container");
}
