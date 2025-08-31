/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:26:21 by vviterbo          #+#    #+#             */
/*   Updated: 2025/08/31 10:56:50 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include "FordJohnson.hpp"

int main(int argc, char *argv[])
{
	std::deque<int>		vals;
	int					newval;
	std::deque<int>		jacobsthal;

	for (int i = 1; i < argc; i++)
	{
		newval = atoi(argv[i]);
		if (!newval && is_non_zero(argv[i]))
		{
			std::cout << "Error: parsing of input failed on " << argv[i] << std::endl;
			return (1);
		}
		if (std::find(vals.begin(), vals.end(), newval) != vals.end())
		{
			std::cout << "Error: value appears more than once in the input " << newval << std::endl;
			return (1);
		}
		vals.push_back(newval);
	}
	std::cout << "\n" << std::endl;
	generate_Jacobsthal(vals.size(), jacobsthal);
	initial_split(vals, initial);

	
	vals = recursive_merge_insert(initial);
	while (vals.size())
	{
		std::cout << vals.back() << std::endl;
		vals.pop_back();
	}
}