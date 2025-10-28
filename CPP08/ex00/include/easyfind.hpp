/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 14:00:00 by victorviter       #+#    #+#             */
/*   Updated: 2025/10/28 15:40:32 by vviterbo         ###   ########.fr       */
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

	while (it != container.end())
	{
		if (*it == value)
			return (*it);
		++it;
	}
	throw std::runtime_error("Value not in container");
}
