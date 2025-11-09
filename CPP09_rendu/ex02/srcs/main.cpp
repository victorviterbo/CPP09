/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:26:21 by vviterbo          #+#    #+#             */
/*   Updated: 2025/11/09 14:02:37 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include "FordJohnson.hpp"
// #include "utils_vec.hpp"
// #include "FordJohnson_vec.hpp"
#include <ctime>


std::deque<int>		insertionOrder_d;
std::vector<int>	insertionOrder_v;

int main(int argc, char *argv[])
{
	double					runtime;
	std::clock_t			start;

	/* =========   DEQUE   =========*/
	start = std::clock();

	std::deque<int>			vals_d;
	std::deque<int>			main_d(0, 0);
	if (!parseInput(vals_d, argc, argv))
		return (1);
	
	std::cout << "Before: ";
	printDeque(vals_d, 10);
	
	getInsertionOrder(insertionOrder_d, vals_d.size());
	main_d.resize(0);

	recursiveMergeInsert(main_d, vals_d, 0);
	runtime = double(std::clock() - start) / CLOCKS_PER_SEC;
	std::cout << "After: ";
	printDeque(main_d, 10);
	std::cout << "Time to process a range of " << vals_d.size() << " with std::deque  : " << runtime << std::endl;
	checkSort(main_d);

	/* =========   VECTOR   =========*/
	std::vector<int>		vals_v;
	std::vector<int>		main_v(0, 0);

	start = std::clock();

	if (!parseInput(vals_v, argc, argv))
		return (1);
	
	getInsertionOrder(insertionOrder_v, vals_v.size());
	main_v.resize(0);

	recursiveMergeInsert(main_v, vals_v, 0);
	runtime = double(std::clock() - start) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << vals_v.size() << " with std::vector : " << runtime << std::endl;
	checkSort(main_v);
	return (0);
}
