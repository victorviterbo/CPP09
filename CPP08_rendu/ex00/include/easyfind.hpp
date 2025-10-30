/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 14:00:00 by victorviter       #+#    #+#             */
/*   Updated: 2025/10/30 11:53:27 by vviterbo         ###   ########.fr       */
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
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator	it = container.begin();

	while (it != container.end())
	{
		if (*it == value)
			return (it);
		++it;
	}
	return (it);
}
