/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FordJohnson.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:02:46 by vviterbo          #+#    #+#             */
/*   Updated: 2025/08/19 15:57:48 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FordJohnson.hpp"

void	initial_split(std::deque<int> &vals, std::list<intpair> &main)
{
	int		val1;
	int		val2;
	intpair	pair;

	while (vals.size())
	{
		val1 = vals.front();
		vals.pop_front();
		if (vals.empty())
		{
			pair.big = -1;
			pair.small = val1;
			return ;
		}
		val2 = vals.front();
		vals.pop_front();
		pair.big = (val1 > val2 ? val1 : val2);
		pair.small = (val1 < val2 ? val1 : val2);
		main.push_back(pair);
	}
	return ;
}

void	generate_Jacobsthal(int n, std::deque<int> &q)
{
	q.push_front(0);
	q.push_front(1);
	while (q.front() < n)
		q.push_front(q[0] + 2 * q[1]);
}