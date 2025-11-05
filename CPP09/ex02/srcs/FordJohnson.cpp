/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FordJohnson.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:02:46 by vviterbo          #+#    #+#             */
/*   Updated: 2025/11/05 14:57:58 by vviterbo         ###   ########.fr       */
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
		std::cout << "FOR LEVEL = " << level << " idx0 = " << pow(2, level - 1) - 1 << " increment = " << pow(2, level) << std::endl;
		while (idx < mixed.size())
		{
			predecessors.push_back(mixed[idx]);
			idx += pow(2, level);
		}
		std::cout << "FOR LEVEL = " << level << std::endl;
		std::cout << "========== SENDING predecessors ==========" << std::endl;
		printDeque(predecessors);
		std::cout << "========== MIXED IS ==========" << std::endl;
		printDeque(mixed);
		std::cout << "========== MAIN IS ==========" << std::endl;
		printDeque(main);
		std::cout << "========== END BLOCK ==========" << std::endl;
		mergeInMain(main, predecessors, level);
	}
	else
	{
		main.resize(0);
		main.push_front(mixed[pow(2, level) - 1]);
		if (mixed[pow(2, level - 1) - 1])
			main.push_front(mixed[pow(2, level - 1) - 1]);
	}
	return (main);
}

//33 1 4 9 7 8 12 5 11  CORRIGER jacobsthal + utiliser ref
std::deque<int>		blockSort(std::deque<int> mixed, unsigned int level)
{

	std::deque<int>			semiSorted;
	size_t					idx_l;
	size_t					idx_r;
	
	idx_l = pow(2, level) - 1;
	idx_r = pow(2, level + 1) - 1;
	printDeque(mixed);
	while (idx_r < mixed.size())
	{
		if (mixed[idx_l] < mixed[idx_r])
		{
			semiSorted.insert(semiSorted.end(), mixed.begin() + idx_l - pow(2, level) + 1, mixed.begin() + idx_l + 1);
			semiSorted.insert(semiSorted.end(), mixed.begin() + idx_l + 1, mixed.begin() + idx_r + 1);
		}
		else
		{
			semiSorted.insert(semiSorted.end(), mixed.begin() + idx_l + 1, mixed.begin() + idx_r + 1);
			semiSorted.insert(semiSorted.end(), mixed.begin() + idx_l - pow(2, level) + 1, mixed.begin() + idx_l + 1);
		}
		idx_l += pow(2, level + 1);
		idx_r += pow(2, level + 1);
	}
	semiSorted.insert(semiSorted.end(), mixed.begin() + idx_r - pow(2, level + 1) + 1, mixed.end());
	return (semiSorted);
}
void	mergeInMain(std::deque<int> &main, std::deque<int> &predecessors, unsigned int level)
{
	std::cout << "step 5.1" << std::endl;
	(void)level;
	printDeque(insertionOrder);
	size_t i = 0;
	while (i < insertionOrder.size())
	{
		std::cout << "insertionOrder[i] - 1 = " << insertionOrder[i] - 1 << std::endl;
		if (predecessors.size() < insertionOrder[i])
		{
			++i;
			continue ;
		}
		std::cout << "inserting " << predecessors[insertionOrder[i] - 1] << std::endl;
		std::cout << "comming from index " << insertionOrder[i] - 1 << " corresponding to insertionOrder : " << insertionOrder[i] << std::endl;
		insertIntoMain(main, predecessors[insertionOrder[i] - 1], insertionOrder[i] - 1 + i);

		std::cout << "========== MAIN IS after insert of " << predecessors[insertionOrder[i] - 1] << "==========" << std::endl;
		printDeque(main);
		std::cout << "========== END BLOCK ==========" << std::endl;
		++i;
	}
}

void	insertIntoMain(std::deque<int> &main, int n, int indx)
{
	int							range;
	std::deque<int>::iterator	it = main.begin();

	range = std::min((indx + 1) / 2, static_cast<int>(main.size() - 1));
	indx = indx / 2;
	while (range)
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
