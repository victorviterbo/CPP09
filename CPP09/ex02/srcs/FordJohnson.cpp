/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FordJohnson.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:02:46 by vviterbo          #+#    #+#             */
/*   Updated: 2025/11/04 18:31:04 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FordJohnson.hpp"

std::deque<int>	recursiveMergeInsert(std::deque<int> mixed, unsigned int level)
{
	std::deque<int>			main;
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
	if (pow(2, level + 1) <= mixed.size())
	{
		main = recursiveMergeInsert(semiSorted, level + 1);
		mergeInMain(main, semiSorted, level - 1);
	}
	else
	{
		std::cout << "FINAL SEMISORTED" << std::endl;
		printDeque(semiSorted);
		std::cout << "FINISH SEMISORTED" << std::endl;
		main.resize(0);
		main.push_front(semiSorted[pow(2, level) - 1]);
		if (semiSorted[pow(2, level - 1) - 1])
			main.push_front(semiSorted[pow(2, level - 1) - 1]);
	}
	return (main);
}

void	mergeInMain(std::deque<int> &main, std::deque<int> &semiSorted, unsigned int level)
{
	std::cout << "step 5.1" << std::endl;
	printDeque(insertionOrder);
	int i = insertionOrder.size() - 1;
	while (i >= 0)
	{
		std::cout << "OK 2 " << i << std::endl;
		if ((insertionOrder[i] - 1) * pow(2, level) >= semiSorted.size())
		{
			--i;
			continue ;
		}
		std::cout << "level " << level << std::endl;
		std::cout << "i " << i << std::endl;
		std::cout << "inserting " << semiSorted[(insertionOrder[i] - 1) * pow(2, level)] << std::endl;
		std::cout << "comming from index " << (insertionOrder[i] - 1) * pow(2, level) << std::endl;
		insertIntoMain(main, semiSorted[(insertionOrder[i] - 1) * pow(2, level)], insertionOrder[i] + i);
		std::cout << "OK" << std::endl;
		--i;
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
