/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FordJohnson_deque.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:02:46 by vviterbo          #+#    #+#             */
/*   Updated: 2025/11/09 11:56:47 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FordJohnson_deque.hpp"

bool hasDuplicate(std::deque<size_t> &d)
{
    std::unordered_set<size_t>	seen;
    for (std::deque<size_t>::iterator it = d.begin(); it != d.end(); ++it)
	{
        if (!seen.insert(*it).second)
            return (true);
		else if (*it >= d.size())
			return (true);
    }
    return false;
}





void	recursiveMergeInsert(std::deque<int> &main, std::deque<int> &mixed, unsigned int level)
{
	blockSort(mixed, level);
	if (pow(2, level + 1) <= mixed.size())
	{
		recursiveMergeInsert(main, mixed, level + 1);
		std::deque<int>	predecessors(0);
		size_t	idx = pow(2, level) - 1;
		while (idx < mixed.size())
		{
			predecessors.push_back(mixed[idx]);
			idx += pow(2, level + 1);
		}
		mergeInMain(main, predecessors);
	}
	else
		main.push_front(mixed[pow(2, level) - 1]);
	return ;
}

void	blockSort(std::deque<int> &mixed, unsigned int level)
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

void	initialInsert(std::deque<int> &main, std::deque<int> &predecessors, std::deque<size_t> &global_mapping)
{
	int		pos = 0;
	main.push_front(predecessors[0]);
	global_mapping.push_back(0);
	global_mapping.push_back(1);
	std::deque<int>::iterator it1 = main.begin();
	std::deque<size_t>::iterator it2 = global_mapping.begin();
	if (predecessors.size() > 1)
	{
		if (main[0] < predecessors[1])
		{
			if (main[1] <predecessors[1])
				pos = 2;
			else
				pos = 1;
		}
		std::advance(it1, pos);
		main.insert(it1, predecessors[1]);
		std::advance(it2, pos);
		global_mapping.insert(it2, 2);
	}
}

void	mergeInMain(std::deque<int> &main, std::deque<int> &predecessors)
{
	std::deque<size_t>				insert_mapping(0);
	std::deque<size_t>::iterator	it;
	static std::deque<size_t>		global_mapping(0);
	std::deque<size_t>				tmp_mapping(main.size());
	size_t							i = 0;
	size_t							indx;
	size_t							insert_pos;
	size_t							main_orig_size = main.size();

	for (unsigned int j = 0; j < main.size() + predecessors.size(); ++j)
		insert_mapping.push_back(j);
	if (global_mapping.size() == 0)
	{
		initialInsert(main, predecessors, global_mapping);
		return ;
	}
	for (unsigned int k = 0; k < tmp_mapping.size(); ++k)
		tmp_mapping[k] = global_mapping[k] * 2 + 1;
	while (i < insertionOrder_d.size() && i < 3 * predecessors.size())
	{
		if (predecessors.size() < insertionOrder_d[i])
		{
			++i;
			continue ;
		}
		else if (predecessors.size() == insertionOrder_d[i] && predecessors.size() != main_orig_size)
		{
			insert_pos = main.size();
			indx = predecessors.size() - 1;
		}
		else
		{
			insert_pos = insert_mapping[insertionOrder_d[i] - 1];
			indx = global_mapping[insertionOrder_d[i] - 1];
		}
		insert_pos = insertIntoMain(main, predecessors[indx], insert_pos);
		for (unsigned int j = 0; j < insert_mapping.size(); ++j)
		{
			if (insert_mapping[j] >= insert_pos)
				insert_mapping[j] += 1;
		}
		it = tmp_mapping.begin();
		std::advance(it, insert_pos);
		if (2 * indx < global_mapping.size())	
			tmp_mapping.insert(it, indx * 2);
		else
			tmp_mapping.insert(it, indx * 2);
		++i;
	}
	global_mapping = tmp_mapping;
}

size_t	insertIntoMain(std::deque<int> &main, int n, size_t indx)
{
	// int							range;
	std::deque<int>::iterator	it = main.begin();
	size_t						rl = 0;
	size_t						ru = indx;
	size_t						mid;

	while (rl + 1 < ru)
	{
		mid = (ru + rl) / 2;
		if (main[mid] < n)
			rl = mid;
		else
			ru = mid;
	}
	if (main[rl] < n)
		indx = rl + 1;
	else
		indx = rl;
	std::advance(it, indx);
	main.insert(it, n);
	return (indx);
}
