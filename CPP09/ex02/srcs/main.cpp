/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:26:21 by vviterbo          #+#    #+#             */
/*   Updated: 2025/08/19 16:02:08 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.hpp"
#include "FordJohnson.hpp"

int main(int argc, char *argv[])
{
	std::deque<int>		vals;
	std::list<intpair>	main;
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
		if (std::find(vals.begin(), vals.end(), newval)  != vals.end())
		{
			std::cout << "Error: value appears more than once in the input" << argv[argc - 1] << std::endl;
			return (1);
		}
		vals.push_back(newval);
	}
	generate_Jacobsthal(vals.size(), jacobsthal);
	initial_split(vals, main);
	
}