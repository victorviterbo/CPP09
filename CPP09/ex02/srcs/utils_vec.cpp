/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_vec.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:32:10 by vviterbo          #+#    #+#             */
/*   Updated: 2025/11/08 10:55:29 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_vec.hpp"


void	printVector(std::vector<int> v, size_t n)
{
	if (n >= v.size())
	{
		for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
			std::cout << *it << " ";
		
		std::cout << std::endl;
		return ;
	}
	for (unsigned int i = 0; i < n / 2; ++i)
		std::cout << v[i] << " ";
	std::cout << "[...] ";
	for (unsigned int i = v.size() - n / 2; i < v.size(); ++i)
		std::cout << v[i] << " ";
	std::cout << std::endl;
}

void	printVector(std::vector<size_t> v, size_t n)
{
	if (n >= v.size())
	{
		for (std::vector<size_t>::iterator it = v.begin(); it != v.end(); ++it)
			std::cout << *it << " ";
		
		std::cout << std::endl;
		return ;
	}
	for (unsigned int i = 0; i < n / 2; ++i)
		std::cout << v[i] << " ";
	std::cout << "[...] ";
	for (unsigned int i = v.size() - n / 2; i < v.size(); ++i)
		std::cout << v[i] << " ";
	std::cout << std::endl;
}
