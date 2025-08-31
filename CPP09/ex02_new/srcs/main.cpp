/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:26:21 by vviterbo          #+#    #+#             */
/*   Updated: 2025/08/31 16:59:27 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include "FordJohnson.hpp"

std::deque<size_t> insertionOrder;

int main(int argc, char *argv[])
{
	std::deque<int>		vals;

	if (!parseInput(vals, argc, argv))
		return (1);
	insertionOrder = getInsertionOrder(vals.size());
	std::cout << "insertion order is " << std::endl;
	printDeque(insertionOrder);
	getInsertionOrder(vals.size());
	vals = recursiveMergeInsert(vals);
	while (vals.size())
	{
		std::cout << vals.back() << std::endl;
		vals.pop_back();
	}
}