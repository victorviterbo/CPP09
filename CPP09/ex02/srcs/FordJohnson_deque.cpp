/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FordJohnson_deque.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:02:46 by vviterbo          #+#    #+#             */
/*   Updated: 2025/11/08 13:56:36 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FordJohnson_deque.hpp"

void	recursiveMergeInsert(std::deque<int> &main, std::deque<int> &mixed, unsigned int level)
{
	blockSort(mixed, level);
	if (pow(2, level + 1) <= mixed.size())
	{
		recursiveMergeInsert(main, mixed, level + 1);
		if (level == 0)
			return ;
		std::deque<int>	predecessors;
		size_t	idx = pow(2, level - 1) - 1;
		while (idx < mixed.size())
		{
			predecessors.push_back(mixed[idx]);
			idx += pow(2, level);
		}
		std::cout << "Predecessors from level " << level << std::endl;
		printDeque(predecessors, predecessors.size());
		std::cout << "Main from level " << level << std::endl;
		printDeque(main, main.size());
		mergeInMain(main, predecessors);
	}
	else
	{
		std::cout << "Insertion Order" << std::endl;
		printDeque(insertionOrder_d, insertionOrder_d.size());
		std::cout << "mixed" << std::endl;
		printDeque(mixed, mixed.size());
		main.push_front(mixed[pow(2, level) - 1]);
		if (mixed[pow(2, level - 1) - 1])
			main.push_front(mixed[pow(2, level - 1) - 1]);
	}
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

void	mergeInMain(std::deque<int> &main, std::deque<int> &predecessors)
{
	std::deque<size_t>				main_mapping(0);
	std::deque<size_t>::iterator	it;
	static std::deque<size_t>	main_global_mapping(0);
	size_t						i = 0;
	size_t						insert_pos;

	if (main_global_mapping.size() == 0)
	{
		for (unsigned int j = 0; j < main.size(); ++j)
			main_mapping.push_back(j);
		main_global_mapping = main_mapping;
	}
	else
		main_mapping = main_global_mapping;
	while (i < insertionOrder_d.size() && i < 2 * predecessors.size())
	{
		if (predecessors.size() < insertionOrder_d[i])
		{
			++i;
			continue ;
		}
		std::cout << "inserting " << predecessors[main_mapping[insertionOrder_d[i] - 1]] << " insertionOrder_d[i] - 1 " << insertionOrder_d[i] - 1 << " main_mapping[insertionOrder_d[i] - 1]: " << main_mapping[insertionOrder_d[i] - 1] << std::endl;
		insert_pos = insertIntoMain(main, predecessors[main_mapping[insertionOrder_d[i] - 1]], main_mapping[insertionOrder_d[i] - 1]);
		for (unsigned int j = 0; j < main_mapping.size(); ++j)
		{
			if (main_mapping[j] >= insert_pos)
				main_mapping[j] += 1;
		}
		for (unsigned int j = insert_pos; j < main_global_mapping.size(); ++j)
		{
			//if (main_mapping[j] >= insert_pos)
			main_global_mapping[j] += 1;
			//if (main_global_mapping[j] > insert_pos)
		}
		std::cout << "DAFFF2222 mapping global = " << std::endl;
		printDeque(main_global_mapping, main_global_mapping.size());
		std::cout << "mapping = " << std::endl;
		printDeque(main_mapping, main_mapping.size());
		it = main_global_mapping.begin() + insert_pos;
		main_global_mapping.insert(it, insertionOrder_d[i] - 1);
		std::cout << "insert pos = " << insert_pos << std::endl;
		std::cout << "DAFFF mapping global = " << std::endl;
		printDeque(main_global_mapping, main_global_mapping.size());
		++i;
	}
	std::cout << "mapping global = " << std::endl;
	printDeque(main_global_mapping, main_global_mapping.size());
	std::cout << "main = " << std::endl;
	printDeque(main, main.size());
	//if (predecessors.size() > 2)
	exit (0);
}

size_t	insertIntoMain(std::deque<int> &main, int n, size_t indx)
{
	int							range;
	std::deque<int>::iterator	it = main.begin();

	range = ceil(static_cast<double>(indx) / 2);
	indx = indx / 2;
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
