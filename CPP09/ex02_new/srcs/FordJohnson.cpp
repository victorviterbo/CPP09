/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FordJohnson.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:02:46 by vviterbo          #+#    #+#             */
/*   Updated: 2025/08/31 12:02:28 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FordJohnson.hpp"

std::deque<int>	recursiveMergeInsert(std::deque<int> mixed)
{
	std::deque<int>		main;
	std::deque<int>		highVals;
	std::map<int, int>	predecessors;
	size_t				i = 0;

	while (i < mixed.size())
	{
		if (i + 1 == mixed.size())
		{
			highVals.push_back(mixed[i]);
			predecessors[i] = -1;
			break ;
		}
		else if (mixed[i] > mixed[i + 1])
		{
			highVals.push_back(mixed[i]);
			predecessors[mixed[i + 1]] = mixed[i];
		}
		else
		{
			highVals.push_back(mixed[i + 1]);
			predecessors[mixed[i + 1]] = mixed[i];
		}
		i += 2;
	}
	if (highVals.size() > 2)
		main = recursiveMergeInsert(highVals);
	mergeInMain(main, highVals, predecessors);
	return (mixed);
}

void	mergeInMain(std::deque<int> &main, std::deque<int> highVals, std::map<int, int> predecessors)
{
	if (!main.size())
	{
		main.push_back(highVals[0] < highVals[1] ? highVals[0] : highVals[1]);
		main.push_back(highVals[0] < highVals[1] ? highVals[1] : highVals[0]);
		return ;
	}
	main.push_back(highVals[0]);
	for (int i = 1; i < 2 * highVals.size(); ++i)
	{
		if (insertionOrder[i] > highVals.size())
			continue ;
		
	}
}