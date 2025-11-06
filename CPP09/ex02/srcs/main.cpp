/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:26:21 by vviterbo          #+#    #+#             */
/*   Updated: 2025/11/06 17:33:33 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include "FordJohnson.hpp"

std::deque<size_t> insertionOrder;

int main(int argc, char *argv[])
{
	std::deque<int>		vals;
	std::deque<int>		main(0, 0);

	if (!parseInput(vals, argc, argv))
		return (1);
	std::cout << "Before: ";
    printDeque(vals);
	insertionOrder = getInsertionOrder(vals.size());
	main.resize(0);
	recursiveMergeInsert(main, vals, 0);
	std::cout << "After: ";
	printDeque(main);
	return (0);
}
