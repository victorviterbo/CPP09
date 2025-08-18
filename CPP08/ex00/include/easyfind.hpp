/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 14:00:00 by victorviter       #+#    #+#             */
/*   Updated: 2025/08/18 13:04:10 by vviterbo         ###   ########.fr       */
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
	typename T::const_iterator	ret;
	
	ret = std::find(container.begin(), container.end(), value);
	if (ret != container.end())
		return (*ret);
	throw std::runtime_error("Value not in container");
}
