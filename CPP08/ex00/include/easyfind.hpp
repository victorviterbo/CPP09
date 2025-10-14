/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EasyFind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 14:00:00 by victorviter       #+#    #+#             */
/*   Updated: 2025/10/14 18:40:38 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>

template < typename T >
int easyfind(T container, int value)
{
	typename T::iterator	it = container.begin();
	
	//ret = std::find(container.begin(), container.end(), value);
	while (it != container.end())
	{
		if (*it == value)
			return (*it);
		++it;
	}
	throw std::runtime_error("Value not in container");
}
