/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FordJohnson_deque.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:02:46 by vviterbo          #+#    #+#             */
/*   Updated: 2025/11/08 15:51:53 by victorviter      ###   ########.fr       */
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
	std::deque<size_t>				insert_mapping(0);
	std::deque<size_t>::iterator	it;
	static std::deque<size_t>		global_mapping(0);
	size_t							i = 0;
	size_t							insert_pos;


	for (unsigned int j = 0; j < predecessors.size(); ++j)
		insert_mapping.push_back(j);
	if (global_mapping.size() == 0)
	{
		std::cout << "My first mapping !" << std::endl;
		printDeque(insert_mapping, 10);
		global_mapping = insert_mapping;
	}
	while (i < insertionOrder_d.size() && i < 2 * predecessors.size())
	{
		if (predecessors.size() < insertionOrder_d[i])
		{
			++i;
			continue ;
		}
		std::cout << "inserting " << predecessors[global_mapping[insert_mapping[insertionOrder_d[i] - 1]]] << " insertionOrder_d[i] - 1 " << insertionOrder_d[i] - 1 << " global_mapping[insert_mapping[insertionOrder_d[i] - 1]] = " << global_mapping[insert_mapping[insertionOrder_d[i] - 1]] << std::endl;
		insert_pos = insertIntoMain(main, predecessors[global_mapping[insert_mapping[insertionOrder_d[i] - 1]]], insert_mapping[insertionOrder_d[i] - 1]);
		for (unsigned int j = 0; j < insert_mapping.size(); ++j)
		{
			if (insert_mapping[j] >= insert_pos)
				insert_mapping[j] += 1;
		}
		/*for (unsigned int j = insert_pos; j < global_mapping.size(); ++j)
		{
			//if (insert_mapping[j] >= insert_pos)
			global_mapping[j] += 1;
			//if (global_mapping[j] > insert_pos)
		}*/
		std::cout << "DAFFF2222 mapping global = " << std::endl;
		printDeque(global_mapping, global_mapping.size());
		std::cout << "mapping = " << std::endl;// 0 1 2 ->  0 0 1 2 -> 0 1 0 1 2  ->  2 0 1 0 1 2  4 1 2 1          2 0 4 1 3
		printDeque(insert_mapping, insert_mapping.size()); // -> 49905 64438 68831 74759 89525
		it = global_mapping.begin();
		std::advance(it, insert_pos);
		global_mapping.insert(it, global_mapping[insert_mapping[insertionOrder_d[i] - 1]]);
		std::cout << "insert pos = " << insert_pos << std::endl;
		std::cout << "DAFFF mapping global = " << std::endl;
		printDeque(global_mapping, global_mapping.size());
		std::cout << "DAFFF mapping = " << std::endl;
		printDeque(insert_mapping, insert_mapping.size());
		++i;
	}
	for (unsigned int k = 0; k < global_mapping.size(); ++k)
		global_mapping[k] = global_mapping[k] * 2 + k % 2;
	std::cout << "mapping global = " << std::endl;
	printDeque(global_mapping, global_mapping.size());
	std::cout << "main = " << std::endl;
	printDeque(main, main.size());
	if (main.size() > 50)
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
