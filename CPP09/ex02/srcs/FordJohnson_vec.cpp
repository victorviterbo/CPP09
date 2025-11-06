/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FordJohnson_vec.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:02:46 by vviterbo          #+#    #+#             */
/*   Updated: 2025/11/06 18:20:24 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FordJohnson_vec.hpp"

void	recursiveMergeInsert(std::vector<int> &main, std::vector<int> &mixed, unsigned int level)
{
	blockSort(mixed, level);
	if (pow(2, level + 1) <= mixed.size())
	{
		recursiveMergeInsert(main, mixed, level + 1);
		if (level == 0)
			return ;
		std::vector<int>	predecessors;
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
		if (mixed[pow(2, level - 1) - 1])
			main.push_back(mixed[pow(2, level - 1) - 1]);
		main.push_back(mixed[pow(2, level) - 1]);
	}
	return ;
}

void	blockSort(std::vector<int> &mixed, unsigned int level)
{

	std::vector<int>					semiSorted;
	size_t							idx_l;
	size_t							idx_r;
	std::vector<int>::iterator		r1_start;
	std::vector<int>::iterator		r2_start;
	std::vector<int>::iterator		r2_end;
	
	idx_l = static_cast<size_t>(pow(2, level) - 1);
	idx_r = static_cast<size_t>(pow(2, level + 1) - 1);
	semiSorted.resize(0);
	while (idx_r < mixed.size())
	{
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
	mixed = semiSorted;
	semiSorted.clear();
	return ;
}

void	mergeInMain(std::vector<int> &main, std::vector<int> &predecessors)
{
	std::vector<size_t>	main_mapping(0);
	size_t				i = 0;
	size_t				insert_pos;

	for (unsigned int j = 0; j <= predecessors.size(); ++j)
		main_mapping.push_back(j);
	while (i < insertionOrder_v.size() && i < 2 * predecessors.size())
	{
		if (predecessors.size() < insertionOrder_v[i])
		{
			++i;
			continue ;
		}
		insert_pos = insertIntoMain(main, predecessors[insertionOrder_v[i] - 1], main_mapping[insertionOrder_v[i] - 1]);
		for (unsigned int j = 0; j < main_mapping.size(); ++j)
		{
			if (main_mapping[j] < insert_pos)
				continue ;
			main_mapping[j] += 1;
		}
		++i;
	}
}

size_t	insertIntoMain(std::vector<int> &main, int n, size_t indx)
{
	int							range;
	std::vector<int>::iterator	it = main.begin();

	indx = indx / 2;
	range = indx;
	while (range > 0 && indx < main.size())
	{
		range = range / 2;
		if (main[indx] < n)
			indx += range;
		else
			indx -= range;
	}
	if (main[indx] < n)
		indx += 1;
	std::advance(it, indx);
	main.insert(it, n);
	return (indx);
}
