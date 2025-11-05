/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:32:10 by vviterbo          #+#    #+#             */
/*   Updated: 2025/11/04 17:18:13 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

bool	parseInput(std::deque<int> &vals, int argc, char *argv[])
{
	int	newval;

	for (int i = 1; i < argc; i++)
	{
		newval = atoi(argv[i]);
		if (!newval && isNonZero(argv[i]))
		{
			std::cout << "Error: parsing of input failed on " << argv[i] << std::endl;
			return (false);
		}
		/*if (std::find(vals.begin(), vals.end(), newval) != vals.end())
		{
			std::cout << "Error: value appears more than once in the input " << newval << std::endl;
			return (false);
		}*/
		vals.push_back(newval);
	}
	return (true);
}

bool	isNonZero(std::string s)
{
	if (s[0] != '0' && s[0] != '-')
		return (true);
	for (unsigned int i = 1; i < s.length(); ++i)
	{
		if (s[i] != '0')
			return (true);
	}
	return (false);
}

std::deque<size_t>	getInsertionOrder(int listSize)
{
	int					J1 = 1;
	int 				J2 = 3;
	int					tmp;
	std::deque<size_t>	indexOrder;	

	while (J2 < listSize)
	{
		for (int i = J2; i > J1; --i)
			indexOrder.push_back(i);
		tmp = J2;
		J2 = J2 + 2 * J1;
		J1 = tmp;
	}
	for (int i = listSize; i > J1; --i)
		indexOrder.push_back(i);
	return (indexOrder);
}

void	printList(std::list<int> l)
{
	for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it)
		std::cout << (*it) << std::endl;
	std::cout << std::endl;
}

void	printDeque(std::deque<int> d)
{
	for (std::deque<int>::iterator it = d.begin(); it != d.end(); ++it)
		std::cout << *it << "\n";
	std::cout << std::endl;
}

void	printDeque(std::deque<size_t> d)
{
	for (std::deque<size_t>::iterator it = d.begin(); it != d.end(); ++it)
		std::cout << *it << "\n";
	std::cout << std::endl;
}

void	printPairing(std::map<int, int> pairing)
{
	for (std::map<int, int>::iterator it = pairing.begin(); it != pairing.end(); ++it)
		std::cout << "big = " << it->first << ", small = " << it->second << "\n";
	std::cout << std::endl;
}