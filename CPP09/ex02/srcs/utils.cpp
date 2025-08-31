/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:32:10 by vviterbo          #+#    #+#             */
/*   Updated: 2025/08/30 18:39:21 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

bool	is_non_zero(std::string s)
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

void	print_list(std::list<intpair> l)
{
	for (std::list<intpair>::iterator it = l.begin(); it != l.end(); ++it)
		std::cout << (*it).small << ", " << (*it).big << std::endl;
	std::cout << std::endl;
}

void	print_list(std::list<int> l)
{
	for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it)
		std::cout << (*it) << std::endl;
	std::cout << std::endl;
}

void	print_deque(std::deque<int> d)
{
	for (std::deque<int>::iterator it = d.begin(); it != d.end(); ++it)
		std::cout << *it << "\n";
	std::cout << std::endl;
}

void	print_pairing(std::map<int, std::list<intpair>::iterator> pairing)
{
	for (std::map<int, std::list<intpair>::iterator>::iterator it = pairing.begin(); it != pairing.end(); ++it)
		std::cout << "first = " << it->first << "big = " << (*it->second).big << "small = " << (*it->second).small << "\n";
	std::cout << std::endl;
}