/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_deque.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:32:10 by vviterbo          #+#    #+#             */
/*   Updated: 2025/11/08 11:43:57 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_deque.hpp"

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
		if (std::find(vals.begin(), vals.end(), newval) != vals.end())
		{
			std::cout << "Error: value appears more than once in the input " << newval << std::endl;
			return (false);
		}
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

	while (J2 <= listSize)
	{
		for (int i = J2; i > J1; --i)
			indexOrder.push_back(i);
		tmp = J2;
		J2 = J2 + 2 * J1;
		J1 = tmp;
	}
	for (int i = listSize; i > J1; --i)
		indexOrder.push_back(i);
	indexOrder.push_front(1);
	return (indexOrder);
}

void	printDeque(std::deque<int> d, size_t n)
{
	if (n >= d.size())
	{
		for (std::deque<int>::iterator it = d.begin(); it != d.end(); ++it)
			std::cout << *it << " ";
		
		std::cout << std::endl;
		return ;
	}
	for (unsigned int i = 0; i < n / 2; ++i)
		std::cout << d[i] << " ";
	std::cout << "[...] ";
	for (unsigned int i = d.size() - n / 2; i < d.size(); ++i)
		std::cout << d[i] << " ";
	std::cout << std::endl;
}

void	printDeque(std::deque<size_t> d, size_t n)
{
	if (n >= d.size())
	{
		for (std::deque<size_t>::iterator it = d.begin(); it != d.end(); ++it)
			std::cout << *it << " ";
		
		std::cout << std::endl;
		return ;
	}
	for (unsigned int i = 0; i < n / 2; ++i)
		std::cout << d[i] << " ";
	std::cout << "[...] ";
	for (unsigned int i = d.size() - n / 2; i < d.size(); ++i)
		std::cout << d[i] << " ";
	std::cout << std::endl;
}

void	checkSort(std::deque<int> d)
{
	for (unsigned int i = 0; i < d.size() - 1; ++i)
	{
		if (d[i] >= d[i+1])
		{
			std::cout << "ERROR : deque not sorted" << std::endl;
			exit(1) ;
		}
	}
}