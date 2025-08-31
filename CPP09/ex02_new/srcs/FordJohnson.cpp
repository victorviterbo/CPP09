/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FordJohnson.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:02:46 by vviterbo          #+#    #+#             */
/*   Updated: 2025/08/31 20:19:02 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FordJohnson.hpp"

std::deque<int>	recursiveMergeInsert(std::deque<int> mixed)
{
	std::deque<int>		main;
	std::deque<int>		highVals;
	std::map<int, int>	predecessors;
	size_t				i = 0;

	std::cout << "Mixed step 0" << std::endl;
	printDeque(mixed);
	while (i < mixed.size())
	{
		if (i + 1 == mixed.size())
			predecessors[-1] = mixed[i];
		else if (mixed[i] > mixed[i + 1])
		{
			highVals.push_back(mixed[i]);
			predecessors[mixed[i]] = mixed[i + 1];
		}
		else
		{
			highVals.push_back(mixed[i + 1]);
			predecessors[mixed[i + 1]] = mixed[i];
		}
		i += 2;
	}
	std::cout << "highVals step 1" << std::endl;
	printDeque(highVals);
	std::cout << "predecessors step 1" << std::endl;
	printPairing(predecessors);


	
	if (highVals.size() > 2)
		main = recursiveMergeInsert(highVals);
	else if (highVals.size() > 1)
	{
		main.push_back(highVals[0] < highVals[1] ? highVals[0] : highVals[1]);
		main.push_back(highVals[0] < highVals[1] ? highVals[1] : highVals[0]);
	}
	else
		main.push_back(highVals[0]);
	std::cout << "main step 2" << std::endl;
	printDeque(main);
	std::cout << "highVals step 2" << std::endl;
	printDeque(highVals);
	std::cout << "predecessors step 2" << std::endl;
	printPairing(predecessors);


	
	mergeInMain(main, predecessors);

	
	std::cout << "main step 3" << std::endl;
	printDeque(main);
	return (main);
}

void	mergeInMain(std::deque<int> &main, std::map<int, int> predecessors)
{
	std::deque<int>	reorderedLowVals;

	printDeque(main);
	for (std::deque<int>::iterator it = main.begin(); it != main.end(); ++it)
	{
		std::cout << "I see " << *it << " and I append its predecessor " << predecessors[*it] << std::endl;
		reorderedLowVals.push_back(predecessors[*it]);
	}
	if (predecessors.find(-1) != predecessors.end())
		reorderedLowVals.push_back(predecessors[-1]);
	std::cout << "Reordered predecessors" << std::endl;
	printDeque(reorderedLowVals);
	main.push_front(predecessors[main[0]]);
	std::cout << "main step inserted elem 0 of secondary chain" << std::endl;
	printDeque(main);
	for (size_t i = 0; i < std::min(2 * reorderedLowVals.size(), insertionOrder.size()); ++i)
	{
		if (insertionOrder[i] > reorderedLowVals.size())
			continue ;
		std::cout << "Going to insert\ninsertIndex = " << insertionOrder[i] << "\ncorresponding main = " << main[insertionOrder[i]] << "\npredecessor = " << reorderedLowVals[insertionOrder[i] - 1] << std::endl;
		insertIntoMain(main, reorderedLowVals[insertionOrder[i] - 1], insertionOrder[i] + i);
	}
}

void	insertIntoMain(std::deque<int> &main, int n, int indx)
{
	int							range;
	std::deque<int>::iterator	it = main.begin();

	range = std::min((indx + 1) / 2, static_cast<int>(main.size() - 1));
	indx = indx / 2;
	std::cout << "Inserting element " << n << " starting comparison at pos " << indx << std::endl;
	std::cout << "First comparison will be with " << main[indx] << std::endl;
	std::cout << "Starting with a range of " << range << std::endl;
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
	std::cout << "Main after insertion is now " << std::endl;
	printDeque(main);
	return ;
}
