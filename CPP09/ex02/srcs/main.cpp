/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:26:21 by vviterbo          #+#    #+#             */
/*   Updated: 2025/08/20 16:34:40 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.hpp"
#include "FordJohnson.hpp"

int main(int argc, char *argv[])
{
	std::deque<int>		vals;
	std::list<intpair>	initial;
	int					newval;
	std::deque<int>		jacobsthal;

	while (argc - 1)
	{
		newval = atoi(argv[argc - 1]);
		if (!newval && is_non_zero(argv[argc - 1]))
		{
			std::cout << "Error: parsing of input failed on " << argv[argc - 1] << std::endl;
			return (1);
		}
		if (std::find(vals.begin(), vals.end(), newval) != vals.end())
		{
			std::cout << "Error: value appears more than once in the input " << newval << std::endl;
			return (1);
		}
		vals.push_back(newval);
		--argc;
	}
	for (std::deque<int>::iterator it = vals.begin(); it != vals.end(); ++it)
		std::cout << "num = " << *it << std::endl;
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