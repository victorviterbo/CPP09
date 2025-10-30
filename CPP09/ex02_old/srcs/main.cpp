/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:26:21 by vviterbo          #+#    #+#             */
/*   Updated: 2025/09/10 18:20:29 by victorviter      ###   ########.fr       */
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
	std::cout << "Before: ";
        for (std::deque<int>::iterator it = vals.begin(); it != vals.end(); ++it)
		std::cout << *it << " ";
	insertionOrder = getInsertionOrder(vals.size());
	getInsertionOrder(vals.size());
	vals = recursiveMergeInsert(vals);
	std::cout << "After: ";
	for (std::deque<int>::iterator it = vals.begin(); it != vals.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}