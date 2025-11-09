/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:32:10 by vviterbo          #+#    #+#             */
/*   Updated: 2025/11/09 14:03:15 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

template < typename T>
bool	parseInput(T &vals, int argc, char *argv[])
{
	int	newval;

	for (int i = 1; i < argc; i++)
	{
		newval = atoi(argv[i]);
		if (!newval && isNonZero(argv[i]))
		{
			std::cout << "KO: parsing of input failed on " << argv[i] << std::endl;
			return (false);
		}
		if (std::find(vals.begin(), vals.end(), newval) != vals.end())
		{
			std::cout << "KO: value appears more than once in the input " << newval << std::endl;
			return (false);
		}
		vals.push_back(newval);
	}
	return (vals.size());
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

template < typename T>
void	getInsertionOrder(T &indexOrder, int listSize)
{
	int		J1 = 1;
	int 	J2 = 3;
	int		tmp;

	indexOrder.push_back(1);
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
	//indexOrder.insert(indexOrder.begin(), 1);
}

template < typename T>
void	printDeque(T d, size_t n)
{
	if (n >= d.size())
	{
		for (typename T::iterator it = d.begin(); it != d.end(); ++it)
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

template < typename T>
void	checkSort(T d)
{
	for (unsigned int i = 0; i < d.size() - 1; ++i)
	{
		if (d[i] >= d[i+1])
		{
			std::cout << "KO : list not sorted : " << d[i] << " before " << d[i+1] << std::endl;
			exit(1) ;
		}
	}
}