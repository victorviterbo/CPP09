/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:26:21 by vviterbo          #+#    #+#             */
/*   Updated: 2025/08/31 15:26:24 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include "FordJohnson.hpp"

std::deque<int> insertionOrder;

int main(int argc, char *argv[])
{
	std::deque<int>		vals;

	if (!parseInput(vals, argc, argv))
		return (1);
	insertionOrder = getInsertionOrder(vals.size());
	getInsertionOrder(vals.size());
	recursiveMergeInsert(vals);
	while (vals.size())
	{
		std::cout << vals.back() << std::endl;
		vals.pop_back();
	}
}