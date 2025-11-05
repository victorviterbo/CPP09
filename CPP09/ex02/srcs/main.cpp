/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:26:21 by vviterbo          #+#    #+#             */
/*   Updated: 2025/11/05 14:33:07 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include "FordJohnson.hpp"

std::deque<size_t> insertionOrder;

int main(int argc, char *argv[])
{
	std::deque<int>		vals;
	std::deque<int>		main;

	if (!parseInput(vals, argc, argv))
		return (1);
	std::cout << "Before: ";
    for (std::deque<int>::iterator it = vals.begin(); it != vals.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	insertionOrder = getInsertionOrder(vals.size());
	std::cout << "insertionOrder = " << std::endl;
	printDeque(insertionOrder);
	getInsertionOrder(vals.size());
	vals = recursiveMergeInsert(main, vals, 0);
	std::cout << "After: ";
	for (std::deque<int>::iterator it = vals.begin(); it != vals.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}
