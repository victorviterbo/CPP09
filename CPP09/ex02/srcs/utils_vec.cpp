/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_vec.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:32:10 by vviterbo          #+#    #+#             */
/*   Updated: 2025/11/06 18:11:29 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_vec.hpp"

void	printVector(std::vector<int> d)
{
	for (std::vector<int>::iterator it = d.begin(); it != d.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void	printVector(std::vector<size_t> d)
{
	for (std::vector<size_t>::iterator it = d.begin(); it != d.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}
