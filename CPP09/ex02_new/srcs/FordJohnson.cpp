/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FordJohnson.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:02:46 by vviterbo          #+#    #+#             */
/*   Updated: 2025/08/31 17:16:37 by victorviter      ###   ########.fr       */
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
	while (i + 1 < mixed.size())
	{
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
	else if (!main.size())
	{
		main.push_back(highVals[0] < highVals[1] ? highVals[0] : highVals[1]);
		main.push_back(highVals[0] < highVals[1] ? highVals[1] : highVals[0]);
	}
	std::cout << "main step 2" << std::endl;
	printDeque(main);
	std::cout << "highVals step 2" << std::endl;
	printDeque(highVals);
	std::cout << "predecessors step 2" << std::endl;
	printPairing(predecessors);


	
	mergeInMain(main, highVals, predecessors);

	
	std::cout << "main step 3" << std::endl;
	printDeque(main);
	return (main);
}

void	mergeInMain(std::deque<int> &main, std::deque<int> highVals, std::map<int, int> predecessors)
{
	main.push_front(predecessors[highVals[0]]);
	std::cout << "main step inserted elem 0 of secondary chain" << std::endl;
	printDeque(main);
	for (size_t i = 1; i < 2 * highVals.size(); ++i)
	{
		if (insertionOrder[i] > highVals.size())
			continue ;
		std::cout << "Working on i " << i << " at position " << insertionOrder[i] << std::endl;
		std::cout << "Going to insert predecessor of " << main[insertionOrder[i]] << " i.e " << predecessors[main[insertionOrder[i]]] << std::endl;
		insertIntoMain(main, predecessors[main[insertionOrder[i]]], insertionOrder[i] + i);
	}
}

void	insertIntoMain(std::deque<int> &main, int n, int indx)
{
	int							range;
	std::deque<int>::iterator	it = main.begin();

	range = (indx + 1) / 2;
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