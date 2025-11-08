/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:26:21 by vviterbo          #+#    #+#             */
/*   Updated: 2025/11/08 11:55:35 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_deque.hpp"
#include "FordJohnson_deque.hpp"
#include "utils_vec.hpp"
#include "FordJohnson_vec.hpp"
#include <ctime>

std::deque<size_t> insertionOrder_d;
std::vector<size_t> insertionOrder_v;

int main(int argc, char *argv[])
{
	std::deque<int>		vals_d;
	std::deque<int>		main_d(0, 0);
	std::vector<int>	vals_v;
	std::vector<int>	main_v(0, 0);
	double				runtime;

	if (!parseInput(vals_d, argc, argv))
		return (1);

	vals_v.assign(vals_d.begin(), vals_d.end());
	
	std::cout << "Before: ";
    printDeque(vals_d, 10);
	
	insertionOrder_d = getInsertionOrder(vals_d.size());
	insertionOrder_v.assign(insertionOrder_d.begin(), insertionOrder_d.end());
	main_d.resize(0);
	main_v.resize(0);

    std::clock_t start = std::clock();
	recursiveMergeInsert(main_d, vals_d, 0);
	runtime = double(std::clock() - start) / CLOCKS_PER_SEC;
	std::cout << "After: ";
	printDeque(main_d, 10);
	std::cout << "Time to process a range of " << vals_d.size() << " with std::deque  : " << runtime << std::endl;
	//return (0);
	start = std::clock();
	recursiveMergeInsert(main_v, vals_v, 0);
	runtime = double(std::clock() - start) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << vals_v.size() << " with std::vector : " << runtime << std::endl;
	checkSort(main_d);
	checkSort(main_v);
	return (0);
}
