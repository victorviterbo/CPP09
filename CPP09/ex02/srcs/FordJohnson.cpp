/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FordJohnson.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:02:46 by vviterbo          #+#    #+#             */
/*   Updated: 2025/11/05 16:01:05 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FordJohnson.hpp"

std::deque<int>	recursiveMergeInsert(std::deque<int> &main, std::deque<int> &mixed, unsigned int level)
{
	mixed = blockSort(mixed, level);
	if (pow(2, level + 1) <= mixed.size())
	{
		main = recursiveMergeInsert(main, mixed, level + 1);
		if (level == 0)
			return (main);
		std::deque<int>	predecessors;
		size_t	idx = pow(2, level - 1) - 1;
		while (idx < mixed.size())
		{
			predecessors.push_back(mixed[idx]);
			idx += pow(2, level);
		}
		mergeInMain(main, predecessors);
	}
	else
	{
		main.push_front(mixed[pow(2, level) - 1]);
		if (mixed[pow(2, level - 1) - 1])
			main.push_front(mixed[pow(2, level - 1) - 1]);
	}
	return (main);
}

std::deque<int>		blockSort(std::deque<int> mixed, unsigned int level)
{

	std::deque<int>					semiSorted;
	size_t							idx_l;
	size_t							idx_r;
	std::deque<int>::iterator		r1_start;
	std::deque<int>::iterator		r2_start;
	std::deque<int>::iterator		r2_end;
	
	idx_l = static_cast<size_t>(pow(2, level) - 1);
	idx_r = static_cast<size_t>(pow(2, level + 1) - 1);
	semiSorted.resize(0);
	while (idx_r < mixed.size())
	{
		//std::cout << "idx_l = " << idx_l << " idx_r = " << idx_r << std::endl;
		r1_start = mixed.begin();
		r2_start = mixed.begin();
		r2_end = mixed.begin();
		std::advance(r1_start, static_cast<int>(idx_l - pow(2, level) + 1));
		std::advance(r2_start, static_cast<int>(idx_l + 1));
		std::advance(r2_end, static_cast<int>(idx_r + 1));
		if (mixed[idx_l] < mixed[idx_r])
		{
			semiSorted.insert(semiSorted.end(), r1_start, r2_start);
			semiSorted.insert(semiSorted.end(), r2_start , r2_end);
		}
		else
		{
			semiSorted.insert(semiSorted.end(), r2_start, r2_end);
			semiSorted.insert(semiSorted.end(), r1_start, r2_start);
		}
		idx_l += static_cast<size_t>(pow(2, level + 1));
		idx_r += static_cast<size_t>(pow(2, level + 1));
	}
	r2_end = mixed.begin();
	std::advance(r2_end, semiSorted.size());
	semiSorted.insert(semiSorted.end(), r2_end, mixed.end());
	return (semiSorted);
}
void	mergeInMain(std::deque<int> &main, std::deque<int> predecessors)
{
	size_t i = 0;
	while (i < insertionOrder.size() && i <= 3 * predecessors.size())
	{
		if (predecessors.size() < insertionOrder[i])
		{
			++i;
			continue ;
		}
		insertIntoMain(main, predecessors[insertionOrder[i] - 1], insertionOrder[i] - 1 + i);
		++i;
	}
}

void	insertIntoMain(std::deque<int> &main, int n, int indx)
{
	int							range;
	std::deque<int>::iterator	it = main.begin();

	range = std::min((indx + 1) / 2, static_cast<int>(main.size() - 1));
	indx = indx / 2;
	while (range > 0 && indx < static_cast<int>(main.size()))
	{
		range = range / 2;
		if (main[indx] < n)
			indx += range;
		else
			indx -= range;
	}
	if (main[indx] < n)
		std::advance(it, indx + 1);
	else
		std::advance(it, indx);
	main.insert(it, n);
	return ;
}
